#ifndef STRUCTURES
#define STRUCTURES

enum ExprType
{
	_ADD,
	_SUB,
	_MUL,
	_DIV,
	_UNARSUB,
	_POW,
	_NOTEQ,
	_OR,
	_AND,
	_DA,
	_NET,
	_NS,
	_GREAT,
	_LESS,
	_GREATEQ,
	_LESSEQ,
	_EQ,
	_IDASSIGN,
	_ARRASSIGN,
	_CELVAL,
	_VESHVAL,
	_ARRID,
	_ID,
	_FUNCCALL
};

enum StmtType
{
	__EXPR,
	__IF,
	__SWITCH,
	__LOOP,
	__TYPE,
	__VVOD,
	__VIVOD
};

enum LoopType
{
	__DLYA,
	__DLYASHAG,
	__PROST,
	__PRI,
	__POKA,
	__RAZ
};

struct ProgramInfo
{
	struct StmtListInfo * prefix;
	struct PrefListInfo * funcpreflist;
	struct StmtListInfo * stmtlist;
	struct FuncListInfo * functions;
};

struct FuncListInfo
{
	int type;
	char * funcname;
	struct ArgListInfo * arglist;
	struct PrefListInfo * funcpreflist;
	struct StmtListInfo * stmtlist;
	struct FuncListInfo * next;
	struct FuncListInfo * first;
};

struct ExprInfo
{
	struct ExprInfo * left;
	struct ExprInfo * right;
	struct ExprInfo * next;
	struct ExprListInfo * arglist;
	enum ExprType type;

	char * id;
	int celval;
	float veshval;
};

struct ExprListInfo
{
	struct ExprInfo * first;
	struct ExprInfo * last;
};

struct IdListInfo
{
	char* id;
	int celval;
	struct IdListInfo * next;
	struct IdListInfo * first;
};

struct StmtInfo
{
	enum StmtType type;
	struct ExprInfo * expr;
	struct IfStmtInfo * ifstmt;
	struct LoopStmtInfo * loopstmt;
	struct SwitchStmtInfo * switchstmt;
	int vartype;
	struct IdListInfo * idlist;
	struct ExprListInfo * exprlist;
	struct StmtInfo * next;
};

struct StmtListInfo
{
	struct StmtInfo * first;
	struct StmtInfo * last;
};

struct PrefListEInfo
{
	int type;
	struct ExprInfo * expr;
	struct PrefListEInfo * next;
	struct PrefListEInfo * first;
};

struct PrefListInfo
{
	struct PrefListEInfo * preflist;
};

struct IfStmtInfo
{
	struct ExprInfo * expr;
	struct StmtListInfo * stmtlist;
	struct StmtListInfo * elsestmtlist;
};

struct SwitchStmtInfo
{
	struct SwitchLinesInfo * lines;
	struct StmtListInfo * stmtlist;
};

struct SwitchLinesInfo
{
	struct ExprInfo * expr;
	struct StmtListInfo * stmtlist;
	struct SwitchLinesInfo * next;
	struct SwitchLinesInfo * first;
};

struct LoopStmtInfo
{
	enum LoopType type;
	char * var;
	int from;
	int to;
	int shag;
	struct ExprInfo * expr;
	struct StmtListInfo * stmtlist;
};

struct ArgListEInfo
{
	int argtype;
	int vartype;
	char * id;
	int arrind;
	struct ArgListEInfo * next;
	struct ArgListEInfo * first;
};

struct ArgListInfo
{
	struct ArgListEInfo * arglist;
};

#endif