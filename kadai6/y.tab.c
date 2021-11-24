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

Scope flag = GLOBAL_VAR;
FILE *fp; 
#line 28 "parser.y"
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
#line 56 "y.tab.c"

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
    1,    2,    0,    7,    3,    4,    4,    8,    8,    9,
    5,    5,   11,   11,   12,   13,   14,   15,   16,   16,
    6,    6,    6,    6,    6,    6,    6,    6,    6,   17,
   28,   30,   18,   31,   29,   29,   32,   33,   20,   34,
   35,   19,   21,   36,   36,   23,   38,   24,   39,   25,
   22,   27,   27,   27,   27,   27,   27,   26,   26,   26,
   26,   26,   40,   40,   40,   41,   41,   41,   42,   37,
   37,   10,   10,
};
static const short yylen[] = {                            2,
    0,    0,    7,    0,    4,    0,    2,    1,    3,    2,
    2,    0,    3,    1,    1,    4,    1,    2,    3,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    1,    3,
    0,    0,    7,    0,    3,    0,    0,    0,    6,    0,
    0,   10,    1,    1,    4,    3,    0,    5,    0,    5,
    0,    3,    3,    3,    3,    3,    3,    1,    2,    2,
    3,    3,    1,    3,    3,    1,    1,    3,    1,    1,
    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    8,   72,    0,    3,    0,    4,    0,   14,   15,    0,
    0,   17,    0,    0,    0,    9,   73,    0,    0,    0,
    0,    0,   37,    0,    0,    5,   21,   22,   23,   24,
   25,   26,   27,   28,   29,   43,   13,    0,   16,   20,
    0,    0,    0,    0,    0,   67,   69,    0,    0,    0,
   63,   66,    0,    0,    0,    0,    0,   18,   46,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   31,    0,    0,   47,   38,    0,    0,    0,
    0,   19,    0,   68,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   64,   65,    0,    0,    0,   45,    0,
    0,   32,   48,    0,   50,    0,    0,    0,   39,    0,
   34,   33,    0,    0,    0,   35,   42,
};
static const short yydgoto[] = {                          2,
    3,    5,    8,    9,   16,   36,   24,   10,   11,   13,
   17,   18,   19,   23,   49,   51,   37,   38,   39,   40,
   41,   42,   43,   44,   45,   58,   59,  103,  122,  118,
  124,   64,  107,  111,  123,   46,   90,  106,  108,   60,
   61,   62,
};
static const short yysindex[] = {                      -251,
    0,    0, -292,    0, -259, -248, -228, -205, -175, -184,
    0,    0, -161,    0, -151,    0, -178,    0,    0, -248,
 -150,    0, -137, -164, -175,    0,    0, -248, -164, -136,
 -154, -119,    0, -110, -174,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0, -164,    0,    0,
 -246, -155, -177, -177, -154,    0,    0,    6, -109, -224,
    0,    0, -123, -154, -154, -154, -154,    0,    0, -164,
 -154, -224, -224, -266, -177, -177, -154, -154, -154, -154,
 -154, -154,    0, -177, -177,    0,    0, -264, -264, -135,
 -264,    0, -264,    0, -224, -224, -264, -264, -264, -264,
 -264, -264, -164,    0,    0, -107,  -84, -106,    0, -154,
  -85,    0,    0, -164,    0, -264, -154,  -74,    0, -264,
    0,    0,  -66, -164, -164,    0,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -218,    0,    0, -202,    0,
    0,    0, -101,    0,    0,    0,    0,    0,    0, -227,
    0,    0,    0,  -98, -189,    0,    0, -173, -240,    0,
    0,    0,    0,    0, -256,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -94,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -146,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -240,
    0, -112,  -78,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -87, -134,    0,
 -105,    0,  -64,    0,  -44,  -10, -252, -237, -208, -187,
 -181, -157,  -71,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -71,    0, -124,    0, -255,    0,  -60,
    0,    0,    0,  -71,  -71,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  179,    0,  -29,    0,    0,  188,    0,
    0,  186,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -54,  148,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    4,
   40,    0,
};
#define YYTABLESIZE 288
static const short yytable[] = {                         50,
   74,    4,   44,   44,   36,   52,   75,   76,   75,   76,
   88,   89,   91,   69,    1,   52,   93,   94,   68,   51,
   53,    7,   97,   98,   99,  100,  101,  102,    6,    7,
   53,   44,   36,    7,   44,   36,    7,    7,    6,    7,
   92,   70,    6,    7,    7,    6,    6,   51,    6,   55,
   84,   85,    6,    6,   12,  116,   72,   73,   12,   55,
    7,   12,  120,    7,   12,   12,    7,   11,   12,   12,
   54,   11,    6,  112,   11,    6,   57,   11,   95,   96,
   54,   11,   11,    6,  119,   14,   57,    6,   12,   15,
    6,   12,   29,    6,  126,  127,   30,    6,    6,   31,
   56,   11,   32,   20,   11,   55,   33,   34,   66,   25,
   56,   58,   58,   58,    6,   56,   57,   67,   53,   54,
    6,   58,   58,  104,  105,   21,   58,   58,   55,   35,
   58,   58,   58,   58,   58,   58,   71,   58,   56,   57,
   58,   58,   22,   27,   58,   59,   59,   59,  109,   70,
   28,  110,   70,   30,   30,   59,   59,   52,   83,   71,
   59,   59,   71,   63,   59,   59,   59,   59,   59,   59,
   86,   59,   65,  114,   59,   59,  113,  115,   59,   60,
   60,   60,   30,  117,  121,   30,   10,   51,   51,   60,
   60,  125,   51,   51,   60,   60,   49,   41,   60,   60,
   60,   60,   60,   60,   40,   60,   48,   26,   60,   60,
   47,   87,   60,   61,   61,   61,   51,    0,    0,   51,
    0,    0,    0,   61,   61,    0,    0,    0,   61,   61,
    0,    0,   61,   61,   61,   61,   61,   61,    0,   61,
    0,    0,   61,   61,    0,    0,   61,   62,   62,   62,
    0,    0,    0,    0,    0,    0,    0,   62,   62,    0,
    0,    0,   62,   62,    0,    0,   62,   62,   62,   62,
   62,   62,    0,   62,    0,    0,   62,   62,   75,   76,
   62,    0,   77,   78,   79,   80,   81,   82,
};
static const short yycheck[] = {                         29,
   55,  294,  259,  260,  260,  258,  273,  274,  273,  274,
   65,   66,   67,  260,  266,  268,   71,  284,   48,  260,
  258,  270,   77,   78,   79,   80,   81,   82,  288,  257,
  268,  288,  288,  261,  291,  291,  264,  265,  257,  267,
   70,  288,  261,  271,  272,  264,  265,  288,  267,  258,
  275,  276,  271,  272,  257,  110,   53,   54,  261,  268,
  288,  264,  117,  291,  267,  294,  294,  257,  271,  272,
  258,  261,  291,  103,  264,  294,  258,  267,   75,   76,
  268,  271,  272,  257,  114,  291,  268,  261,  291,  265,
  264,  294,  257,  267,  124,  125,  261,  271,  272,  264,
  258,  291,  267,  288,  294,  283,  271,  272,  283,  288,
  268,  258,  259,  260,  288,  293,  294,  292,  273,  274,
  294,  268,  269,   84,   85,  287,  273,  274,  283,  294,
  277,  278,  279,  280,  281,  282,  292,  284,  293,  294,
  287,  288,  294,  294,  291,  258,  259,  260,  284,  284,
  288,  287,  287,  259,  260,  268,  269,  294,  268,  284,
  273,  274,  287,  283,  277,  278,  279,  280,  281,  282,
  294,  284,  283,  258,  287,  288,  284,  284,  291,  258,
  259,  260,  288,  269,  259,  291,  288,  259,  260,  268,
  269,  258,  291,  288,  273,  274,  284,  258,  277,  278,
  279,  280,  281,  282,  269,  284,   28,   20,  287,  288,
   25,   64,  291,  258,  259,  260,  288,   -1,   -1,  291,
   -1,   -1,   -1,  268,  269,   -1,   -1,   -1,  273,  274,
   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,  284,
   -1,   -1,  287,  288,   -1,   -1,  291,  258,  259,  260,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  268,  269,   -1,
   -1,   -1,  273,  274,   -1,   -1,  277,  278,  279,  280,
  281,  282,   -1,  284,   -1,   -1,  287,  288,  273,  274,
  291,   -1,  277,  278,  279,  280,  281,  282,
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
"var_decl : VAR id_list",
"subprog_decl_part : subprog_decl_list SEMICOLON",
"subprog_decl_part :",
"subprog_decl_list : subprog_decl_list SEMICOLON subprog_decl",
"subprog_decl_list : subprog_decl",
"subprog_decl : proc_decl",
"proc_decl : PROCEDURE proc_name SEMICOLON inblock",
"proc_name : IDENT",
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
"$$4 :",
"$$5 :",
"if_statement : IF condition THEN $$4 statement $$5 else_statement",
"$$6 :",
"else_statement : ELSE $$6 statement",
"else_statement :",
"$$7 :",
"$$8 :",
"while_statement : WHILE $$7 condition $$8 DO statement",
"$$9 :",
"$$10 :",
"for_statement : FOR IDENT ASSIGN expression $$9 TO expression $$10 DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"proc_call_name : IDENT LPAREN arg_list RPAREN",
"block_statement : SBEGIN statement_list SEND",
"$$11 :",
"read_statement : READ LPAREN IDENT $$11 RPAREN",
"$$12 :",
"write_statement : WRITE LPAREN expression $$12 RPAREN",
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
#line 420 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s in line %d,token %s\n", s,yylineno,yytext);
}
#line 408 "y.tab.c"

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
#line 51 "parser.y"
	{
		printf("program is inputted.\n");
		if((fp = fopen("result.ll","w")) == NULL){
		fprintf(stderr,"ファイルのオープンに失敗\n");
		exit(1);	
		}
	}
break;
case 2:
#line 59 "parser.y"
	{	
		flag = GLOBAL_VAR;
		init_fstack();
		init_brstack();
		init_lstack();  
 
    }
break;
case 3:
#line 68 "parser.y"
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
#line 84 "parser.y"
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
break;
case 5:
#line 97 "parser.y"
	{
		Factor tmp;
		tmp.type = CONSTANT;
		tmp.val = 0;
		factorpush(tmp);
		generate_code(Ret);
	}
break;
case 16:
#line 130 "parser.y"
	{
		Factor r;
		r.type = LOCAL_VAR;
		strcpy(r.vname,"void");
		r.val = 0;
		factorpush(r);
		generate_code(Ret);
	}
break;
case 17:
#line 141 "parser.y"
	{
	  flag = LOCAL_VAR;
	  insert(yystack.l_mark[0].ident,PROC_NAME);
	  generate_decl(yystack.l_mark[0].ident,VOID);

	}
break;
case 30:
#line 169 "parser.y"
	{	
		factorgenerate(yystack.l_mark[-2].ident);
	  	generate_code(Store);
	}
break;
case 31:
#line 176 "parser.y"
	{
		generate_code(BrCond);
		generate_code(Label);
		labelpop();
	}
break;
case 32:
#line 182 "parser.y"
	{
		generate_code(BrUncond); /* arg1未確定 */
	}
break;
case 33:
#line 186 "parser.y"
	{
		generate_code(Label);
		int label = labelpop();
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = label;
	}
break;
case 34:
#line 195 "parser.y"
	{
		generate_code(Label);
		int label = labelpop();
		LLVMcode *tmp1 = brpop();
		LLVMcode *tmp2 = brpop();
		brpush(tmp1);
		(tmp2->args).brcond.arg3 = label;
	}
break;
case 35:
#line 204 "parser.y"
	{
		generate_code(BrUncond);
		LLVMcode *tmp = brpop();
		(tmp->args).bruncond.arg1 = cntr;
	}
break;
case 36:
#line 210 "parser.y"
	{
		LLVMcode *tmp1 = brpop();
		LLVMcode *tmp2 = brpop();
		brpush(tmp1);
		(tmp2->args).brcond.arg3 = cntr;
	}
break;
case 37:
#line 219 "parser.y"
	{
		generate_code(BrUncond); /* 条件文へのbr エラー発生*/
		brpop(); /* br確定のため削除 */
		generate_code(Label); /* 条件文ラベル宣言 */
	}
break;
case 38:
#line 225 "parser.y"
	{
		generate_code(BrCond); /* 条件文brc,未確定  */
		generate_code(Label); /* 処理部(statement)のラベル宣言 */
		labelpop(); /* ラベル削除 */
	}
break;
case 39:
#line 231 "parser.y"
	{
		generate_code(BrUncond); /* 条件文へのbr,未確定 */
		LLVMcode *tmp1 = brpop();
		(tmp1->args).bruncond.arg1 = labelpop(); /* 条件文へのbr確定 */
		generate_code(Label); /* whileブロック外のラベル */
		LLVMcode *tmp2 = brpop(); 
		(tmp2->args).brcond.arg3 = labelpop(); /* 条件文brc確定 */
	}
break;
case 40:
#line 244 "parser.y"
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
case 41:
#line 255 "parser.y"
	{
		/* 継続判定*/

		generate_icmp(SLT);
		generate_code(BrCond);/* arg2確定,arg3未確定*/
		generate_code(Label); /*処理部ラベル*/
		labelpop();
	}
break;
case 42:
#line 263 "parser.y"
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
case 44:
#line 292 "parser.y"
	{
		factorgenerate(yystack.l_mark[0].ident);
		Factor f = factorpop();
		Factor args[10];
		generate_call(f,VOID,args); /* 引数、返り値なしの手続き  */
	}
break;
case 46:
#line 301 "parser.y"
	{delete();flag = GLOBAL_VAR;}
break;
case 47:
#line 305 "parser.y"
	{	
		factorgenerate(yystack.l_mark[0].ident);
		Factor arg = factorpop();
		Factor args[10] = {arg};
		Factor f ={PROC_NAME,"read",1}; /* read関数は記号表にないため生成 */
		generate_call(f,I32,args);
		read_flag = 1;
	}
break;
case 49:
#line 317 "parser.y"
	{
		Factor arg = factorpop();
		Factor args[10] = {arg};
		Factor f ={PROC_NAME,"write",1}; /* write関数は記号表にないため生成 */
		generate_call(f,I32,args);
		write_flag = 1;
	}
break;
case 52:
#line 330 "parser.y"
	{generate_icmp(EQUAL);}
break;
case 53:
#line 331 "parser.y"
	{generate_icmp(NE);}
break;
case 54:
#line 332 "parser.y"
	{generate_icmp(SLT);}
break;
case 55:
#line 333 "parser.y"
	{generate_icmp(SLE);}
break;
case 56:
#line 334 "parser.y"
	{generate_icmp(SGT);}
break;
case 57:
#line 335 "parser.y"
	{generate_icmp(SGE);}
break;
case 61:
#line 343 "parser.y"
	{
	  generate_code(Add);
	}
break;
case 62:
#line 347 "parser.y"
	{	
	  generate_code(Sub);
	}
break;
case 64:
#line 355 "parser.y"
	{	
	  generate_code(Mult);
	}
break;
case 65:
#line 359 "parser.y"
	{
	  generate_code(Div);
	}
break;
case 67:
#line 366 "parser.y"
	{
	  Factor tmp;
	  tmp.type = CONSTANT;
	  tmp.val = yystack.l_mark[0].num;
	  factorpush(tmp);
	}
break;
case 69:
#line 376 "parser.y"
	{
		factorgenerate(yystack.l_mark[0].ident);
		generate_code(Load);	    
	}
break;
case 72:
#line 387 "parser.y"
	{
	  insert(yystack.l_mark[0].ident,flag);
	  if(flag == GLOBAL_VAR){ /*グローバル変数宣言*/
	    /*Factor tmp;
	    strcpy(tmp.vname,$1);
	    tmp.type = GLOBAL_VAR;
	    factorpush(tmp);
	    generate_code(Global);*/
		fprintf(fp,"@%s = common global i32 0, align 4\n",yystack.l_mark[0].ident);
	  }
	  else{/*ローカル変数宣言*/
	    generate_code(Alloca);
	  }
	}
break;
case 73:
#line 402 "parser.y"
	{
	    insert(yystack.l_mark[0].ident,flag);
	    if(flag == GLOBAL_VAR){ /*グローバル変数宣言*/
	      /*Factor tmp;
	      strcpy(tmp.vname,$3);
	      tmp.type = GLOBAL_VAR;
	      factorpush(tmp);
	      generate_code(Global);*/
		  fprintf(fp,"@%s = common global i32 0, align 4\n",yystack.l_mark[0].ident);
	    }
	    else{/*ローカル変数宣言*/
	      generate_code(Alloca);
	    }
	  }
break;
#line 960 "y.tab.c"
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
