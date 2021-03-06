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
  
int yyparse();
int yyerror(char *);
extern int yylineno;
extern char *yytext;

Scope flag = GLOBAL_VAR;
 
#line 20 "parser.y"
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
#line 48 "y.tab.c"

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
    1,    2,    0,    3,    4,    4,    7,    7,    8,    5,
    5,   10,   10,   11,   12,   13,   14,   15,   15,    6,
    6,    6,    6,    6,    6,    6,    6,    6,   16,   17,
   27,   27,   19,   28,   18,   20,   29,   22,   30,   23,
   24,   21,   26,   26,   26,   26,   26,   26,   25,   25,
   25,   25,   25,   31,   31,   31,   32,   32,   32,   33,
   34,   34,    9,    9,
};
static const short yylen[] = {                            2,
    0,    0,    7,    3,    0,    2,    1,    3,    2,    2,
    0,    3,    1,    1,    4,    1,    2,    3,    1,    1,
    1,    1,    1,    1,    1,    1,    1,    1,    3,    5,
    2,    0,    4,    0,    9,    1,    1,    3,    0,    5,
    4,    0,    3,    3,    3,    3,    3,    3,    1,    2,
    2,    3,    3,    1,    3,    3,    1,    1,    3,    1,
    1,    3,    1,    3,
};
static const short yydefred[] = {                         0,
    1,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    7,   63,    0,    3,    0,    0,    0,   13,   14,    0,
    0,   16,    0,    0,    0,    0,    0,    0,    0,    0,
    4,   20,   21,   22,   23,   24,   25,   26,   27,   28,
   36,    0,    8,   64,    0,   19,    0,   34,    0,    0,
    0,   58,   60,    0,    0,    0,   54,   57,    0,    0,
    0,    0,   12,    0,   15,   38,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   39,    0,    0,    0,   17,   18,    0,   59,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   55,
   56,    0,   33,   41,    0,    0,   30,   40,    0,   31,
    0,    0,   35,
};
static const short yydgoto[] = {                          2,
    3,    5,    8,    9,   16,   31,   10,   11,   13,   17,
   18,   19,   23,   65,   47,   32,   33,   34,   35,   36,
   37,   38,   39,   40,   54,   55,  107,   68,   41,  102,
   56,   57,   58,    0,
};
static const short yysindex[] = {                      -235,
    0,    0, -242,    0, -224, -212, -228, -219, -178, -190,
    0,    0, -173,    0, -164, -156, -153,    0,    0, -212,
 -148,    0, -136, -156, -139,  -37, -126,  -37, -123, -131,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -178,    0,    0, -212,    0, -252,    0, -278, -278,
  -37,    0,    0,  -13, -106, -230,    0,    0, -128,  -93,
  -37,  -37,    0, -156,    0,    0, -156, -119, -230, -230,
 -267, -278, -278,  -37,  -37,  -37,  -37,  -37,  -37, -156,
 -278, -278,    0, -156, -199, -167,    0,    0,  -37,    0,
 -230, -230, -167, -167, -167, -167, -167, -167,  -80,    0,
    0, -104,    0,    0, -255, -156,    0,    0,  -37,    0,
 -146, -156,    0,
};
static const short yyrindex[] = {                         0,
    0,    0,    0,    0,    0, -210,    0,    0, -194,    0,
    0,    0, -105,    0,    0, -109,    0,    0,    0, -223,
    0,    0,    0, -251,    0,    0,    0,    0,    0, -256,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0, -181,    0,    0, -168,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0, -137,    0,    0,    0,    0,
    0,    0,    0, -153,    0,    0, -251,    0, -110,  -83,
    0,    0,    0,    0,    0,    0,    0,    0,    0, -238,
    0,    0,    0, -238,    0, -135,    0,    0,    0,    0,
  -56,  -29, -248, -245, -189, -166, -149, -129, -258,    0,
    0,    0,    0,    0,    0, -238,    0,    0,    0,    0,
    0, -238,    0,
};
static const short yygindex[] = {                         0,
    0,    0,    0,  139,    0,  -24,    0,  167,    0,    0,
  146,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  -50,  161,    0,    0,    0,    0,
   45,   52,    0,    0,
};
#define YYTABLESIZE 269
static const short yytable[] = {                         46,
   71,   32,   37,   37,   51,   72,   73,   66,   42,   43,
   85,   86,   44,  109,   52,   53,   90,   72,   73,   43,
   42,   42,   44,   93,   94,   95,   96,   97,   98,   32,
    1,   37,   32,    6,   37,   67,   42,    6,  105,   87,
    6,    6,   88,    6,   81,   82,    5,    6,    6,   42,
    5,    4,   42,    5,    5,   99,    5,    7,  111,  103,
    5,    5,   11,    6,    6,   12,   11,    6,   46,   11,
    6,   14,   11,   72,   73,   10,   11,   11,   46,   10,
    5,  110,   10,    5,  104,   10,   15,  113,    5,   10,
   10,   45,    5,   69,   70,    5,   11,   20,    5,   11,
   24,   45,    5,    5,   25,   72,   73,   26,   48,   10,
   27,  112,   10,   21,   28,   29,   91,   92,   48,    5,
   49,   49,   49,   29,   29,    5,   72,   73,   47,   22,
   49,   49,  100,  101,   42,   49,   49,   30,   47,   49,
   49,   49,   49,   49,   49,   44,   49,   50,   50,   50,
   49,   45,   29,   49,   48,   29,   59,   50,   50,   61,
   62,   80,   50,   50,   84,   83,   50,   50,   50,   50,
   50,   50,   89,   50,   51,   51,   51,   50,  106,  108,
   50,   42,    9,   64,   51,   51,   43,   63,   60,   51,
   51,    0,    0,   51,   51,   51,   51,   51,   51,    0,
   51,   52,   52,   52,   51,    0,    0,   51,    0,    0,
    0,   52,   52,    0,    0,    0,   52,   52,    0,    0,
   52,   52,   52,   52,   52,   52,    0,   52,   53,   53,
   53,   52,    0,    0,   52,   49,   50,    0,   53,   53,
    0,    0,    0,   53,   53,   51,    0,   53,   53,   53,
   53,   53,   53,    0,   53,   52,   53,    0,   53,   72,
   73,   53,    0,   74,   75,   76,   77,   78,   79,
};
static const short yycheck[] = {                         24,
   51,  260,  259,  260,  283,  273,  274,  260,  260,  258,
   61,   62,  258,  269,  293,  294,  284,  273,  274,  268,
  259,  260,  268,   74,   75,   76,   77,   78,   79,  288,
  266,  288,  291,  257,  291,  288,  288,  261,   89,   64,
  264,  265,   67,  267,  275,  276,  257,  271,  272,  288,
  261,  294,  291,  264,  265,   80,  267,  270,  109,   84,
  271,  272,  257,  288,  288,  294,  261,  291,  258,  264,
  294,  291,  267,  273,  274,  257,  271,  272,  268,  261,
  291,  106,  264,  294,  284,  267,  265,  112,  257,  271,
  272,  258,  261,   49,   50,  264,  291,  288,  267,  294,
  257,  268,  271,  272,  261,  273,  274,  264,  258,  291,
  267,  258,  294,  287,  271,  272,   72,   73,  268,  288,
  258,  259,  260,  259,  260,  294,  273,  274,  258,  294,
  268,  269,   81,   82,  288,  273,  274,  294,  268,  277,
  278,  279,  280,  281,  282,  294,  284,  258,  259,  260,
  288,  288,  288,  291,  294,  291,  283,  268,  269,  283,
  292,  268,  273,  274,  258,  294,  277,  278,  279,  280,
  281,  282,  292,  284,  258,  259,  260,  288,  259,  284,
  291,  291,  288,   45,  268,  269,   20,   42,   28,  273,
  274,   -1,   -1,  277,  278,  279,  280,  281,  282,   -1,
  284,  258,  259,  260,  288,   -1,   -1,  291,   -1,   -1,
   -1,  268,  269,   -1,   -1,   -1,  273,  274,   -1,   -1,
  277,  278,  279,  280,  281,  282,   -1,  284,  258,  259,
  260,  288,   -1,   -1,  291,  273,  274,   -1,  268,  269,
   -1,   -1,   -1,  273,  274,  283,   -1,  277,  278,  279,
  280,  281,  282,   -1,  284,  293,  294,   -1,  288,  273,
  274,  291,   -1,  277,  278,  279,  280,  281,  282,
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
"outblock : var_decl_part subprog_decl_part statement",
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
"if_statement : IF condition THEN statement else_statement",
"else_statement : ELSE statement",
"else_statement :",
"while_statement : WHILE condition DO statement",
"$$3 :",
"for_statement : FOR IDENT $$3 ASSIGN expression TO expression DO statement",
"proc_call_statement : proc_call_name",
"proc_call_name : IDENT",
"block_statement : SBEGIN statement_list SEND",
"$$4 :",
"read_statement : READ LPAREN IDENT $$4 RPAREN",
"write_statement : WRITE LPAREN expression RPAREN",
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
#line 173 "parser.y"
 
yyerror(char *s)
{
  fprintf(stderr, "%s in line %d,token %s\n", s,yylineno,yytext);
}
#line 380 "y.tab.c"

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
#line 43 "parser.y"
	{printf("program is inputted.\n");}
break;
case 2:
#line 43 "parser.y"
	{flag = GLOBAL_VAR;}
break;
case 16:
#line 77 "parser.y"
	{flag = LOCAL_VAR; insert(yystack.l_mark[0].ident,PROC_NAME);}
break;
case 29:
#line 99 "parser.y"
	{lookup(yystack.l_mark[-2].ident);}
break;
case 34:
#line 112 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 37:
#line 118 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 38:
#line 121 "parser.y"
	{delete();flag = GLOBAL_VAR;}
break;
case 39:
#line 124 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 60:
#line 160 "parser.y"
	{lookup(yystack.l_mark[0].ident);}
break;
case 63:
#line 167 "parser.y"
	{insert(yystack.l_mark[0].ident,flag);}
break;
case 64:
#line 168 "parser.y"
	{insert(yystack.l_mark[0].ident,flag);}
break;
#line 630 "y.tab.c"
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
