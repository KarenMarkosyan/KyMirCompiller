#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "tree_structs.h"

struct ProgramInfo * CreateProgram (struct StmtListInfo * prefix, struct PrefListInfo * funcpreflist, struct StmtListInfo * stmtlist, struct FuncListInfo * functions)
{
	struct ProgramInfo * prog = (struct ProgramInfo *)malloc(sizeof(struct ProgramInfo));
	prog->prefix = prefix;
	prog->funcpreflist = funcpreflist;
	prog->stmtlist = stmtlist;
	prog->functions = functions;

	return prog;
}

struct FuncListInfo * CreateFunctionList (int type, char * funcname, struct ArgListInfo * arglist, struct PrefListInfo * funcpreflist, struct StmtListInfo * stmtlist, struct FuncListInfo * prev)
{
	struct FuncListInfo * functionlist = (struct FuncListInfo *)malloc(sizeof(struct FuncListInfo));
	functionlist->type = type;
	functionlist->funcname = funcname;
	functionlist->arglist = arglist;
	functionlist->funcpreflist = funcpreflist;
	functionlist->stmtlist = stmtlist;
	functionlist->next = NULL;
	if (prev != NULL)
	{
		prev->next = functionlist;
		functionlist->first = prev->first;
	}
	else
		functionlist->first = functionlist;

	return functionlist;
}

struct StmtListInfo * CreateStatementList (struct StmtInfo * stmt, struct StmtListInfo * stmtlist)
{
	stmt->next = NULL;
	if (stmtlist == NULL)
	{
		struct StmtListInfo * sl = (struct StmtListInfo *)malloc(sizeof(struct StmtListInfo));
		sl->first = sl->last = stmt;
		return sl;
	}
	
	stmtlist->last = stmtlist->last->next = stmt;
	return stmtlist;
}

struct StmtInfo * CreateFromExprStatement (enum StmtType type, struct ExprInfo * expr)
{
	struct StmtInfo * stmt = (struct StmtInfo *)malloc(sizeof(struct StmtInfo));
	stmt->type = type;
	stmt->expr = expr;
	stmt->next = NULL;

	return stmt;
}
struct StmtInfo * CreateFromIfStatement (enum StmtType type, struct IfStmtInfo * ifstmt)
{
	struct StmtInfo * stmt = (struct StmtInfo *)malloc(sizeof(struct StmtInfo));
	stmt->type = type;
	stmt->ifstmt = ifstmt;
	stmt->next = NULL;

	return stmt;
}
struct StmtInfo * CreateFromLoopStatement (enum StmtType type, struct LoopStmtInfo * loopstmt)
{
	struct StmtInfo * stmt = (struct StmtInfo *)malloc(sizeof(struct StmtInfo));
	stmt->type = type;
	stmt->loopstmt = loopstmt;
	stmt->next = NULL;

	return stmt;
}
struct StmtInfo * CreateFromSwitchStatement (enum StmtType type, struct SwitchStmtInfo * switchstmt)
{
	struct StmtInfo * stmt = (struct StmtInfo *)malloc(sizeof(struct StmtInfo));
	stmt->type = type;
	stmt->switchstmt = switchstmt;
	stmt->next = NULL;

	return stmt;
}
struct StmtInfo * CreateFromTypeListStatement (enum StmtType type, int vartype, struct IdListInfo * idlist)
{
	struct StmtInfo * stmt = (struct StmtInfo *)malloc(sizeof(struct StmtInfo));
	stmt->type = type;
	stmt->vartype = vartype;
	stmt->idlist = idlist;
	stmt->next = NULL;

	return stmt;
}
struct StmtInfo * CreateFromInOutStatement (enum StmtType type, struct ExprListInfo * exprlist, struct IdListInfo * idlist)
{
	struct StmtInfo * stmt = (struct StmtInfo *)malloc(sizeof(struct StmtInfo));
	stmt->type = type;
	stmt->exprlist = exprlist;
	stmt->idlist = idlist;
	stmt->next = NULL;

	return stmt;
}

struct IfStmtInfo * CreateIfStatement (struct ExprInfo * expr, struct StmtListInfo * stmtlist, struct StmtListInfo * elsestmtlist)
{
	struct IfStmtInfo * ifstmt = (struct IfStmtInfo *)malloc(sizeof(struct IfStmtInfo));
	ifstmt->expr = expr;
	ifstmt->stmtlist = stmtlist;
	ifstmt->elsestmtlist = elsestmtlist;

	return ifstmt;
}

struct SwitchStmtInfo * CreateSwitchStatement (struct SwitchLinesInfo * lines, struct StmtListInfo * stmtlist)
{
	struct SwitchStmtInfo * switchstmt = (struct SwitchStmtInfo *)malloc(sizeof(struct SwitchStmtInfo));
	switchstmt->lines = lines->first;
	switchstmt->stmtlist = stmtlist;

	return switchstmt;
}

struct SwitchLinesInfo * CreateSwitchLines (struct ExprInfo * expr, struct StmtListInfo * stmtlist, struct SwitchLinesInfo * prev)
{
	struct SwitchLinesInfo * switchlines = (struct SwitchLinesInfo *)malloc(sizeof(struct SwitchLinesInfo));
	switchlines->expr = expr;
	switchlines->stmtlist = stmtlist;
	switchlines->next = NULL;
	if (prev != NULL)
	{
		prev->next = switchlines;
		switchlines->first = prev->first;
	}
	else
		switchlines->first = switchlines;

	return switchlines;
}

struct LoopStmtInfo * CreateLoopStatement (enum LoopType type, char * var, int from, int to, int shag, struct ExprInfo * expr, struct StmtListInfo * stmtlist)
{
	struct LoopStmtInfo * loopstmt = (struct LoopStmtInfo *)malloc(sizeof(struct LoopStmtInfo));
	loopstmt->type = type;
	loopstmt->var = var;
	loopstmt->from = from;
	loopstmt->to = to;
	loopstmt->shag = shag;
	loopstmt->expr = expr;
	loopstmt->stmtlist = stmtlist;
	
	return loopstmt;
}

struct ExprInfo * CreateCompExpression (enum ExprType type, struct ExprInfo * left, struct ExprInfo * right)
{
	struct ExprInfo * exp = (struct ExprInfo *)malloc(sizeof(struct ExprInfo));
	exp->type = type;
	exp->left = left;
	exp->right = right;

	return exp;
}

struct ExprInfo * CreateSimpleExpression (enum ExprType type, int a, float b, char * c, struct ExprInfo * expr, struct ExprListInfo * exprlist)
{
	struct ExprInfo * exp = (struct ExprInfo *)malloc(sizeof(struct ExprInfo));
	exp->type = type;
	exp->celval = a;
	exp->veshval = b;
	exp->id = c;
	exp->left = expr;
	exp->arglist = exprlist;

	return exp;
}

struct ExprListInfo * CreateExpressionList (struct ExprInfo * expr, struct ExprListInfo * exprlist)
{
	expr->next = NULL;
	if (exprlist == NULL)
	{
		struct ExprListInfo * el = (struct ExprListInfo *)malloc(sizeof(struct ExprListInfo));
		el->first = el->last = expr;
		return el;
	}
	
	exprlist->last = exprlist->last->next = expr;
	return exprlist;
}

struct IdListInfo * CreateIdList (int val, char * id, struct IdListInfo * prev)
{
	struct IdListInfo * idlist = (struct IdListInfo *)malloc(sizeof(struct IdListInfo));
	idlist->celval = val;
	idlist->id = id;
	idlist->next = NULL;
	if (prev != NULL)
	{
		prev->next = idlist;
		idlist->first = prev->first;
	}
	else
		idlist->first = idlist;

	return idlist;
}

struct ArgListEInfo * CreateArgListE (int argtype, int vartype, char * id, int arrind, struct ArgListEInfo * prev)
{
	struct ArgListEInfo * arglist = (struct ArgListEInfo *)malloc(sizeof(struct ArgListEInfo));
	arglist->argtype = argtype;
	arglist->vartype = vartype;
	arglist->id = id;
	arglist->arrind = arrind;
	arglist->next = NULL;
	if (prev != NULL)
	{
		prev->next = arglist;
		arglist->first = prev->first;
	}
	else
		arglist->first = arglist;

	return arglist;
}

struct ArgListInfo * CreateArgList(struct ArgListEInfo * ale)
{
	struct ArgListInfo * al = (struct ArgListInfo *)malloc(sizeof(struct ArgListInfo));
	al->arglist = ale->first;
	return al;
}

struct PrefListEInfo * CreatePrefListE (int type, struct ExprInfo * expr, struct PrefListEInfo * prev)
{
	struct PrefListEInfo * preflist = (struct PrefListEInfo *)malloc(sizeof(struct PrefListEInfo));
	preflist->type = type;
	preflist->expr = expr;
	preflist->next = NULL;
	if (prev != NULL)
	{
		prev->next = preflist;
		preflist->first = prev->first;
	}
	else
		preflist->first = preflist;

	return preflist;
}

struct PrefListInfo * CreatePrefList (struct PrefListEInfo * ple)
{
	struct PrefListInfo * pl = (struct PrefListInfo *)malloc(sizeof(struct PrefListInfo));
	pl->preflist = ple->first;
	return pl;
}