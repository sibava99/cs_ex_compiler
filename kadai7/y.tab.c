#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
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
#line 31 "parser.y"
#ifdef YYSTYPE
#undef  YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
#endif
#ifndef YYSTYPE_IS_DECLARED
#define YYSTYPE_IS_DECLARED 1
typedef union {
    int num;
    char ident[MAXLENGTH+1];
} YYSTYPE;
#endif /* !YYSTYPE_IS_DECLARED */
#line 59 "y.tab.c"

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define SBEGIN 257
#define DO 258
#define ELSE 259
#define SEND 260
#define FOR 261
#define FORWARD 262
#define FUNCTION 263
#define IF 264
#define PROCEDURE 265
#define PROGRAM 266
#define READ 267
#define THEN 268
#define TO 269
#define VAR 270
#define WHILE 271
#define WRITE 272
#define PLUS 273
#define MINUS 274
#define MULT 275
#define DIV 276
#define EQ 277
#define NEQ 278
#define LE 279
#define LT 280
#define GE 281
#define GT 282
#define LPAREN 283
#define RPAREN 284
#define LBRACKET 285
#define RBRACKET 286
#define COMMA 287
#define SEMICOLON 288
#define COLON 289
#define INTERVAL 290
#define PERIOD 291
#define ASSIGN 292
#define NUMBER 293
#define IDENT 294
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    1,    2,    0,    7,    3,    4,    4,    8,    8,   11,
    9,    5,    5,   12,   12,   15,   13,   16,   14,   18,
   19,   14,   20,   14,   21,   22,   14,   17,   23,   23,
    6,    6,    6,    6,    6,    6,    6,    6,    6,   24,
   35,   37,   25,   38,   36,   36,   39,   40,   27,   41,
   42,   26,   28,   43,   43,   45,   46,   30,   47,   31,
   48,   32,   29,   34,   34,   34,   34,   34,   34,   33,
   33,   33,   33,   33,   49,   49,   49,   50,   50,   50,
   50,   51,   44,   44,   10,   10,
};
static const short yylen[] = {                            2,
    0,    0,    7,    0,    4,    0,    2,    1,    3,    0,
    3,    2,    0,    3,    1,    0,    2,    0,    5,    0,
    0,    9,    0,    5,    0,    0,    9,    2,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    0,    7,    0,    3,    0,    0,    0,    6,    0,
    0,   10,    1,    1,    4,    1,    4,    3,    0,    5,
    0,    5,    0,    3,    3,    3,    3,    3,    3,    1,
    2,    2,    3,    3,    1,    3,    3,    1,    1,    1,
    3,    1,    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    2,    0,    0,   10,    0,    0,    0,
    8,    0,    3,    4,    0,   15,    0,    0,   85,    0,
    0,    0,    0,    0,   17,    9,    0,    0,    0,    0,
    0,   47,    0,    0,    5,   31,   32,   33,   34,   35,
   36,   37,   38,   39,   53,   14,    0,    0,   86,   30,
    0,    0,    0,    0,    0,   80,    0,    0,    0,   79,
   56,    0,   75,   78,    0,    0,    0,    0,    0,    0,
    0,   20,    0,   58,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   41,    0,
    0,   59,   48,    0,    0,    0,    0,    0,    0,    0,
    0,   29,    0,   81,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   76,   77,    0,    0,    0,   55,
    0,    0,   24,    0,    0,   19,    0,   57,   42,   60,
    0,   62,    0,   28,    0,    0,    0,    0,   49,   26,
   21,    0,   44,   43,    0,    0,    0,    0,   27,   22,
    0,   45,   52,
};
static const short yydgoto[] = {                          2,
    3,    5,    8,  122,   14,   35,   21,   10,   11,   20,
   12,   15,   16,   25,   17,   73,  123,  100,  146,   70,
   71,  145,   51,   36,   37,   38,   39,   40,   41,   42,
   43,   44,   58,   59,  114,  144,  138,  148,   66,  118,
  127,  147,   45,   96,   60,   61,  117,  119,   62,   63,
   64,
};
static const short yysindex[] = {                      -246,
    0,    0, -221,    0, -227, -211,    0, -228,    0, -209,
    0, -205,    0,    0, -193,    0, -260, -211,    0, -190,
 -150,    0, -169, -166,    0,    0, -154, -150, -146, -144,
 -182,    0, -120, -264,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -104,    0,    0,
 -242,  -84, -167, -167, -144,    0,  -95,   65,  -73,    0,
    0, -108,    0,    0,  -90, -144, -144, -144, -144,  -79,
  -71,    0,  -78,    0, -150, -144, -108, -108, -233, -144,
 -167, -167, -144, -144, -144, -144, -144, -144,    0, -167,
 -167,    0,    0, -229, -229, -142, -229, -211, -205, -205,
 -211,    0, -229,    0, -123, -108, -108, -229, -229, -229,
 -229, -229, -229, -150,    0,    0,  -67,  -45,  -66,    0,
 -144, -150,    0, -111, -110,    0,  -50,    0,    0,    0,
 -150,    0, -229,    0,  -65,  -58, -144,  -37,    0,    0,
    0, -229,    0,    0, -211, -211,  -26, -150,    0,    0,
 -150,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -255,    0,    0, -195,    0,
    0,    0,    0,    0,    0,    0,    0, -207,    0,  -55,
  -49, -159,    0,    0,    0,    0,    0, -235,    0,    0,
    0,    0,    0, -236,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0, -208, -209,    0,    0,
    0,    0,    0,    0,    0,    0, -122,    0,    0,    0,
    0,  -88,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0, -235,    0,  -53,  -19,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -48, -109,    0, -217, -179,    0,    0,
 -179,    0,  -32,    0,    0,   15,   49, -247, -231, -158,
 -134, -127, -125,  -77,    0,    0,    0,    0,    0,    0,
    0,  -44,    0,    0,    0,    0,    0,    0,    0,    0,
  -77,    0, -100,    0,    0,    0,    0, -253,    0,    0,
    0,  -15,    0,    0, -179, -179,    0,  -77,    0,    0,
  -77,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  239,    0,  -28,    0,    0,  228,   98,
    0,    0,  225,    0,    0,    0,  -97,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  -54,  182,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  171,    0,    0,    0,    0,   37,  111,
    0,
};
#define YYTABLESIZE 347
static const short yytable[] = {                         50,
   79,    6,   23,  126,   24,    6,   46,    6,    6,    6,
   64,    6,   94,   95,   97,    6,    6,   74,   68,    1,
   64,  103,   54,   54,   63,   95,   65,   69,  108,  109,
  110,  111,  112,  113,   46,    6,   65,   46,    6,   81,
   82,   40,   40,   81,   82,   75,  102,  149,  150,    7,
  104,   54,   63,    7,   54,    7,    7,    7,    7,    7,
    6,   13,   13,    7,    7,   13,  133,   16,   13,   16,
   40,   13,    4,   40,   25,   13,   13,    6,   18,   23,
    7,    6,  142,    7,    6,  129,    7,    6,   19,   77,
   78,    6,    6,  134,   22,   13,   27,   12,   13,   67,
   65,   12,  139,   16,   12,   16,   28,   12,    6,   67,
   29,   12,   12,   30,    6,   55,   31,  106,  107,  152,
   32,   33,  153,   66,   47,   56,   57,   48,   53,   54,
   69,   12,   68,   66,   12,   82,   82,   82,   55,   49,
   69,  120,   68,   34,  121,   82,   82,   52,   56,   57,
   82,   82,   82,   82,   82,   82,   82,   82,   82,   82,
  128,   82,   67,  121,   82,   82,   90,   91,   82,   70,
   70,   70,  135,  136,   83,   27,   27,   83,   72,   70,
   70,   63,   63,   84,   70,   70,   84,   80,   70,   70,
   70,   70,   70,   70,   89,   70,  124,  125,   70,   70,
  115,  116,   70,   92,   71,   71,   71,   76,   98,  101,
   63,   99,  131,   63,   71,   71,  130,  132,  137,   71,
   71,  143,  140,   71,   71,   71,   71,   71,   71,  141,
   71,  151,   11,   71,   71,   61,   50,   71,   72,   72,
   72,   63,   51,   63,    9,   26,   46,   93,   72,   72,
  105,    0,    0,   72,   72,    0,    0,   72,   72,   72,
   72,   72,   72,    0,   72,    0,    0,   72,   72,    0,
    0,   72,   73,   73,   73,    0,    0,    0,    0,    0,
    0,    0,   73,   73,    0,    0,    0,   73,   73,    0,
    0,   73,   73,   73,   73,   73,   73,    0,   73,    0,
    0,   73,   73,    0,    0,   73,   74,   74,   74,    0,
    0,    0,    0,    0,    0,    0,   74,   74,    0,    0,
    0,   74,   74,    0,    0,   74,   74,   74,   74,   74,
   74,    0,   74,    0,    0,   74,   74,   81,   82,   74,
    0,   83,   84,   85,   86,   87,   88,
};
static const short yycheck[] = {                         28,
   55,  257,  263,  101,  265,  261,  260,  263,  264,  265,
  258,  267,   67,   68,   69,  271,  272,  260,  283,  266,
  268,   76,  259,  260,  260,   80,  258,  292,   83,   84,
   85,   86,   87,   88,  288,  291,  268,  291,  294,  273,
  274,  259,  260,  273,  274,  288,   75,  145,  146,  257,
  284,  288,  288,  261,  291,  263,  264,  265,  270,  267,
  288,  257,  291,  271,  272,  261,  121,  263,  264,  265,
  288,  267,  294,  291,  283,  271,  272,  257,  288,  288,
  288,  261,  137,  291,  264,  114,  294,  267,  294,   53,
   54,  271,  272,  122,  288,  291,  287,  257,  294,  258,
  283,  261,  131,  263,  264,  265,  257,  267,  288,  268,
  261,  271,  272,  264,  294,  283,  267,   81,   82,  148,
  271,  272,  151,  258,  294,  293,  294,  294,  273,  274,
  258,  291,  258,  268,  294,  258,  259,  260,  283,  294,
  268,  284,  268,  294,  287,  268,  269,  294,  293,  294,
  273,  274,  275,  276,  277,  278,  279,  280,  281,  282,
  284,  284,  283,  287,  287,  288,  275,  276,  291,  258,
  259,  260,  284,  284,  284,  287,  287,  287,  283,  268,
  269,  259,  260,  284,  273,  274,  287,  283,  277,  278,
  279,  280,  281,  282,  268,  284,   99,  100,  287,  288,
   90,   91,  291,  294,  258,  259,  260,  292,  288,  288,
  288,  283,  258,  291,  268,  269,  284,  284,  269,  273,
  274,  259,  288,  277,  278,  279,  280,  281,  282,  288,
  284,  258,  288,  287,  288,  284,  269,  291,  258,  259,
  260,  291,  258,  288,    6,   18,   22,   66,  268,  269,
   80,   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,   -1,   -1,  287,  288,   -1,
   -1,  291,  258,  259,  260,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,
   -1,  277,  278,  279,  280,  281,  282,   -1,  284,   -1,
   -1,  287,  288,   -1,   -1,  291,  258,  259,  260,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,   -1,
   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,  281,
  282,   -1,  284,   -1,   -1,  287,  288,  273,  274,  291,
   -1,  277,  278,  279,  280,  281,  282,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 294
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"SBEGIN","DO","ELSE","SEND","FOR",
"FORWARD","FUNCTION","IF","PROCEDURE","PROGRAM","READ","THEN","TO","VAR",
"WHILE","WRITE","PLUS","MINUS","MULT","DIV","EQ","NEQ","LE","LT","GE","GT",
"LPAREN","RPAREN","LBRACKET","RBRACKET","COMMA","SEMICOLON","COLON","INTERVAL",
"PERIOD","ASSIGN","NUMBER","IDENT",
};
static const char *yyrule[] = {
"$accept : program",
"$$1 :",
"$$2 :",
"program : PROGRAM $$1 IDENT $$2 SEMICOLON outblock PERIOD",
"$$3 :",
"outblock : var_decl_part subprog_decl_part $$3 statement",
"var_decl_part :",
"var_decl_part : var_decl_list SEMICOLON",
"var_decl_list : var_decl",
"var_decl_list : var_decl_list SEMICOLON var_decl",
"$$4 :",
"var_decl : VAR $$4 id_list",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"$$5 :",
"subprog_decl : $$5 proc_decl",
"$$6 :",
"proc_decl : PROCEDURE IDENT $$6 SEMICOLON inblock",
"$$7 :",
"$$8 :",
"proc_decl : PROCEDURE IDENT LPAREN $$7 id_list RPAREN SEMICOLON $$8 inblock",
"$$9 :",
"proc_decl : FUNCTION IDENT $$9 SEMICOLON inblock",
"$$10 :",
"$$11 :",
"proc_decl : FUNCTION IDENT $$10 LPAREN id_list RPAREN SEMICOLON $$11 inblock",
"inblock : var_decl_part statement",
"statement_list : statement_list SEMICOLON statement",
"statement_list : statement",
"statement : assignment_statement",
"statement : if_statement",
"statement : for_statement",
"statement : while_statement",
"statement : proc_call_statement",
"statement : null_statement",
"statement : block_statement",
"statement : read_statement",
"statement : write_statement",
"assignment_statement : IDENT ASSIGN expression",
"$$12 :",
"$$13 :",
"if_statement : IF condition THEN $$12 statement $$13 else_statement",
"$$14 :",
"else_statement : ELSE $$14 statement",
"else_statement :",
"$$15 :",
"$$16 :",
"while_statement : WHILE $$15 condition $$16 DO statement",
"$$17 :",
"$$18 :",
"for_statement : FOR IDENT ASSIGN expression $$17 TO expression $$18 DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"proc_call_name : IDENT LPAREN arg_list RPAREN",
"func_call_statement : func_call_name",
"func_call_name : IDENT LPAREN arg_list RPAREN",
"block_statement : SBEGIN statement_list SEND",
"$$19 :",
"read_statement : READ LPAREN IDENT $$19 RPAREN",
"$$20 :",
"write_statement : WRITE LPAREN expression $$20 RPAREN",
"null_statement :",
"condition : expression EQ expression",
"condition : expression NEQ expression",
"condition : expression LT expression",
"condition : expression LE expression",
"condition : expression GT expression",
"condition : expression GE expression",
"expression : term",
"expression : PLUS term",
"expression : MINUS term",
"expression : expression PLUS term",
"expression : expression MINUS term",
"term : factor",
"term : term MULT factor",
"term : term DIV factor",
"factor : var_name",
"factor : func_call_statement",
"factor : NUMBER",
"factor : LPAREN expression RPAREN",
"var_name : IDENT",
"arg_list : expression",
"arg_list : arg_list COMMA expression",
"id_list : IDENT",
"id_list : id_list COMMA IDENT",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 561 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s in line %d,token %s\n", s,yylineno,yytext);
}
#line 449 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 54 "parser.y"
	{
		printf("program is inputted.\n");
		if((fp = fopen("result.ll","w")) == NULL){
		fprintf(stderr,"ファイルのオープンに失敗\n");
		exit(1);	
		}
	}
break;
case 2:
#line 62 "parser.y"
	{	
		flag = GLOBAL_VAR;
		init_fstack();
		init_brstack();
		init_lstack();  
 
    }
break;
case 3:
#line 71 "parser.y"
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
break;
case 4:
#line 87 "parser.y"
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
break;
case 5:
#line 100 "parser.y"
	{
		Factor tmp;
		tmp.type = CONSTANT;
		tmp.val = 0;
		factorpush(tmp);
		generate_code(Ret);
		delete();
		flag = GLOBAL_VAR;
	}
break;
case 10:
#line 121 "parser.y"
	{flag = GLOBAL_VAR;}
break;
case 16:
#line 132 "parser.y"
	{flag = LOCAL_VAR;}
break;
case 18:
#line 136 "parser.y"
	{
		flag = LOCAL_VAR;
		insert(yystack.l_mark[0].ident,PROC_NAME);
		generate_decl(yystack.l_mark[0].ident,VOID,0);	
	}
break;
case 19:
#line 142 "parser.y"
	{
		Factor r;
		r.type = LOCAL_VAR;
		strcpy(r.vname,"void");
		r.val = 0;
		factorpush(r);
		generate_code(Ret);
	}
break;
case 20:
#line 152 "parser.y"
	{
		insert(yystack.l_mark[-1].ident,PROC_NAME);
		arg_flag = 1;
	}
break;
case 21:
#line 157 "parser.y"
	{
		generate_decl(yystack.l_mark[-5].ident,VOID,arity);
		struct symboltable *st = lookup(yystack.l_mark[-5].ident);
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
break;
case 22:
#line 182 "parser.y"
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
break;
case 23:
#line 195 "parser.y"
	{
		insert(yystack.l_mark[0].ident,FUNC_NAME);
		insert(yystack.l_mark[0].ident,LOCAL_VAR); /* 返り値を記号表に追加 */
		generate_decl(yystack.l_mark[0].ident,I32,0);
		generate_code(Alloca); /* 返り値用レジスタ */
	}
break;
case 24:
#line 202 "parser.y"
	{	
		factorgenerate(yystack.l_mark[-3].ident);
		generate_code(Load);
		generate_code(Ret);
		delete();
		flag = GLOBAL_VAR;
	}
break;
case 25:
#line 211 "parser.y"
	{
		insert(yystack.l_mark[0].ident,FUNC_NAME);
		arg_flag = 1;
	}
break;
case 26:
#line 216 "parser.y"
	{
		generate_decl(yystack.l_mark[-5].ident,I32,arity);
        
		struct symboltable *st = lookup(yystack.l_mark[-5].ident);
		(st->num) = arity;
		arg_flag = 0;
		cntr = cntr + arity;
		insert(yystack.l_mark[-5].ident,LOCAL_VAR); /* 返り値を記号表に追加 */
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
break;
case 27:
#line 244 "parser.y"
	{
		factorgenerate(yystack.l_mark[-7].ident);
		generate_code(Load);
		generate_code(Ret);
		delete();
		flag = GLOBAL_VAR;
	}
break;
case 40:
#line 283 "parser.y"
	{	
		factorgenerate(yystack.l_mark[-2].ident);
	  	generate_code(Store);
	}
break;
case 41:
#line 290 "parser.y"
	{
		generate_code(BrCond);
		generate_code(Label);
		labelpop();
	}
break;
case 42:
#line 296 "parser.y"
	{
		generate_code(BrUncond); /* arg1未確定 */
	}
break;
case 43:
#line 300 "parser.y"
	{
		generate_code(Label);
		int label = labelpop();
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = label;
	}
break;
case 44:
#line 309 "parser.y"
	{
		generate_code(Label);
		int label = labelpop();
		LLVMcode *tmp1 = brpop();
		LLVMcode *tmp2 = brpop();
		brpush(tmp1);
		(tmp2->args).brcond.arg3 = label;
	}
break;
case 45:
#line 318 "parser.y"
	{
		generate_code(BrUncond);
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = cntr;
	}
break;
case 46:
#line 324 "parser.y"
	{
		LLVMcode *tmp1 = brpop();
		LLVMcode *tmp2 = brpop();
		brpush(tmp1);
		(tmp2->args).brcond.arg3 = cntr;
	}
break;
case 47:
#line 333 "parser.y"
	{
		generate_code(BrUncond); /* 条件文へのbr エラー発生*/
		brpop(); /* br確定のため削除 */
		generate_code(Label); /* 条件文ラベル宣言 */
	}
break;
case 48:
#line 339 "parser.y"
	{
		generate_code(BrCond); /* 条件文brc,未確定  */
		generate_code(Label); /* 処理部(statement)のラベル宣言 */
		labelpop(); /* ラベル削除 */
	}
break;
case 49:
#line 345 "parser.y"
	{
		generate_code(BrUncond); /* 条件文へのbr,未確定 */
		LLVMcode *tmp1 = brpop();
		(tmp1->args).bruncond.arg1 = labelpop(); /* 条件文へのbr確定 */
		generate_code(Label); /* whileブロック外のラベル */
		LLVMcode *tmp2 = brpop(); 
		(tmp2->args).brcond.arg3 = labelpop(); /* 条件文brc確定 */
	}
break;
case 50:
#line 358 "parser.y"
	{	
		factorgenerate(yystack.l_mark[-2].ident);
		generate_code(Store);
		generate_code(BrUncond);/* 即確定 */
		brpop();
		generate_code(Label);
		factorgenerate(yystack.l_mark[-2].ident);
		generate_code(Load);
	}
break;
case 51:
#line 369 "parser.y"
	{
		/* 継続判定*/

		generate_icmp(SLT);
		generate_code(BrCond);/* arg2確定,arg3未確定*/
		generate_code(Label); /*処理部ラベル*/
		labelpop();
	}
break;
case 52:
#line 377 "parser.y"
	{
		generate_code(BrUncond);
		brpop();
		/* インクリメント処理*/
		generate_code(Label);
		labelpop();
		factorgenerate(yystack.l_mark[-8].ident);
		generate_code(Load);
		
		Factor one;
		one.type = CONSTANT;
		one.val = 1;
		factorpush(one);
		generate_code(Add);
		factorgenerate(yystack.l_mark[-8].ident);
		generate_code(Store);
		generate_code(BrUncond);
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = labelpop();
		generate_code(Label); /*forブロック外へのラベル*/
		tmp = brpop();
		(tmp->args).brcond.arg3 = labelpop();/* arg3確定 */
	}
break;
case 54:
#line 406 "parser.y"
	{
		factorgenerate(yystack.l_mark[0].ident);
		Factor f = factorpop();
		Factor args[10];
		generate_call(f,VOID,args); /* 引数、返り値なしの手続き  */
	}
break;
case 55:
#line 413 "parser.y"
	{
		factorgenerate(yystack.l_mark[-3].ident);
		Factor f = factorpop();
		Factor args[10];
		for(i = 0;i < f.val;i++){
			args[i] = factorpop();
		}
		generate_call(f,VOID,args);
	}
break;
case 57:
#line 429 "parser.y"
	{
		struct symboltable *p = type_lookup(yystack.l_mark[-3].ident,FUNC_NAME);
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
break;
case 59:
#line 447 "parser.y"
	{	
		factorgenerate(yystack.l_mark[0].ident);
		Factor arg = factorpop();
		Factor args[10] = {arg};
		Factor f ={PROC_NAME,"read",1}; /* read関数は記号表にないため生成 */
		generate_call(f,I32,args);
		read_flag = 1;
	}
break;
case 61:
#line 459 "parser.y"
	{
		Factor arg = factorpop();
		Factor args[10] = {arg};
		Factor f ={PROC_NAME,"write",1}; /* write関数は記号表にないため生成 */
		generate_call(f,I32,args);
		write_flag = 1;
	}
break;
case 64:
#line 472 "parser.y"
	{generate_icmp(EQUAL);}
break;
case 65:
#line 473 "parser.y"
	{generate_icmp(NE);}
break;
case 66:
#line 474 "parser.y"
	{generate_icmp(SLT);}
break;
case 67:
#line 475 "parser.y"
	{generate_icmp(SLE);}
break;
case 68:
#line 476 "parser.y"
	{generate_icmp(SGT);}
break;
case 69:
#line 477 "parser.y"
	{generate_icmp(SGE);}
break;
case 73:
#line 485 "parser.y"
	{
	  generate_code(Add);
	}
break;
case 74:
#line 489 "parser.y"
	{	
	  generate_code(Sub);
	}
break;
case 76:
#line 497 "parser.y"
	{	
	  generate_code(Mult);
	}
break;
case 77:
#line 501 "parser.y"
	{
	  generate_code(Div);
	}
break;
case 80:
#line 509 "parser.y"
	{
	  Factor tmp;
	  tmp.type = CONSTANT;
	  tmp.val = yystack.l_mark[0].num;
	  factorpush(tmp);
	}
break;
case 82:
#line 519 "parser.y"
	{
		factorgenerate(yystack.l_mark[0].ident);
		generate_code(Load);	    
	}
break;
case 85:
#line 530 "parser.y"
	{
	  insert(yystack.l_mark[0].ident,flag);
	  if(flag == GLOBAL_VAR){ /*グローバル変数宣言*/
		fprintf(fp,"@%s = common global i32 0, align 4\n",yystack.l_mark[0].ident);
	  }
	  else if(arg_flag == 1){
		  strcpy(arg_name[arity],yystack.l_mark[0].ident);
		  arity++;
	  }
	  else{/*ローカル変数宣言*/
	    generate_code(Alloca);
	  }
	}
break;
case 86:
#line 544 "parser.y"
	{
	    insert(yystack.l_mark[0].ident,flag);
	    if(flag == GLOBAL_VAR){ /*グローバル変数宣言*/
		  fprintf(fp,"@%s = common global i32 0, align 4\n",yystack.l_mark[0].ident);
	    }
		else if(arg_flag == 1){
			strcpy(arg_name[arity],yystack.l_mark[0].ident);
			arity++;
		}
	    else{/*ローカル変数宣言*/
	      generate_code(Alloca);
	    }
	  }
break;
#line 1144 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
