%{
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
%}
%union {
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
}

%type <prog>		program;
%type <funclist>	func_list;
%type <exp>			expr;
%type <explst>		expr_list;
%type <idlst>		id_list;
%type <stm>			stmt;
%type <stmlst>		stmt_list;
%type <prflste>		func_pref_listE;
%type <prflst>		func_pref_list;
%type <ifstm>		if_stmt;
%type <swstm>		switch_stmt;
%type <swln>		switch_lines;
%type <lpstm>		loop_stmt;
%type <arglste>		arg_listE;
%type <arglst>		arg_list;

%token <int_const> CELVAL
%token <float_const> VESHVAL
%token <id> ID
%token NOTEQ
%token ASSIGN
%token POW
%token NEWLINE
%token VIBOR
%token PRI
%token NZ
%token KZ
%token KZ_PRI
%token IF
%token ELSE
%token THEN
%token OT
%token DO
%token VSE
%token DLYA
%token SHAG
%token POKA
%token RAZ
%token DA
%token NET
%token OR
%token AND
%token ALG
%token NACH
%token KON
%token <int_const> TYPE
%token <int_const> FUNCPREF
%token <int_const> ARGTYPE
%token NS
%token VVOD
%token VIVOD

%token ZNACH
%token NE
%token UTV
%token VIHOD
%token <str> QUOTE1
%token <str> QUOTE2
%token TRASH

%right ASSIGN
%left OR
%left AND
%left '<' '>' '=' LESSEQ MOREEQ NOTEQ
%left '-' '+'
%left '*' '/'
%left POW
%left UMINUS
%nonassoc '[' ']'
%nonassoc '(' ')'
%%

program: 
      stmt_list ALG ';' func_pref_list NACH ';' stmt_list KON ';'							{ $$ = CreateProgram($1, $4, $7, NULL); print($$); }
    | ALG ';' func_pref_list NACH ';' stmt_list KON ';'										{ $$ = CreateProgram(NULL, $3, $6, NULL);  print($$); }
    | stmt_list ALG ';' func_pref_list NACH ';' stmt_list KON ';' func_list					{ $$ = CreateProgram($1, $4, $7, $10);  print($$); }
    | ALG ';' func_pref_list NACH ';' stmt_list KON ';' func_list							{ $$ = CreateProgram(NULL, $3, $6, $9);  print($$); }
    ;

func_list:
	  ALG ID '(' arg_list ')' ';' func_pref_list NACH ';' stmt_list KON ';'					{ $$ = CreateFunctionList(-1, $2, $4, $7, $10, NULL); }
    | TYPE ALG ID '(' arg_list ')' ';' func_pref_list NACH ';' stmt_list KON ';'			{ $$ = CreateFunctionList($1, $3, $5, $8, $11, NULL); }
	| func_list ALG ID '(' arg_list ')' ';' func_pref_list NACH ';' stmt_list KON ';'		{ $$ = CreateFunctionList(-1, $3, $5, $8, $11, $1); }
	| func_list TYPE ALG ID '(' arg_list ')' ';' func_pref_list NACH ';' stmt_list KON ';'	{ $$ = CreateFunctionList($2, $4, $6, $9, $12, $1); }
	;

stmt_list: 
      stmt							{ $$ = CreateStatementList($1, NULL); }
    | stmt_list stmt				{ $$ = CreateStatementList($2, $1); }
    ;

stmt:
      expr ';'						{ $$ = CreateFromExprStatement(__EXPR, $1); }
    | if_stmt ';'					{ $$ = CreateFromIfStatement(__IF, $1); }
    | loop_stmt ';'					{ $$ = CreateFromLoopStatement(__LOOP, $1); }
    | switch_stmt ';'				{ $$ = CreateFromSwitchStatement(__SWITCH, $1); }
    | TYPE id_list ';'				{ $$ = CreateFromTypeListStatement(__TYPE, $1, $2); }
    | VVOD id_list ';'				{ $$ = CreateFromInOutStatement(__VVOD, NULL, $2); }
    | VIVOD expr_list ';'			{ $$ = CreateFromInOutStatement(__VIVOD, $2, NULL); }
    ;

if_stmt: 
      IF expr THEN stmt_list VSE								{ $$ = CreateIfStatement($2, $4, NULL); }
    | IF expr THEN stmt_list ELSE stmt_list VSE					{ $$ = CreateIfStatement($2, $4, $6); }
    ;

switch_stmt:
      VIBOR switch_lines VSE									{ $$ = CreateSwitchStatement($2, NULL); }
    | VIBOR switch_lines ELSE stmt_list VSE						{ $$ = CreateSwitchStatement($2, $4); }
    ;

switch_lines: 
      PRI expr ':' stmt_list									{ $$ = CreateSwitchLines($2, $4, NULL); }
    | switch_lines PRI expr ':' stmt_list						{ $$ = CreateSwitchLines($3, $5, $1); }
    ;

loop_stmt: 
      NZ DLYA ID OT CELVAL DO CELVAL stmt_list KZ				{ $$ = CreateLoopStatement(__DLYA, $3, $5, $7, 1, NULL, $8); }
    | NZ DLYA ID OT CELVAL DO CELVAL SHAG CELVAL stmt_list KZ	{ $$ = CreateLoopStatement(__DLYASHAG, $3, $5, $7, $9, NULL, $10); }
    | NZ stmt_list KZ											{ $$ = CreateLoopStatement(__PROST, NULL, -1, -1, -1, NULL, $2); }
	| NZ stmt_list KZ_PRI expr									{ $$ = CreateLoopStatement(__PRI, NULL, -1, -1, -1, $4, $2); }
    | NZ POKA expr ';' stmt_list KZ								{ $$ = CreateLoopStatement(__POKA, NULL, -1, -1, -1, $3, $5); }
    | NZ CELVAL RAZ stmt_list KZ								{ $$ = CreateLoopStatement(__RAZ, NULL, 0, $2, -1, NULL, $4); }
    ;

expr:
      expr '+' expr					{ $$ = CreateCompExpression(_ADD, $1, $3); }
    | expr '-' expr					{ $$ = CreateCompExpression(_SUB, $1, $3); }
    | expr '*' expr					{ $$ = CreateCompExpression(_MUL, $1, $3); }
    | expr '/' expr					{ $$ = CreateCompExpression(_DIV, $1, $3); }
    | '-' expr %prec UMINUS			{ $$ = CreateCompExpression(_UNARSUB, $2, NULL); }
    | expr POW expr					{ $$ = CreateCompExpression(_POW, $1, $3); }
    | '(' expr ')'					{ $$ = $2; }
    | expr NOTEQ expr				{ $$ = CreateCompExpression(_NOTEQ, $1, $3); }
    | expr OR expr 					{ $$ = CreateCompExpression(_OR, $1, $3); }
    | expr AND expr					{ $$ = CreateCompExpression(_AND, $1, $3); }
    | DA							{ $$ = CreateSimpleExpression(_DA, -1, -1, NULL, NULL, NULL); }
    | NET							{ $$ = CreateSimpleExpression(_NET, -1, -1, NULL, NULL, NULL); }
    | NS							{ $$ = CreateSimpleExpression(_NS, -1, -1, NULL, NULL, NULL); }
    | expr '>' expr					{ $$ = CreateCompExpression(_GREAT, $1, $3); }
    | expr '<' expr					{ $$ = CreateCompExpression(_LESS, $1, $3); }
    | expr LESSEQ expr				{ $$ = CreateCompExpression(_LESSEQ, $1, $3); }
    | expr MOREEQ expr				{ $$ = CreateCompExpression(_GREATEQ, $1, $3); }
    | expr '=' expr					{ $$ = CreateCompExpression(_EQ, $1, $3); }
    | ID ASSIGN expr				{ $$ = CreateSimpleExpression(_IDASSIGN, -1, -1, $1, $3, NULL); }
    | ID '[' CELVAL ']' ASSIGN expr	{ $$ = CreateSimpleExpression(_ARRASSIGN, $3, -1, $1, $6, NULL); }
    | CELVAL						{ $$ = CreateSimpleExpression(_CELVAL, $1, -1, NULL, NULL, NULL); }
    | VESHVAL						{ $$ = CreateSimpleExpression(_VESHVAL, -1, $1, NULL, NULL, NULL); }
    | ID '[' CELVAL ']'				{ $$ = CreateSimpleExpression(_ARRID, $3, -1, $1, NULL, NULL); }
    | ID							{ $$ = CreateSimpleExpression(_ID, -1, -1, $1, NULL, NULL); }
    | ID '(' expr_list ')'			{ $$ = CreateSimpleExpression(_FUNCCALL, -1, -1, $1, NULL, $3); }
    | ID '(' ')'					{ $$ = CreateSimpleExpression(_FUNCCALL, -1, -1, $1, NULL, NULL); }
    ;

expr_list: 
      expr							{ $$ = CreateExpressionList($1, NULL); }
    | expr_list ',' expr			{ $$ = CreateExpressionList($3, $1); }
    ;

id_list:
      ID							{ $$ = CreateIdList(-1, $1, NULL); }
    | ID '[' CELVAL ']'				{ $$ = CreateIdList($3, $1, NULL); }
    | id_list ',' ID				{ $$ = CreateIdList(-1, $3, $1); }
    | id_list ',' ID '[' CELVAL ']'	{ $$ = CreateIdList($5, $3, $1); }
    ;

arg_list:
      /* empty */					{ $$ = 0; }
    | arg_listE						{ $$ = CreateArgList($1); }
    ;

arg_listE:
      ARGTYPE TYPE ID								{ $$ = CreateArgListE($1, $2, $3, -1, NULL); }
    | ARGTYPE TYPE ID '[' CELVAL ']'				{ $$ = CreateArgListE($1, $2, $3, $5, NULL); }
    | TYPE ID										{ $$ = CreateArgListE(-1, $1, $2, -1, NULL); }
    | TYPE ID '[' CELVAL ']'						{ $$ = CreateArgListE(-1, $1, $2, $4, NULL); }
    | arg_listE ',' ARGTYPE TYPE ID					{ $$ = CreateArgListE($3, $4, $5, -1, $1); }
    | arg_listE ',' ARGTYPE TYPE ID '[' CELVAL ']'	{ $$ = CreateArgListE($3, $4, $5, $7, $1); }
    | arg_listE ',' TYPE ID							{ $$ = CreateArgListE(-1, $3, $4, -1, $1); }
    | arg_listE ',' TYPE ID '[' CELVAL ']'			{ $$ = CreateArgListE(-1, $3, $4, $6, $1); }
    ;

func_pref_list:
      /* empty */						{ $$ = 0; }
    | func_pref_listE					{ $$ = CreatePrefList($1); }
    ;

func_pref_listE:
      FUNCPREF ';'						{ $$ = CreatePrefListE($1, NULL, NULL); }
    | FUNCPREF expr ';'					{ $$ = CreatePrefListE($1, $2, NULL); }
    | func_pref_listE FUNCPREF			{ $$ = CreatePrefListE($2, NULL, $1); }
    | func_pref_listE FUNCPREF expr	';'	{ $$ = CreatePrefListE($2, $3, $1); }
    ;
%%

void yyerror(char const *s)
{
	printf("%s",s);
}