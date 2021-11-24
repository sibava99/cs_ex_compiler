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
int read_flag = 0;
int write_flag = 0;
int arg_flag = 0;
unsigned arity = 0;
int i = 0;
char arg_name [10][64]; /* 引数名保存用配列 */
Scope flag = GLOBAL_VAR;
FILE *fp; 
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
	{
		printf("program is inputted.\n");
		if((fp = fopen("result.ll","w")) == NULL){
		fprintf(stderr,"ファイルのオープンに失敗\n");
		exit(1);	
		}
	}
	IDENT
	{	
		flag = GLOBAL_VAR;
		init_fstack();
		init_brstack();
		init_lstack();  
 
    }
	
	SEMICOLON outblock PERIOD
	{
		if((read_flag || write_flag) == 1){
			fprintf(fp,"@.str = private unnamed_addr constant [3 x i8] c\"%%d\\00\", align 1\n\n");
		} /* readまたはwriteが使用されたときに宣言 */
		displayLlvmfundecl(declhd);
		if(read_flag == 1){
			fprintf(fp,"declare dso_local i32 @__isoc99_scanf(i8*, ...) #1\n");
		}	/* read仕様時 */
		if(write_flag == 1){
			fprintf(fp,"declare dso_local i32 @printf(i8*, ...) #1\n");
		}/* write仕様時 */
	}
	;

outblock
	: var_decl_part subprog_decl_part
	{
		generate_decl("main",I32,0);
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
		delete();
		flag = GLOBAL_VAR;
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
	: VAR{flag = GLOBAL_VAR;} id_list
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
	: {flag = LOCAL_VAR;}proc_decl
	;
proc_decl
	:PROCEDURE IDENT 
	{
		flag = LOCAL_VAR;
		insert($2,PROC_NAME);
		generate_decl($2,VOID,0);	
	}
	SEMICOLON inblock
	{
		Factor r;
		r.type = LOCAL_VAR;
		strcpy(r.vname,"void");
		r.val = 0;
		factorpush(r);
		generate_code(Ret);
	}

	|PROCEDURE IDENT LPAREN 
	{
		insert($2,PROC_NAME);
		arg_flag = 1;
	} 
	id_list RPAREN SEMICOLON 
	{
		generate_decl($2,VOID,arity);
		struct symboltable *st = lookup($2);
		(st->num) = arity;
		arg_flag = 0;
		cntr = cntr + arity;
		for(i = 0; i < arity; i++){
			/* alloca文を生成し引数の記号表のレジスタ番号を正しい値に変更する */
			struct symboltable *st = lookup(arg_name[i]);
			(st->num) = cntr;
			generate_code(Alloca);
		}
		for(i = 0;i < arity; i++){
			Factor f1,f2;
			f1.type = LOCAL_VAR;
			f2.type = LOCAL_VAR;
			f1.val = i;
			f2.val = i + 1 + arity;
			factorpush(f1);
			factorpush(f2);
			generate_code(Store);
		}
		arity = 0;
	}
	inblock	
	{
		Factor r;
		r.type = LOCAL_VAR;
		strcpy(r.vname,"void");
		r.val = 0;
		factorpush(r);
		generate_code(Ret);
		delete();
		flag = GLOBAL_VAR;
	}


	|FUNCTION IDENT 
	{
		insert($2,FUNC_NAME);
		insert($2,LOCAL_VAR); /* 返り値を記号表に追加 */
		generate_decl($2,I32,0);
		generate_code(Alloca); /* 返り値用レジスタ */
	}
	SEMICOLON inblock
	{	
		factorgenerate($2);
		generate_code(Load);
		generate_code(Ret);
		delete();
		flag = GLOBAL_VAR;
	}

	|FUNCTION IDENT
	{
		insert($2,FUNC_NAME);
		arg_flag = 1;
	}
	LPAREN id_list RPAREN SEMICOLON 
	{
		generate_decl($2,I32,arity);
        
		struct symboltable *st = lookup($2);
		(st->num) = arity;
		arg_flag = 0;
		cntr = cntr + arity;
		insert($2,LOCAL_VAR); /* 返り値を記号表に追加 */
		generate_code(Alloca); /* 返り値用レジスタ */
		for(i = 0; i < arity; i++){
			/* alloca文を生成し引数の記号表のレジスタ番号を正しい値に変更する */
			struct symboltable *st = lookup(arg_name[i]);
			(st->num) = cntr;
			generate_code(Alloca);
		}
		for(i = 0;i < arity; i++){
			Factor f1,f2;
			f1.type = LOCAL_VAR;
			f2.type = LOCAL_VAR;
			f1.val = i;
			f2.val = i + 2 + arity;
			factorpush(f1);
			factorpush(f2);
			generate_code(Store);
		}
		arity = 0;
	}
	inblock
	{
		factorgenerate($2);
		generate_code(Load);
		generate_code(Ret);
		delete();
		flag = GLOBAL_VAR;
	}
	;

	
/* proc_name
	: IDENT
	{
	  flag = LOCAL_VAR;
	  insert($1,PROC_NAME);
	  generate_decl($1,VOID,0);
	} 
	; */
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
		generate_code(BrUncond);/* 即確定 */
		brpop();
		generate_code(Label);
		factorgenerate($2);
		generate_code(Load);
	}
		
	TO expression
	{
		// 継続判定

		generate_icmp(SLT);
		generate_code(BrCond);/* arg2確定,arg3未確定*/
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
		(tmp->args).brcond.arg3 = labelpop();/* arg3確定 */
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
		Factor args[10];
		generate_call(f,VOID,args); /* 引数、返り値なしの手続き  */
	}
	| IDENT LPAREN arg_list RPAREN
	{
		factorgenerate($1);
		Factor f = factorpop();
		Factor args[10];
		for(i = 0;i < f.val;i++){
			args[i] = factorpop();
		}
		generate_call(f,VOID,args);
	}
	;

func_call_statement
	: func_call_name
	;
func_call_name
	: IDENT LPAREN arg_list RPAREN
	{
		struct symboltable *p = type_lookup($1,FUNC_NAME);
		Factor f;
		f.type = FUNC_NAME;
		strcpy(f.vname,p->name);
		f.val = p->num;
		Factor args[10];
		for(i = f.val-1; i>=0 ;i--){
			args[i] = factorpop();
		}
		generate_call(f,I32,args);
	}
	;
block_statement
	:SBEGIN statement_list SEND
	;
read_statement 
	: READ LPAREN IDENT
	{	
		factorgenerate($3);
		Factor arg = factorpop();
		Factor args[10] = {arg};
		Factor f ={PROC_NAME,"read",1}; /* read関数は記号表にないため生成 */
		generate_call(f,I32,args);
		read_flag = 1;
	} 
	RPAREN 
	;
write_statement
	: WRITE LPAREN expression 
	{
		Factor arg = factorpop();
		Factor args[10] = {arg};
		Factor f ={PROC_NAME,"write",1}; /* write関数は記号表にないため生成 */
		generate_call(f,I32,args);
		write_flag = 1;
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
	| func_call_statement
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
		fprintf(fp,"@%s = common global i32 0, align 4\n",$1);
	  }
	  else if(arg_flag == 1){
		  strcpy(arg_name[arity],$1);
		  arity++;
	  }
	  else{/*ローカル変数宣言*/
	    generate_code(Alloca);
	  }
	}
	| id_list COMMA IDENT
	  {
	    insert($3,flag);
	    if(flag == GLOBAL_VAR){ /*グローバル変数宣言*/
		  fprintf(fp,"@%s = common global i32 0, align 4\n",$3);
	    }
		else if(arg_flag == 1){
			strcpy(arg_name[arity],$3);
			arity++;
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
