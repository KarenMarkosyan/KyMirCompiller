
/*  A Bison parser, made from simple.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	CELVAL	258
#define	VESHVAL	259
#define	ID	260
#define	NOTEQ	261
#define	ASSIGN	262
#define	POW	263
#define	NEWLINE	264
#define	VIBOR	265
#define	PRI	266
#define	NZ	267
#define	KZ	268
#define	KZ_PRI	269
#define	IF	270
#define	ELSE	271
#define	THEN	272
#define	OT	273
#define	DO	274
#define	VSE	275
#define	DLYA	276
#define	SHAG	277
#define	POKA	278
#define	RAZ	279
#define	DA	280
#define	NET	281
#define	OR	282
#define	AND	283
#define	ALG	284
#define	NACH	285
#define	KON	286
#define	TYPE	287
#define	FUNCPREF	288
#define	ARGTYPE	289
#define	NS	290
#define	VVOD	291
#define	VIVOD	292
#define	ZNACH	293
#define	NE	294
#define	UTV	295
#define	VIHOD	296
#define	QUOTE1	297
#define	QUOTE2	298
#define	TRASH	299
#define	LESSEQ	300
#define	MOREEQ	301
#define	UMINUS	302

#line 1 "simple.y"

#include "functions.h"
#include "tree_print.h"
void yyerror(char const *s);
extern int yylex(void);
struct ProgramInfo * CreateProgram (struct StmtListInfo * prefix, struct PrefListInfo * funcpreflist, struct StmtListInfo * stmtlist, struct FuncListInfo * functions);
struct FuncListInfo * CreateFunctionList (int type, char * funcname, struct ArgListInfo * arglist, struct PrefListInfo * funcpreflist, struct StmtListInfo * stmtlist, struct FuncListInfo * prev);
struct StmtListInfo * CreateStatementList (struct StmtInfo * stmt, struct StmtListInfo * stmtlist);
struct StmtInfo * CreateFromExprStatement (enum StmtType type, struct ExprInfo * expr);
struct StmtInfo * CreateFromIfStatement (enum StmtType type, struct IfStmtInfo * ifstmt);
struct StmtInfo * CreateFromLoopStatement (enum StmtType type, struct LoopStmtInfo * loopstmt);
struct StmtInfo * CreateFromSwitchStatement (enum StmtType type, struct SwitchStmtInfo * switchstmt);
struct StmtInfo * CreateFromTypeListStatement (enum StmtType type, int vartype, struct IdListInfo * idlist);
struct StmtInfo * CreateFromFuncCallStatement (enum StmtType type, char * id, struct ExprListInfo * exprlist);
struct StmtInfo * CreateFromInOutStatement (enum StmtType type, struct ExprListInfo * exprlist, struct IdListInfo * idlist);
struct IfStmtInfo * CreateIfStatement (struct ExprInfo * expr, struct StmtListInfo * stmtlist, struct StmtListInfo * elsestmtlist);
struct SwitchStmtInfo * CreateSwitchStatement (struct SwitchLinesInfo * lines, struct StmtListInfo * stmtlist);
struct SwitchLinesInfo * CreateSwitchLines (struct ExprInfo * expr, struct StmtListInfo * stmtlist, struct SwitchLinesInfo * prev);
struct LoopStmtInfo * CreateLoopStatement (enum LoopType type, char * var, int from, int to, int shag, struct ExprInfo * expr, struct StmtListInfo * stmtlist);
struct ExprInfo * CreateCompExpression (enum ExprType type, struct ExprInfo * left, struct ExprInfo * right);
struct ExprInfo * CreateSimpleExpression (enum ExprType type, int a, float b, char * c, struct ExprInfo * expr, struct ExprListInfo * exprlist);
struct ExprListInfo * CreateExpressionList (struct ExprInfo * expr, struct ExprListInfo * exprlist);
struct IdListInfo * CreateIdList (int val, char * id, struct IdListInfo * prev);
struct ArgListEInfo * CreateArgListE (int argtype, int vartype, char * id, int arrind, struct ArgListEInfo * prev);
struct ArgListInfo * CreateArgList(struct ArgListEInfo * ale);
struct PrefListEInfo * CreatePrefListE (int type, struct ExprInfo * expr, struct PrefListEInfo * prev);
struct PrefListInfo * CreatePrefList (struct PrefListEInfo * ple);

#line 29 "simple.y"
typedef union {
	int int_const;
	float float_const;
	char* str;
	char* id;

	struct ProgramInfo * prog;
	struct FuncListInfo * funclist;
	struct ExprInfo * exp;
	struct ExprListInfo * explst;
	struct IdListInfo * idlst;
	struct StmtInfo * stm;
	struct StmtListInfo * stmlst;
	struct PrefListEInfo * prflste;
	struct PrefListInfo * prflst;
	struct IfStmtInfo * ifstm;
	struct SwitchStmtInfo * swstm;
	struct SwitchLinesInfo * swln;
	struct LoopStmtInfo * lpstm;
	struct ArgListEInfo * arglste;
	struct ArgListInfo * arglst;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#ifndef YYDEBUG
#define YYDEBUG 1
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		231
#define	YYFLAG		-32768
#define	YYNTBASE	62

#define YYTRANSLATE(x) ((unsigned)(x) <= 302 ? yytranslate[x] : 77)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    57,
    58,    52,    51,    61,    50,     2,    53,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,    60,    59,    45,
    47,    46,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
    55,     2,    56,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42,    43,    44,    48,
    49,    54
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,    10,    19,    30,    40,    53,    67,    81,    96,    98,
   101,   104,   107,   110,   113,   117,   121,   125,   131,   139,
   143,   149,   154,   160,   170,   182,   186,   191,   198,   204,
   208,   212,   216,   220,   223,   227,   231,   235,   239,   243,
   245,   247,   249,   253,   257,   261,   265,   269,   273,   280,
   282,   284,   289,   291,   296,   300,   302,   306,   308,   313,
   317,   324,   325,   327,   331,   338,   341,   347,   353,   362,
   367,   375,   376,   378,   381,   385,   388
};

static const short yyrhs[] = {    64,
    29,    59,    75,    30,    59,    64,    31,    59,     0,    29,
    59,    75,    30,    59,    64,    31,    59,     0,    64,    29,
    59,    75,    30,    59,    64,    31,    59,    63,     0,    29,
    59,    75,    30,    59,    64,    31,    59,    63,     0,    29,
     5,    57,    73,    58,    59,    75,    30,    59,    64,    31,
    59,     0,    32,    29,     5,    57,    73,    58,    59,    75,
    30,    59,    64,    31,    59,     0,    63,    29,     5,    57,
    73,    58,    59,    75,    30,    59,    64,    31,    59,     0,
    63,    32,    29,     5,    57,    73,    58,    59,    75,    30,
    59,    64,    31,    59,     0,    65,     0,    64,    65,     0,
    70,    59,     0,    66,    59,     0,    69,    59,     0,    67,
    59,     0,    32,    72,    59,     0,    36,    72,    59,     0,
    37,    71,    59,     0,    15,    70,    17,    64,    20,     0,
    15,    70,    17,    64,    16,    64,    20,     0,    10,    68,
    20,     0,    10,    68,    16,    64,    20,     0,    11,    70,
    60,    64,     0,    68,    11,    70,    60,    64,     0,    12,
    21,     5,    18,     3,    19,     3,    64,    13,     0,    12,
    21,     5,    18,     3,    19,     3,    22,     3,    64,    13,
     0,    12,    64,    13,     0,    12,    64,    14,    70,     0,
    12,    23,    70,    59,    64,    13,     0,    12,     3,    24,
    64,    13,     0,    70,    51,    70,     0,    70,    50,    70,
     0,    70,    52,    70,     0,    70,    53,    70,     0,    50,
    70,     0,    70,     8,    70,     0,    57,    70,    58,     0,
    70,     6,    70,     0,    70,    27,    70,     0,    70,    28,
    70,     0,    25,     0,    26,     0,    35,     0,    70,    46,
    70,     0,    70,    45,    70,     0,    70,    48,    70,     0,
    70,    49,    70,     0,    70,    47,    70,     0,     5,     7,
    70,     0,     5,    55,     3,    56,     7,    70,     0,     3,
     0,     4,     0,     5,    55,     3,    56,     0,     5,     0,
     5,    57,    71,    58,     0,     5,    57,    58,     0,    70,
     0,    71,    61,    70,     0,     5,     0,     5,    55,     3,
    56,     0,    72,    61,     5,     0,    72,    61,     5,    55,
     3,    56,     0,     0,    74,     0,    34,    32,     5,     0,
    34,    32,     5,    55,     3,    56,     0,    32,     5,     0,
    32,     5,    55,     3,    56,     0,    74,    61,    34,    32,
     5,     0,    74,    61,    34,    32,     5,    55,     3,    56,
     0,    74,    61,    32,     5,     0,    74,    61,    32,     5,
    55,     3,    56,     0,     0,    76,     0,    33,    59,     0,
    33,    70,    59,     0,    76,    33,     0,    76,    33,    70,
    59,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
   124,   126,   127,   128,   131,   133,   134,   135,   138,   140,
   143,   145,   146,   147,   148,   149,   150,   153,   155,   158,
   160,   163,   165,   168,   170,   171,   172,   173,   174,   177,
   179,   180,   181,   182,   183,   184,   185,   186,   187,   188,
   189,   190,   191,   192,   193,   194,   195,   196,   197,   198,
   199,   200,   201,   202,   203,   206,   208,   211,   213,   214,
   215,   218,   220,   223,   225,   226,   227,   228,   229,   230,
   231,   234,   236,   239,   241,   242,   243
};

static const char * const yytname[] = {   "$","error","$undefined.","CELVAL",
"VESHVAL","ID","NOTEQ","ASSIGN","POW","NEWLINE","VIBOR","PRI","NZ","KZ","KZ_PRI",
"IF","ELSE","THEN","OT","DO","VSE","DLYA","SHAG","POKA","RAZ","DA","NET","OR",
"AND","ALG","NACH","KON","TYPE","FUNCPREF","ARGTYPE","NS","VVOD","VIVOD","ZNACH",
"NE","UTV","VIHOD","QUOTE1","QUOTE2","TRASH","'<'","'>'","'='","LESSEQ","MOREEQ",
"'-'","'+'","'*'","'/'","UMINUS","'['","']'","'('","')'","';'","':'","','","program",
"func_list","stmt_list","stmt","if_stmt","switch_stmt","switch_lines","loop_stmt",
"expr","expr_list","id_list","arg_list","arg_listE","func_pref_list","func_pref_listE",
""
};
#endif

static const short yyr1[] = {     0,
    62,    62,    62,    62,    63,    63,    63,    63,    64,    64,
    65,    65,    65,    65,    65,    65,    65,    66,    66,    67,
    67,    68,    68,    69,    69,    69,    69,    69,    69,    70,
    70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
    70,    70,    70,    70,    70,    71,    71,    72,    72,    72,
    72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
    74,    75,    75,    76,    76,    76,    76
};

static const short yyr2[] = {     0,
     9,     8,    10,     9,    12,    13,    13,    14,     1,     2,
     2,     2,     2,     2,     3,     3,     3,     5,     7,     3,
     5,     4,     5,     9,    11,     3,     4,     6,     5,     3,
     3,     3,     3,     2,     3,     3,     3,     3,     3,     1,
     1,     1,     3,     3,     3,     3,     3,     3,     6,     1,
     1,     4,     1,     4,     3,     1,     3,     1,     4,     3,
     6,     0,     1,     3,     6,     2,     5,     5,     8,     4,
     7,     0,     1,     2,     3,     2,     4
};

static const short yydefact[] = {     0,
    50,    51,    53,     0,     0,     0,    40,    41,     0,     0,
    42,     0,     0,     0,     0,     0,     9,     0,     0,     0,
     0,     0,     0,     0,     0,     0,    50,     0,     0,     0,
     0,    72,    58,     0,     0,    56,     0,    34,     0,     0,
    10,    12,    14,    13,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    11,    48,     0,
    55,     0,     0,     0,     0,    20,     0,     0,     0,    26,
     0,     0,     0,     0,    73,     0,    15,     0,    16,    17,
     0,    36,    72,    37,    35,    38,    39,    44,    43,    47,
    45,    46,    31,    30,    32,    33,    52,    54,     0,     0,
     0,     0,     0,     0,    27,     0,    74,     0,     0,    76,
     0,    60,    57,     0,     0,    22,     0,    21,    29,     0,
     0,     0,    18,    75,     0,     0,    59,     0,     0,    49,
    23,     0,    28,     0,     0,    77,     0,     0,     0,    19,
     0,    61,     0,     0,     0,     2,     0,     0,    24,     0,
     0,     4,     1,     0,     0,     0,     0,     0,     3,    25,
    62,     0,     0,     0,     0,     0,     0,    63,    62,    62,
     0,    66,     0,     0,     0,     0,     0,    62,     0,    64,
    72,     0,     0,     0,     0,     0,     0,     0,     0,    70,
     0,    72,    72,     0,    67,     0,     0,     0,    68,     0,
     0,    72,    65,     0,     0,     0,     0,     0,     0,     0,
    71,     0,     0,     0,     0,     0,    69,     0,     0,     0,
     5,     0,     0,     0,     6,     7,     0,     8,     0,     0,
     0
};

static const short yydefgoto[] = {   229,
   152,    16,    17,    18,    19,    26,    20,    21,    37,    34,
   167,   168,    74,    75
};

static const short yypact[] = {   243,
-32768,-32768,    19,   -10,   132,   124,-32768,-32768,   -47,    11,
-32768,    11,   124,   124,   124,   279,-32768,   -40,   -39,   -36,
   810,   124,    30,    81,   124,    -9,    20,    64,   124,   188,
   936,    10,    32,   -27,   -20,   921,   -19,-32768,   888,    16,
-32768,-32768,-32768,-32768,   124,   124,   124,   124,   124,   124,
   124,   124,   124,   124,   124,   124,   124,-32768,   921,    26,
-32768,   -53,   744,   124,   773,-32768,   773,    73,   825,-32768,
   124,   773,    33,    65,    63,    94,-32768,    93,-32768,-32768,
   124,-32768,    10,    27,-32768,   948,   969,    27,    27,    27,
    27,    27,    13,    13,    92,    92,    97,-32768,   773,   794,
   315,   351,    98,   773,   921,   224,-32768,   858,    46,   124,
    53,    56,   921,    89,   124,   773,   773,-32768,-32768,   105,
   387,   773,-32768,-32768,   773,   873,-32768,   122,    67,   921,
   773,   137,-32768,   406,   442,-32768,    90,   773,   478,-32768,
    86,-32768,   514,   145,   550,    -2,    95,   773,-32768,   146,
   123,    -1,    -2,   586,    99,   155,   156,   133,    -1,-32768,
    29,   106,   108,   161,   165,   139,   114,   112,    29,    29,
   118,   121,   172,   119,    38,   125,   126,    29,   176,   130,
    10,   175,   154,   128,   129,   136,   134,   192,   166,   149,
   202,    10,    10,   151,-32768,   160,   153,   214,   163,   189,
   191,    10,-32768,   773,   170,   219,   171,   173,   201,   622,
-32768,   177,   773,   773,   178,   182,-32768,   658,   694,   773,
-32768,   183,   184,   730,-32768,-32768,   193,-32768,   235,   251,
-32768
};

static const short yypgoto[] = {-32768,
   101,    -5,   -13,-32768,-32768,-32768,-32768,     0,   233,   250,
  -160,-32768,   -79,-32768
};


#define	YYLAST		1022


static const short yytable[] = {    30,
    25,    64,    41,   114,    98,    31,    65,    81,   176,   177,
    66,    32,    36,    38,    39,    33,    41,   186,    42,    43,
    46,    59,    44,    36,    63,    22,   150,   157,    69,   151,
   158,    77,    60,    78,    46,     1,     2,     3,    79,    80,
    78,    81,    73,    67,    84,    85,    86,    87,    88,    89,
    90,    91,    92,    93,    94,    95,    96,     7,     8,   101,
   165,   102,   166,   100,    56,    57,   106,    11,    68,   182,
   105,   183,   108,    23,    83,    24,    54,    55,    56,    57,
   113,    97,    14,     1,     2,     3,    76,    41,    41,    15,
   103,   107,    41,   116,   109,   110,   111,   112,   121,    46,
   120,   189,    41,   115,   125,     7,     8,    41,   127,   126,
   128,   131,   200,   201,   130,    11,   134,    41,   129,   135,
    41,    41,   209,   132,   137,   138,     1,     2,     3,    41,
    14,    41,   143,   145,    27,     2,     3,    15,    61,   139,
    41,     4,   154,     5,   146,   142,     6,   148,     7,     8,
   155,   156,    28,   153,    29,   161,     7,     8,    11,   162,
   163,   164,   169,    10,   170,   171,    11,    12,    13,   172,
   173,   174,   175,    14,   178,   179,   180,   181,   187,   190,
    15,    14,   184,   185,   188,   191,   192,   193,    15,   195,
     1,     2,     3,   194,   196,   197,    41,     4,   210,     5,
    70,    71,     6,   198,    41,    41,   199,   218,   219,   202,
    41,   204,     7,     8,   224,   203,   205,   206,   207,    10,
   208,   212,    11,    12,    13,   211,     1,     2,     3,   213,
   215,   214,   217,     4,   230,     5,   220,    14,     6,   122,
   221,   225,   226,   123,    15,     1,     2,     3,     7,     8,
   231,   228,     4,   159,     5,    10,    62,     6,    11,    12,
    13,    35,     0,     0,     0,     0,     0,     7,     8,     0,
     0,     9,     0,    14,    10,     0,     0,    11,    12,    13,
    15,     1,     2,     3,     0,     0,     0,     0,     4,     0,
     5,     0,    14,     6,     0,     0,     0,     0,     0,    15,
     0,     0,     0,     7,     8,     0,     0,    40,     0,     0,
    10,     0,     0,    11,    12,    13,     0,     1,     2,     3,
     0,     0,     0,     0,     4,     0,     5,     0,    14,     6,
     0,     0,     0,     0,   118,    15,     0,     0,     0,     7,
     8,     0,     0,     0,     0,     0,    10,     0,     0,    11,
    12,    13,     0,     1,     2,     3,     0,     0,     0,     0,
     4,     0,     5,   119,    14,     6,     0,     0,     0,     0,
     0,    15,     0,     0,     0,     7,     8,     0,     0,     0,
     0,     0,    10,     0,     0,    11,    12,    13,     0,     1,
     2,     3,     0,     0,     0,     0,     4,     0,     5,   133,
    14,     6,     0,     0,     0,     0,     0,    15,     1,     2,
     3,     7,     8,     0,     0,     4,     0,     5,    10,     0,
     6,    11,    12,    13,     0,   140,     0,     0,     0,     0,
     7,     8,     0,     0,     0,     0,    14,    10,     0,     0,
    11,    12,    13,    15,     1,     2,     3,     0,     0,     0,
     0,     4,     0,     5,     0,    14,     6,     0,     0,     0,
     0,     0,    15,     0,     0,     0,     7,     8,     0,     0,
     0,     0,   141,    10,     0,     0,    11,    12,    13,     0,
     1,     2,     3,     0,     0,     0,     0,     4,     0,     5,
     0,    14,     6,     0,     0,     0,     0,     0,    15,   144,
     0,     0,     7,     8,     0,     0,     0,     0,     0,    10,
     0,     0,    11,    12,    13,     0,     1,     2,     3,     0,
     0,     0,     0,     4,     0,     5,     0,    14,     6,     0,
     0,     0,     0,     0,    15,     0,     0,     0,     7,     8,
     0,     0,     0,     0,   147,    10,     0,     0,    11,    12,
    13,     0,     1,     2,     3,     0,     0,     0,     0,     4,
     0,     5,   149,    14,     6,     0,     0,     0,     0,     0,
    15,     0,     0,     0,     7,     8,     0,     0,     0,     0,
     0,    10,     0,     0,    11,    12,    13,     0,     1,     2,
     3,     0,     0,     0,     0,     4,     0,     5,   160,    14,
     6,     0,     0,     0,     0,     0,    15,     0,     0,     0,
     7,     8,     0,     0,     0,     0,     0,    10,     0,     0,
    11,    12,    13,     0,     1,     2,     3,     0,     0,     0,
     0,     4,     0,     5,     0,    14,     6,     0,     0,     0,
     0,     0,    15,     0,     0,     0,     7,     8,     0,     0,
     0,     0,   216,    10,     0,     0,    11,    12,    13,     0,
     1,     2,     3,     0,     0,     0,     0,     4,     0,     5,
     0,    14,     6,     0,     0,     0,     0,     0,    15,     0,
     0,     0,     7,     8,     0,     0,     0,     0,   222,    10,
     0,     0,    11,    12,    13,     0,     1,     2,     3,     0,
     0,     0,     0,     4,     0,     5,     0,    14,     6,     0,
     0,     0,     0,     0,    15,     0,     0,     0,     7,     8,
     0,     0,     0,     0,   223,    10,     0,     0,    11,    12,
    13,     0,     1,     2,     3,     0,     0,     0,     0,     4,
     0,     5,     0,    14,     6,     0,     0,     0,     0,    45,
    15,    46,     0,     0,     7,     8,     0,     0,     0,     0,
   227,    10,     0,     0,    11,    12,    13,     0,     0,     0,
    47,    48,     0,     0,     0,     1,     2,     3,     0,    14,
     0,     0,     4,     0,     5,     0,    15,     6,    49,    50,
    51,    52,    53,    54,    55,    56,    57,     7,     8,    45,
     0,    46,     0,    99,    10,     0,     0,    11,    12,    13,
     0,     0,     0,     0,     0,    45,     0,    46,     0,     0,
    47,    48,    14,     0,     0,     0,     0,     0,     0,    15,
    45,     0,    46,     0,     0,     0,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,     0,     0,     0,
     0,    47,    48,   117,    49,    50,    51,    52,    53,    54,
    55,    56,    57,    45,     0,    46,     0,     0,    58,    49,
    50,    51,    52,    53,    54,    55,    56,    57,    45,     0,
    46,     0,     0,   104,    47,    48,     0,     0,     0,     0,
     0,     0,     0,    45,     0,    46,     0,     0,     0,    47,
    48,     0,    49,    50,    51,    52,    53,    54,    55,    56,
    57,     0,     0,     0,    47,    48,   124,    49,    50,    51,
    52,    53,    54,    55,    56,    57,    45,     0,    46,     0,
     0,   136,    49,    50,    51,    52,    53,    54,    55,    56,
    57,    45,     0,    46,     0,    82,     0,    47,    48,     0,
     0,     0,    72,    45,     0,    46,     0,     0,     0,     0,
     0,     0,    47,    48,     0,    49,    50,    51,    52,    53,
    54,    55,    56,    57,    45,    48,    46,     0,     0,     0,
    49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
     0,     0,    49,    50,    51,    52,    53,    54,    55,    56,
    57,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,    49,    50,    51,    52,    53,    54,    55,
    56,    57
};

static const short yycheck[] = {     5,
    11,    11,    16,    83,    58,     6,    16,    61,   169,   170,
    20,    59,    13,    14,    15,     5,    30,   178,    59,    59,
     8,    22,    59,    24,    25,     7,    29,    29,    29,    32,
    32,    59,     3,    61,     8,     3,     4,     5,    59,    59,
    61,    61,    33,    24,    45,    46,    47,    48,    49,    50,
    51,    52,    53,    54,    55,    56,    57,    25,    26,    65,
    32,    67,    34,    64,    52,    53,    72,    35,     5,    32,
    71,    34,    73,    55,    59,    57,    50,    51,    52,    53,
    81,    56,    50,     3,     4,     5,    55,   101,   102,    57,
    18,    59,   106,    99,    30,    33,     3,     5,   104,     8,
     3,   181,   116,     7,    59,    25,    26,   121,    56,   110,
    55,   117,   192,   193,   115,    35,   122,   131,    30,   125,
   134,   135,   202,    19,     3,    59,     3,     4,     5,   143,
    50,   145,   138,   139,     3,     4,     5,    57,    58,     3,
   154,    10,   148,    12,    59,    56,    15,     3,    25,    26,
     5,    29,    21,    59,    23,    57,    25,    26,    35,     5,
     5,    29,    57,    32,    57,     5,    35,    36,    37,     5,
    32,    58,    61,    50,    57,    55,     5,    59,     3,     5,
    57,    50,    58,    58,    55,    32,    59,    59,    57,    56,
     3,     4,     5,    58,     3,    30,   210,    10,   204,    12,
    13,    14,    15,    55,   218,   219,     5,   213,   214,    59,
   224,    59,    25,    26,   220,    56,     3,    55,    30,    32,
    30,     3,    35,    36,    37,    56,     3,     4,     5,    59,
    30,    59,    56,    10,     0,    12,    59,    50,    15,    16,
    59,    59,    59,    20,    57,     3,     4,     5,    25,    26,
     0,    59,    10,   153,    12,    32,    24,    15,    35,    36,
    37,    12,    -1,    -1,    -1,    -1,    -1,    25,    26,    -1,
    -1,    29,    -1,    50,    32,    -1,    -1,    35,    36,    37,
    57,     3,     4,     5,    -1,    -1,    -1,    -1,    10,    -1,
    12,    -1,    50,    15,    -1,    -1,    -1,    -1,    -1,    57,
    -1,    -1,    -1,    25,    26,    -1,    -1,    29,    -1,    -1,
    32,    -1,    -1,    35,    36,    37,    -1,     3,     4,     5,
    -1,    -1,    -1,    -1,    10,    -1,    12,    -1,    50,    15,
    -1,    -1,    -1,    -1,    20,    57,    -1,    -1,    -1,    25,
    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,    35,
    36,    37,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,
    10,    -1,    12,    13,    50,    15,    -1,    -1,    -1,    -1,
    -1,    57,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,
    -1,    -1,    32,    -1,    -1,    35,    36,    37,    -1,     3,
     4,     5,    -1,    -1,    -1,    -1,    10,    -1,    12,    13,
    50,    15,    -1,    -1,    -1,    -1,    -1,    57,     3,     4,
     5,    25,    26,    -1,    -1,    10,    -1,    12,    32,    -1,
    15,    35,    36,    37,    -1,    20,    -1,    -1,    -1,    -1,
    25,    26,    -1,    -1,    -1,    -1,    50,    32,    -1,    -1,
    35,    36,    37,    57,     3,     4,     5,    -1,    -1,    -1,
    -1,    10,    -1,    12,    -1,    50,    15,    -1,    -1,    -1,
    -1,    -1,    57,    -1,    -1,    -1,    25,    26,    -1,    -1,
    -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,
     3,     4,     5,    -1,    -1,    -1,    -1,    10,    -1,    12,
    -1,    50,    15,    -1,    -1,    -1,    -1,    -1,    57,    22,
    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,
    -1,    -1,    35,    36,    37,    -1,     3,     4,     5,    -1,
    -1,    -1,    -1,    10,    -1,    12,    -1,    50,    15,    -1,
    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    25,    26,
    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
    37,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
    -1,    12,    13,    50,    15,    -1,    -1,    -1,    -1,    -1,
    57,    -1,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
    -1,    32,    -1,    -1,    35,    36,    37,    -1,     3,     4,
     5,    -1,    -1,    -1,    -1,    10,    -1,    12,    13,    50,
    15,    -1,    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,
    25,    26,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
    35,    36,    37,    -1,     3,     4,     5,    -1,    -1,    -1,
    -1,    10,    -1,    12,    -1,    50,    15,    -1,    -1,    -1,
    -1,    -1,    57,    -1,    -1,    -1,    25,    26,    -1,    -1,
    -1,    -1,    31,    32,    -1,    -1,    35,    36,    37,    -1,
     3,     4,     5,    -1,    -1,    -1,    -1,    10,    -1,    12,
    -1,    50,    15,    -1,    -1,    -1,    -1,    -1,    57,    -1,
    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,    31,    32,
    -1,    -1,    35,    36,    37,    -1,     3,     4,     5,    -1,
    -1,    -1,    -1,    10,    -1,    12,    -1,    50,    15,    -1,
    -1,    -1,    -1,    -1,    57,    -1,    -1,    -1,    25,    26,
    -1,    -1,    -1,    -1,    31,    32,    -1,    -1,    35,    36,
    37,    -1,     3,     4,     5,    -1,    -1,    -1,    -1,    10,
    -1,    12,    -1,    50,    15,    -1,    -1,    -1,    -1,     6,
    57,     8,    -1,    -1,    25,    26,    -1,    -1,    -1,    -1,
    31,    32,    -1,    -1,    35,    36,    37,    -1,    -1,    -1,
    27,    28,    -1,    -1,    -1,     3,     4,     5,    -1,    50,
    -1,    -1,    10,    -1,    12,    -1,    57,    15,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    25,    26,     6,
    -1,     8,    -1,    60,    32,    -1,    -1,    35,    36,    37,
    -1,    -1,    -1,    -1,    -1,     6,    -1,     8,    -1,    -1,
    27,    28,    50,    -1,    -1,    -1,    -1,    -1,    -1,    57,
     6,    -1,     8,    -1,    -1,    -1,    27,    28,    45,    46,
    47,    48,    49,    50,    51,    52,    53,    -1,    -1,    -1,
    -1,    27,    28,    60,    45,    46,    47,    48,    49,    50,
    51,    52,    53,     6,    -1,     8,    -1,    -1,    59,    45,
    46,    47,    48,    49,    50,    51,    52,    53,     6,    -1,
     8,    -1,    -1,    59,    27,    28,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,     6,    -1,     8,    -1,    -1,    -1,    27,
    28,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    -1,    -1,    -1,    27,    28,    59,    45,    46,    47,
    48,    49,    50,    51,    52,    53,     6,    -1,     8,    -1,
    -1,    59,    45,    46,    47,    48,    49,    50,    51,    52,
    53,     6,    -1,     8,    -1,    58,    -1,    27,    28,    -1,
    -1,    -1,    17,     6,    -1,     8,    -1,    -1,    -1,    -1,
    -1,    -1,    27,    28,    -1,    45,    46,    47,    48,    49,
    50,    51,    52,    53,     6,    28,     8,    -1,    -1,    -1,
    45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
    -1,    -1,    45,    46,    47,    48,    49,    50,    51,    52,
    53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
    52,    53
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 125 "simple.y"
{ yyval.prog = CreateProgram(yyvsp[-8].stmlst, yyvsp[-5].prflst, yyvsp[-2].stmlst, NULL); print(yyval.prog); ;
    break;}
case 2:
#line 126 "simple.y"
{ yyval.prog = CreateProgram(NULL, yyvsp[-5].prflst, yyvsp[-2].stmlst, NULL);  print(yyval.prog); ;
    break;}
case 3:
#line 127 "simple.y"
{ yyval.prog = CreateProgram(yyvsp[-9].stmlst, yyvsp[-6].prflst, yyvsp[-3].stmlst, yyvsp[0].funclist);  print(yyval.prog); ;
    break;}
case 4:
#line 128 "simple.y"
{ yyval.prog = CreateProgram(NULL, yyvsp[-6].prflst, yyvsp[-3].stmlst, yyvsp[0].funclist);  print(yyval.prog); ;
    break;}
case 5:
#line 132 "simple.y"
{ yyval.funclist = CreateFunctionList(-1, yyvsp[-10].id, yyvsp[-8].arglst, yyvsp[-5].prflst, yyvsp[-2].stmlst, NULL); ;
    break;}
case 6:
#line 133 "simple.y"
{ yyval.funclist = CreateFunctionList(yyvsp[-12].int_const, yyvsp[-10].id, yyvsp[-8].arglst, yyvsp[-5].prflst, yyvsp[-2].stmlst, NULL); ;
    break;}
case 7:
#line 134 "simple.y"
{ yyval.funclist = CreateFunctionList(-1, yyvsp[-10].id, yyvsp[-8].arglst, yyvsp[-5].prflst, yyvsp[-2].stmlst, yyvsp[-12].funclist); ;
    break;}
case 8:
#line 135 "simple.y"
{ yyval.funclist = CreateFunctionList(yyvsp[-12].int_const, yyvsp[-10].id, yyvsp[-8].arglst, yyvsp[-5].prflst, yyvsp[-2].stmlst, yyvsp[-13].funclist); ;
    break;}
case 9:
#line 139 "simple.y"
{ yyval.stmlst = CreateStatementList(yyvsp[0].stm, NULL); ;
    break;}
case 10:
#line 140 "simple.y"
{ yyval.stmlst = CreateStatementList(yyvsp[0].stm, yyvsp[-1].stmlst); ;
    break;}
case 11:
#line 144 "simple.y"
{ yyval.stm = CreateFromExprStatement(__EXPR, yyvsp[-1].exp); ;
    break;}
case 12:
#line 145 "simple.y"
{ yyval.stm = CreateFromIfStatement(__IF, yyvsp[-1].ifstm); ;
    break;}
case 13:
#line 146 "simple.y"
{ yyval.stm = CreateFromLoopStatement(__LOOP, yyvsp[-1].lpstm); ;
    break;}
case 14:
#line 147 "simple.y"
{ yyval.stm = CreateFromSwitchStatement(__SWITCH, yyvsp[-1].swstm); ;
    break;}
case 15:
#line 148 "simple.y"
{ yyval.stm = CreateFromTypeListStatement(__TYPE, yyvsp[-2].int_const, yyvsp[-1].idlst); ;
    break;}
case 16:
#line 149 "simple.y"
{ yyval.stm = CreateFromInOutStatement(__VVOD, NULL, yyvsp[-1].idlst); ;
    break;}
case 17:
#line 150 "simple.y"
{ yyval.stm = CreateFromInOutStatement(__VIVOD, yyvsp[-1].explst, NULL); ;
    break;}
case 18:
#line 154 "simple.y"
{ yyval.ifstm = CreateIfStatement(yyvsp[-3].exp, yyvsp[-1].stmlst, NULL); ;
    break;}
case 19:
#line 155 "simple.y"
{ yyval.ifstm = CreateIfStatement(yyvsp[-5].exp, yyvsp[-3].stmlst, yyvsp[-1].stmlst); ;
    break;}
case 20:
#line 159 "simple.y"
{ yyval.swstm = CreateSwitchStatement(yyvsp[-1].swln, NULL); ;
    break;}
case 21:
#line 160 "simple.y"
{ yyval.swstm = CreateSwitchStatement(yyvsp[-3].swln, yyvsp[-1].stmlst); ;
    break;}
case 22:
#line 164 "simple.y"
{ yyval.swln = CreateSwitchLines(yyvsp[-2].exp, yyvsp[0].stmlst, NULL); ;
    break;}
case 23:
#line 165 "simple.y"
{ yyval.swln = CreateSwitchLines(yyvsp[-2].exp, yyvsp[0].stmlst, yyvsp[-4].swln); ;
    break;}
case 24:
#line 169 "simple.y"
{ yyval.lpstm = CreateLoopStatement(__DLYA, yyvsp[-6].id, yyvsp[-4].int_const, yyvsp[-2].int_const, 1, NULL, yyvsp[-1].stmlst); ;
    break;}
case 25:
#line 170 "simple.y"
{ yyval.lpstm = CreateLoopStatement(__DLYASHAG, yyvsp[-8].id, yyvsp[-6].int_const, yyvsp[-4].int_const, yyvsp[-2].int_const, NULL, yyvsp[-1].stmlst); ;
    break;}
case 26:
#line 171 "simple.y"
{ yyval.lpstm = CreateLoopStatement(__PROST, NULL, -1, -1, -1, NULL, yyvsp[-1].stmlst); ;
    break;}
case 27:
#line 172 "simple.y"
{ yyval.lpstm = CreateLoopStatement(__PRI, NULL, -1, -1, -1, yyvsp[0].exp, yyvsp[-2].stmlst); ;
    break;}
case 28:
#line 173 "simple.y"
{ yyval.lpstm = CreateLoopStatement(__POKA, NULL, -1, -1, -1, yyvsp[-3].exp, yyvsp[-1].stmlst); ;
    break;}
case 29:
#line 174 "simple.y"
{ yyval.lpstm = CreateLoopStatement(__RAZ, NULL, 0, yyvsp[-3].int_const, -1, NULL, yyvsp[-1].stmlst); ;
    break;}
case 30:
#line 178 "simple.y"
{ yyval.exp = CreateCompExpression(_ADD, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 31:
#line 179 "simple.y"
{ yyval.exp = CreateCompExpression(_SUB, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 32:
#line 180 "simple.y"
{ yyval.exp = CreateCompExpression(_MUL, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 33:
#line 181 "simple.y"
{ yyval.exp = CreateCompExpression(_DIV, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 34:
#line 182 "simple.y"
{ yyval.exp = CreateCompExpression(_UNARSUB, yyvsp[0].exp, NULL); ;
    break;}
case 35:
#line 183 "simple.y"
{ yyval.exp = CreateCompExpression(_POW, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 36:
#line 184 "simple.y"
{ yyval.exp = yyvsp[-1].exp; ;
    break;}
case 37:
#line 185 "simple.y"
{ yyval.exp = CreateCompExpression(_NOTEQ, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 38:
#line 186 "simple.y"
{ yyval.exp = CreateCompExpression(_OR, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 39:
#line 187 "simple.y"
{ yyval.exp = CreateCompExpression(_AND, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 40:
#line 188 "simple.y"
{ yyval.exp = CreateSimpleExpression(_DA, -1, -1, NULL, NULL, NULL); ;
    break;}
case 41:
#line 189 "simple.y"
{ yyval.exp = CreateSimpleExpression(_NET, -1, -1, NULL, NULL, NULL); ;
    break;}
case 42:
#line 190 "simple.y"
{ yyval.exp = CreateSimpleExpression(_NS, -1, -1, NULL, NULL, NULL); ;
    break;}
case 43:
#line 191 "simple.y"
{ yyval.exp = CreateCompExpression(_GREAT, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 44:
#line 192 "simple.y"
{ yyval.exp = CreateCompExpression(_LESS, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 45:
#line 193 "simple.y"
{ yyval.exp = CreateCompExpression(_LESSEQ, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 46:
#line 194 "simple.y"
{ yyval.exp = CreateCompExpression(_GREATEQ, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 47:
#line 195 "simple.y"
{ yyval.exp = CreateCompExpression(_EQ, yyvsp[-2].exp, yyvsp[0].exp); ;
    break;}
case 48:
#line 196 "simple.y"
{ yyval.exp = CreateSimpleExpression(_IDASSIGN, -1, -1, yyvsp[-2].id, yyvsp[0].exp, NULL); ;
    break;}
case 49:
#line 197 "simple.y"
{ yyval.exp = CreateSimpleExpression(_ARRASSIGN, yyvsp[-3].int_const, -1, yyvsp[-5].id, yyvsp[0].exp, NULL); ;
    break;}
case 50:
#line 198 "simple.y"
{ yyval.exp = CreateSimpleExpression(_CELVAL, yyvsp[0].int_const, -1, NULL, NULL, NULL); ;
    break;}
case 51:
#line 199 "simple.y"
{ yyval.exp = CreateSimpleExpression(_VESHVAL, -1, yyvsp[0].float_const, NULL, NULL, NULL); ;
    break;}
case 52:
#line 200 "simple.y"
{ yyval.exp = CreateSimpleExpression(_ARRID, yyvsp[-1].int_const, -1, yyvsp[-3].id, NULL, NULL); ;
    break;}
case 53:
#line 201 "simple.y"
{ yyval.exp = CreateSimpleExpression(_ID, -1, -1, yyvsp[0].id, NULL, NULL); ;
    break;}
case 54:
#line 202 "simple.y"
{ yyval.exp = CreateSimpleExpression(_FUNCCALL, -1, -1, yyvsp[-3].id, NULL, yyvsp[-1].explst); ;
    break;}
case 55:
#line 203 "simple.y"
{ yyval.exp = CreateSimpleExpression(_FUNCCALL, -1, -1, yyvsp[-2].id, NULL, NULL); ;
    break;}
case 56:
#line 207 "simple.y"
{ yyval.explst = CreateExpressionList(yyvsp[0].exp, NULL); ;
    break;}
case 57:
#line 208 "simple.y"
{ yyval.explst = CreateExpressionList(yyvsp[0].exp, yyvsp[-2].explst); ;
    break;}
case 58:
#line 212 "simple.y"
{ yyval.idlst = CreateIdList(-1, yyvsp[0].id, NULL); ;
    break;}
case 59:
#line 213 "simple.y"
{ yyval.idlst = CreateIdList(yyvsp[-1].int_const, yyvsp[-3].id, NULL); ;
    break;}
case 60:
#line 214 "simple.y"
{ yyval.idlst = CreateIdList(-1, yyvsp[0].id, yyvsp[-2].idlst); ;
    break;}
case 61:
#line 215 "simple.y"
{ yyval.idlst = CreateIdList(yyvsp[-1].int_const, yyvsp[-3].id, yyvsp[-5].idlst); ;
    break;}
case 62:
#line 219 "simple.y"
{ yyval.arglst = 0; ;
    break;}
case 63:
#line 220 "simple.y"
{ yyval.arglst = CreateArgList(yyvsp[0].arglste); ;
    break;}
case 64:
#line 224 "simple.y"
{ yyval.arglste = CreateArgListE(yyvsp[-2].int_const, yyvsp[-1].int_const, yyvsp[0].id, -1, NULL); ;
    break;}
case 65:
#line 225 "simple.y"
{ yyval.arglste = CreateArgListE(yyvsp[-5].int_const, yyvsp[-4].int_const, yyvsp[-3].id, yyvsp[-1].int_const, NULL); ;
    break;}
case 66:
#line 226 "simple.y"
{ yyval.arglste = CreateArgListE(-1, yyvsp[-1].int_const, yyvsp[0].id, -1, NULL); ;
    break;}
case 67:
#line 227 "simple.y"
{ yyval.arglste = CreateArgListE(-1, yyvsp[-4].int_const, yyvsp[-3].id, yyvsp[-1].int_const, NULL); ;
    break;}
case 68:
#line 228 "simple.y"
{ yyval.arglste = CreateArgListE(yyvsp[-2].int_const, yyvsp[-1].int_const, yyvsp[0].id, -1, yyvsp[-4].arglste); ;
    break;}
case 69:
#line 229 "simple.y"
{ yyval.arglste = CreateArgListE(yyvsp[-5].int_const, yyvsp[-4].int_const, yyvsp[-3].id, yyvsp[-1].int_const, yyvsp[-7].arglste); ;
    break;}
case 70:
#line 230 "simple.y"
{ yyval.arglste = CreateArgListE(-1, yyvsp[-1].int_const, yyvsp[0].id, -1, yyvsp[-3].arglste); ;
    break;}
case 71:
#line 231 "simple.y"
{ yyval.arglste = CreateArgListE(-1, yyvsp[-4].int_const, yyvsp[-3].id, yyvsp[-1].int_const, yyvsp[-6].arglste); ;
    break;}
case 72:
#line 235 "simple.y"
{ yyval.prflst = 0; ;
    break;}
case 73:
#line 236 "simple.y"
{ yyval.prflst = CreatePrefList(yyvsp[0].prflste); ;
    break;}
case 74:
#line 240 "simple.y"
{ yyval.prflste = CreatePrefListE(yyvsp[-1].int_const, NULL, NULL); ;
    break;}
case 75:
#line 241 "simple.y"
{ yyval.prflste = CreatePrefListE(yyvsp[-2].int_const, yyvsp[-1].exp, NULL); ;
    break;}
case 76:
#line 242 "simple.y"
{ yyval.prflste = CreatePrefListE(yyvsp[0].int_const, NULL, yyvsp[-1].prflste); ;
    break;}
case 77:
#line 243 "simple.y"
{ yyval.prflste = CreatePrefListE(yyvsp[-2].int_const, yyvsp[-1].exp, yyvsp[-3].prflste); ;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}
#line 245 "simple.y"


void yyerror(char const *s)
{
	printf("%s",s);
}