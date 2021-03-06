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
	}
	SEMICOLON outblock PERIOD
	{displayLlvmfundecl(declhd);}
	;

outblock
	: var_decl_part subprog_decl_part {generate_decl("main");}
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
        :PROCEDURE proc_name SEMICOLON inblock
	;
proc_name
        : IDENT
	{
	  flag = LOCAL_VAR;
	  insert($1,PROC_NAME);
	  generate_decl($1);
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
	  struct symboltable *st;
	  st = lookup($1);
	  if( st == NULL){
	    printf("未定義の変数です\n");
	    exit(1);
	  }	

	  Factor tmp;
	  strcpy(tmp.vname,$1);
	  tmp.type = st->type;
	  tmp.val = st->num;
	  factorpush(tmp);	    
	  generate_code(Store);
	}
	;
if_statement 
	: IF condition THEN statement else_statement
	;
else_statement
	: ELSE statement
	| /*empty*/
	;
while_statement 
	: WHILE condition DO statement
	;
for_statement
	: FOR IDENT{lookup($2);} ASSIGN expression TO expression DO statement
	;
proc_call_statement
	: proc_call_name
	;
proc_call_name
	: IDENT{lookup($1);}
	;
block_statement
        :SBEGIN statement_list SEND{delete();flag = GLOBAL_VAR;}
	;
read_statement 
	: READ LPAREN IDENT{lookup($3);} RPAREN 
	;
write_statement
	: WRITE LPAREN expression RPAREN
	;
null_statement
	: /*empty*/
	;
condition
	: expression EQ expression
	| expression NEQ expression
	| expression LT expression
	| expression LE expression
	| expression GT expression
	| expression GE expression
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
	  struct symboltable *st;
	  st = lookup($1);
	  if( st == NULL){
	    printf("未定義の変数です\n");
	    exit(1);
	  }	
	  
	  Factor tmp;
	  strcpy(tmp.vname,$1);
	  tmp.type = st->type;
	  tmp.val = st->num;
	  factorpush(tmp);
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
