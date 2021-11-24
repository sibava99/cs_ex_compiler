%{
/*
 * parser; Parser for PL-*
 */

#define MAXLENGTH 16

#include <stdio.h>
#include "symtab.h"
#include "llvmcommands.h"  

int yyparse();
int yyerror(char *);
extern int yylineno;
extern char *yytext;
extern LLVMcode *codehd;
extern LLVMcode *codetl;
extern Fundecl *declhd;
extern Fundecl *decltl;
extern int cntr;

Scope flag = GLOBAL_VAR;
 
%}

%union {
    int num;
    char ident[MAXLENGTH+1];
}
%token SBEGIN DO ELSE SEND
%token FOR FORWARD FUNCTION IF PROCEDURE
%token PROGRAM READ THEN TO VAR
%token WHILE WRITE

%left PLUS MINUS
%left MULT DIV

%token EQ NEQ LE LT GE GT
%token LPAREN RPAREN LBRACKET RBRACKET
%token COMMA SEMICOLON COLON INTERVAL
%token PERIOD ASSIGN
%token <num> NUMBER
%token <ident> IDENT

%%

program
	: PROGRAM 
	{printf("program is inputted.\n");}IDENT
	{
	  flag = GLOBAL_VAR;
	  init_fstack();
	  init_brstack();
	  init_lstack();
	}
	SEMICOLON outblock PERIOD
	{
		printf("@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n\n");
		displayLlvmfundecl(declhd);
		printf("declare dso_local i32 @__isoc99_scanf(i8*, ...) #1\n");
		printf("declare dso_local i32 @printf(i8*, ...) #1\n");
	}

	;

outblock
	: var_decl_part subprog_decl_part
	{
		generate_decl("main",I32);
		Factor tmp;
		tmp.type = CONSTANT;
		tmp.val = 0;
		factorpush(tmp);
		tmp.type = LOCAL_VAR;
		tmp.val = cntr;
		factorpush(tmp);
		generate_code(Alloca);
		generate_code(Store);
	}
	statement
	{
		Factor tmp;
		tmp.type = CONSTANT;
		tmp.val = 0;
		factorpush(tmp);
		generate_code(Ret);
	}
	;

var_decl_part
	: /* empty */
	| var_decl_list SEMICOLON
	;
var_decl_list
	: var_decl
	| var_decl_list SEMICOLON var_decl
	;

var_decl
	: VAR id_list
	;
subprog_decl_part
	: subprog_decl_list SEMICOLON
	| /*empty*/
	;
subprog_decl_list
	: subprog_decl_list SEMICOLON subprog_decl
	| subprog_decl
	;
subprog_decl
	: proc_decl
	;
proc_decl
	:PROCEDURE proc_name SEMICOLON inblock{
		Factor r;
		r.type = LOCAL_VAR;  /* 返り値として存在しないGLOBAL_VAR */
		strcpy(r.vname,"void");
		r.val = 0;
		factorpush(r);
		generate_code(Ret);
	}
	;
proc_name
	: IDENT
	{
	  flag = LOCAL_VAR;
	  insert($1,PROC_NAME);
	  generate_decl($1,VOID);

	} 
	;
inblock
	:var_decl_part statement 
	;
statement_list 
	: statement_list SEMICOLON statement
	| statement
	;
statement
	: assignment_statement
	| if_statement
	| for_statement
	| while_statement
	| proc_call_statement
	| null_statement
	| block_statement
	| read_statement
	| write_statement
	;

assignment_statement
        : IDENT ASSIGN expression
	{	
		factorgenerate($1);
	  	generate_code(Store);
	}
	;
if_statement 
	: IF condition THEN 
	{
		generate_code(BrCond);
		generate_code(Label);
		labelpop();
	}
	statement
	{
		generate_code(BrUncond); /* arg1未確定 */
	}
	 else_statement
	{
		generate_code(Label);
		int label = labelpop();
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = label;
	}
	;
else_statement
	: ELSE
	{
		generate_code(Label);
		int label = labelpop();
		LLVMcode *tmp1 = brpop();
		LLVMcode *tmp2 = brpop();
		brpush(tmp1);
		(tmp2->args).brcond.arg3 = label;
	} 
	statement
	{
		generate_code(BrUncond);
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = cntr;
	}
	| /*empty*/
	{
		LLVMcode *tmp1 = brpop();
		LLVMcode *tmp2 = brpop();
		brpush(tmp1);
		(tmp2->args).brcond.arg3 = cntr;
	}
	;
while_statement 
	: WHILE 
	{
		generate_code(BrUncond); /* 条件文へのbr エラー発生*/
		brpop(); /* br確定のため削除 */
		generate_code(Label); /* 条件文ラベル宣言 */
	}
	condition 
	{
		generate_code(BrCond); /* 条件文brc,未確定  */
		generate_code(Label); /* 処理部(statement)のラベル宣言 */
		labelpop(); /* ラベル削除 */
	}
	DO statement
	{
		generate_code(BrUncond); /* 条件文へのbr,未確定 */
		LLVMcode *tmp1 = brpop();
		(tmp1->args).bruncond.arg1 = labelpop(); /* 条件文へのbr確定 */
		generate_code(Label); /* whileブロック外のラベル */
		LLVMcode *tmp2 = brpop(); 
		(tmp2->args).brcond.arg3 = labelpop(); /* 条件文brc確定 */
	}


	;
for_statement
	: FOR IDENT ASSIGN expression
	{	
		factorgenerate($2);
		generate_code(Store);
		generate_code(BrUncond);
		brpop();
		generate_code(Label);
	}
		
	TO expression
	{
		// 継続判定
		factorgenerate($2);
		generate_code(Load);
		generate_icmp(SLT);
		generate_code(BrCond);
		generate_code(Label); //処理部ラベル
		labelpop();
	} DO statement
	{
		generate_code(BrUncond);
		brpop();
		// インクリメント処理
		generate_code(Label);
		labelpop();
		factorgenerate($2);
		generate_code(Load);
		
		Factor one;
		one.type = CONSTANT;
		one.val = 1;
		factorpush(one);
		generate_code(Add);
		factorgenerate($2);
		generate_code(Store);
		generate_code(BrUncond);
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = labelpop();
		generate_code(Label); //forブロック外へのラベル
		tmp = brpop();
		(tmp->args).brcond.arg3 = labelpop();
	}
	;
proc_call_statement
	: proc_call_name
	;
proc_call_name
	: IDENT
	{
		factorgenerate($1);
		Factor f = factorpop();
		Factor args[5];
		generate_call(f,VOID,args); /* 引数、返り値なしの手続き  */
	}
	| IDENT LPAREN arg_list RPAREN
	;
block_statement
        :SBEGIN statement_list SEND{delete();flag = GLOBAL_VAR;}
	;
read_statement 
	: READ LPAREN IDENT
	{	
		factorgenerate($3);
		Factor arg = factorpop();
		Factor args[5] = {arg};
		Factor f ={PROC_NAME,"read",1}; /* read関数は記号表にないため生成 */
		generate_call(f,I32,args);
	} 
	RPAREN 
	;
write_statement
	: WRITE LPAREN expression 
	{
		Factor arg = factorpop();
		Factor args[5] = {arg};
		Factor f ={PROC_NAME,"write",1}; /* write関数は記号表にないため生成 */
		generate_call(f,I32,args,1);
	}	
	RPAREN
	;
null_statement
	: /*empty*/
	;
condition
	: expression EQ expression {generate_icmp(EQUAL);} 
	| expression NEQ expression {generate_icmp(NE);} 
	| expression LT expression {generate_icmp(SLT);} 
	| expression LE expression {generate_icmp(SLE);}
	| expression GT expression {generate_icmp(SGT);}
	| expression GE expression {generate_icmp(SGE);}
	;

expression
	: term
	| PLUS term
	| MINUS term
	| expression PLUS term
	{
	  generate_code(Add);
	}
	| expression MINUS term
	{	
	  generate_code(Sub);
	}
	;

term
	: factor
	| term MULT factor
	{	
	  generate_code(Mult);
	}
	| term DIV factor
	{
	  generate_code(Div);
	}
	;
factor
	: var_name
	| NUMBER
	{
	  Factor tmp;
	  tmp.type = CONSTANT;
	  tmp.val = $1;
	  factorpush(tmp);
	}
	| LPAREN expression RPAREN
	;
var_name 
	: IDENT
	{
		factorgenerate($1);
		generate_code(Load);	    
	}
        ;
arg_list
	: expression
	| arg_list COMMA expression
	;
id_list 
	: IDENT
	{
	  insert($1,flag);
	  if(flag == GLOBAL_VAR){ /*グローバル変数宣言*/
	    /*Factor tmp;
	    strcpy(tmp.vname,$1);
	    tmp.type = GLOBAL_VAR;
	    factorpush(tmp);
	    generate_code(Global);*/
		printf("@%s = common global i32 0, align 4\n",$1);
	  }
	  else{/*ローカル変数宣言*/
	    generate_code(Alloca);
	  }
	}
	| id_list COMMA IDENT
	  {
	    insert($3,flag);
	    if(flag == GLOBAL_VAR){ /*グローバル変数宣言*/
	      /*Factor tmp;
	      strcpy(tmp.vname,$3);
	      tmp.type = GLOBAL_VAR;
	      factorpush(tmp);
	      generate_code(Global);*/
		  printf("@%s = common global i32 0, align 4\n",$3);
	    }
	    else{/*ローカル変数宣言*/
	      generate_code(Alloca);
	    }
	  }
	;

       

%% 
yyerror(char *s)
{
  fprintf(stderr, "%s in line %d,token %s\n", s,yylineno,yytext);
}
