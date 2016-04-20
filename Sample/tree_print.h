#include <stdio.h>
#include <string.h>
#include "tree_structs.h"

char dotfile[10] = "tree.dot";
FILE * file;
int nodeid = 0;

void printFuncList(struct FuncListInfo * funclist, int idfrom);
void printFunc(struct FuncListInfo * func, int idfrom);
void printPrefList(struct PrefListInfo * preflist, int idfrom);
void printPrefListE(struct PrefListEInfo * preflist, int idfrom);
void printArgList(struct ArgListInfo * arglist, int idfrom);
void printArgListE(struct ArgListEInfo * arglist, int idfrom, int argnum);
void printStmtList(struct StmtListInfo * stmtlist, int idfrom);
void printStmt(struct StmtInfo * stmt, int idfrom);
void printIfStmt(struct IfStmtInfo * ifstmt, int idfrom);
void printSwitchStmt(struct SwitchStmtInfo * switchstmt, int idfrom);
void printSwitchLine(struct SwitchLinesInfo * switchline, int idfrom);
void printLoopStmt(struct LoopStmtInfo * loopstmt, int idfrom);
void printExprList(struct ExprListInfo * exprlist, int idfrom);
void printExpr(struct ExprInfo * expr, int idfrom);
void printIdList(struct IdListInfo * idlist, int idfrom);
void printId(struct IdListInfo * idlist, int idfrom);
void printByStr(int parent, int child, char * name);
void printByNum(int parent, int child, int name);
void printByFloat(int parent, int child, float name);
void printNode(int id, char * name);
void printRelation(int parent, int child);
char * getTypeName(int type_id);
char * getArgTypeName(int argtype_id);
char * transliterateId(char * id);
char * transliterateChar(char ch);

void print(struct ProgramInfo * tree)
{
	int id = nodeid++;
	if (tree == NULL)
		return;

	file = fopen(dotfile, "w");
	fputs("digraph G {\n", file);
	
	printNode(id, "Program Starts");

	if (tree->prefix != NULL)
		printStmtList(tree->prefix, id);
	if (tree->funcpreflist != NULL)
		printPrefList(tree->funcpreflist, id);
	if (tree->stmtlist != NULL)
		printStmtList(tree->stmtlist, id);
	if (tree->functions != NULL)
		printFuncList(tree->functions, id);

	fputs("}Program Ends", file);
	fclose(file);
}

void printFuncList(struct FuncListInfo * funclist, int idfrom)
{
	int id = nodeid++;
	struct FuncListInfo * fl = funclist->first;
	printByStr(idfrom, id, "FuncList");
	do {
		printFunc(fl, id);
		fl = fl->next;
	} while (fl != NULL);
}

void printFunc(struct FuncListInfo * func, int idfrom)
{
	int id = nodeid++;
	printByStr(idfrom, id, func->funcname);
	if (func->type)
		printByStr(id, nodeid++, getTypeName(func->type));
	if (func->arglist != NULL)
		printArgList(func->arglist, id);
	if (func->funcpreflist != NULL)
		printPrefList(func->funcpreflist, id);
	if (func->stmtlist != NULL)
		printStmtList(func->stmtlist, id);
}

void printPrefList(struct PrefListInfo * preflist, int idfrom)
{
	int id = nodeid++;
	printByStr(idfrom, id, "PrefList");
	if (preflist->preflist != NULL)
		printPrefListE(preflist->preflist, id);
}

void printPrefListE(struct PrefListEInfo * preflist, int idfrom)
{
	int id = nodeid++;
	if (preflist->type == 1)
		printByStr(idfrom, id, "DANO");
	else
		printByStr(idfrom, id, "NADO");

	if (preflist->expr != NULL)
		printExpr(preflist->expr, id);
	if (preflist->next != NULL)
		printPrefListE(preflist->next, idfrom);
}

void printArgList(struct ArgListInfo * arglist, int idfrom)
{
	int id = nodeid++;
	printByStr(idfrom, id, "ArgList");
	if (arglist->arglist != NULL)
		printArgListE(arglist->arglist, id, 1);
}

void printArgListE(struct ArgListEInfo * arglist, int idfrom, int argnum)
{
	int id = nodeid++;

	if (argnum == 1 && arglist->argtype == 0)
		arglist->argtype = 1;
	
	printByNum(idfrom, id, argnum);
	if (arglist->argtype != -1)
		printByStr(id, nodeid++, getArgTypeName(arglist->argtype));
	printByStr(id, nodeid++, getTypeName(arglist->vartype));
	printByStr(id, nodeid++, "ID");
	printByStr(nodeid-2, nodeid++, arglist->id);
	if (arglist->arrind != -1)
	{
		printByStr(idfrom, nodeid++, "ArrInd");
		printByNum(nodeid-2, nodeid++, arglist->arrind);
	}
	if (arglist->next != NULL)
		printArgListE(arglist->next, idfrom, ++argnum);
}

void printStmtList(struct StmtListInfo * stmtlist, int idfrom)
{
	int id = nodeid++;
	struct StmtInfo * si = stmtlist->first;
	printByStr(idfrom, id, "Stmtlist");
	while (si != NULL)
	{
		printStmt(si, id);
		si = si->next;
	}
}

void printStmt(struct StmtInfo * stmt, int idfrom)
{
	int id = nodeid++;
	printByStr(idfrom, id, "Stmt");
	switch (stmt->type)
	{
	case __EXPR:
		printExpr(stmt->expr, id);
		break;
	case __IF:
		printIfStmt(stmt->ifstmt, id);
		break;
	case __SWITCH:
		printSwitchStmt(stmt->switchstmt, id);
		break;
	case __LOOP:
		printLoopStmt(stmt->loopstmt, id);
		break;
	case __TYPE:
		printByStr(id, nodeid++, "Type");
		printByStr(nodeid-2, nodeid++, getTypeName(stmt->vartype));
		printIdList(stmt->idlist, nodeid-2);
		break;
	case __VVOD:
		printByStr(id, nodeid++, "Vvod");
		printIdList(stmt->idlist, nodeid-1);
		break;
	case __VIVOD:
		printByStr(id, nodeid++, "Vivod");
		printExprList(stmt->exprlist, nodeid-1);
		break;
	}
}

void printIfStmt(struct IfStmtInfo * ifstmt, int idfrom)
{
	int id = nodeid++;
	printByStr(idfrom, id, "IfStmt");
	printExpr(ifstmt->expr, id);
	printStmtList(ifstmt->stmtlist, id);
	if (ifstmt->elsestmtlist != NULL)
		printStmtList(ifstmt->elsestmtlist, id);
}

void printSwitchStmt(struct SwitchStmtInfo * switchstmt, int idfrom)
{
	int id = nodeid++;
	struct SwitchLinesInfo * sl = switchstmt->lines;
	printByStr(idfrom, id, "SwitchStmt");
	do {
		printSwitchLine(sl, id);
		sl = sl->next;
	} while (sl != NULL);
	if (switchstmt->stmtlist != NULL)
	{
		printByStr(id, nodeid, "Default");
		printStmtList(switchstmt->stmtlist, nodeid++);
	}
}

void printSwitchLine(struct SwitchLinesInfo * switchline, int idfrom)
{
	int id = nodeid++;
	printByStr(idfrom, id, "SwitchLine");
	printExpr(switchline->expr, id);
	printStmtList(switchline->stmtlist, id);
}

void printLoopStmt(struct LoopStmtInfo * loopstmt, int idfrom)
{
	int id = nodeid++;
	switch (loopstmt->type)
	{
	case __DLYA:
		printByStr(idfrom, id, "Dlya Loop");
		printByStr(id, nodeid++, loopstmt->var);
		printByNum(id, nodeid++, loopstmt->from);
		printByNum(id, nodeid++, loopstmt->to);
		printStmtList(loopstmt->stmtlist, id);
		break;
	case __DLYASHAG:
		printByStr(idfrom, id, "DlyaShag Loop");
		printByStr(id, nodeid++, loopstmt->var);
		printByNum(id, nodeid++, loopstmt->from);
		printByNum(id, nodeid++, loopstmt->to);
		printByNum(id, nodeid++, loopstmt->shag);
		printStmtList(loopstmt->stmtlist, id);
		break;
	case __PROST:
		printByStr(idfrom, id, "Prost Loop");
		printStmtList(loopstmt->stmtlist, id);
		break;
	case __PRI:
		printByStr(idfrom, id, "Pri Loop");
		printExpr(loopstmt->expr, id);
		printStmtList(loopstmt->stmtlist, id);
		break;
	case __POKA:
		printByStr(idfrom, id, "Poka Loop");
		printExpr(loopstmt->expr, id);
		printStmtList(loopstmt->stmtlist, id);
		break;
	case __RAZ:
		printByStr(idfrom, id, "Raz Loop");
		printByNum(id, nodeid++, loopstmt->to);
		printStmtList(loopstmt->stmtlist, id);
		break;
	}
}

void printExprList(struct ExprListInfo * exprlist, int idfrom)
{
	int id = nodeid++;
	struct ExprInfo * ei = exprlist->first;
	printByStr(idfrom, id, "Exprlist");
	while (ei != NULL)
	{
		printExpr(ei, id);
		ei = ei->next;
	}
}

void printExpr(struct ExprInfo * expr, int idfrom)
{
	int id = nodeid++;
	printNode(id, "Expr");
	printRelation(idfrom, id);
	switch (expr->type)
	{
	case _ADD:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "+");
		printExpr(expr->right, id);
		break;
	case _SUB:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "-");
		printExpr(expr->right, id);
		break;
	case _MUL:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "*");
		printExpr(expr->right, id);
		break;
	case _DIV:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "/");
		printExpr(expr->right, id);
		break;
	case _UNARSUB:
		printByStr(id, nodeid++, "-");
		printExpr(expr->left, id);
		break;
	case _POW:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "POW");
		printExpr(expr->right, id);
		break;
	case _NOTEQ:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "!=");
		printExpr(expr->right, id);
		break;
	case _OR:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "||");
		printExpr(expr->right, id);
		break;
	case _AND:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "&&");
		printExpr(expr->right, id);
		break;
	case _DA:
		printByStr(id, nodeid++, "TRUE");
		break;
	case _NET:
		printByStr(id, nodeid++, "FALSE");
		break;
	case _NS:
		printByStr(id, nodeid++, "NS");
		break;
	case _GREAT:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, ">");
		printExpr(expr->right, id);
		break;
	case _LESS:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "<");
		printExpr(expr->right, id);
		break;
	case _GREATEQ:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, ">=");
		printExpr(expr->right, id);
		break;
	case _LESSEQ:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "<=");
		printExpr(expr->right, id);
		break;
	case _EQ:
		printExpr(expr->left, id);
		printByStr(id, nodeid++, "==");
		printExpr(expr->right, id);
		break;
	case _IDASSIGN:
		printByStr(id, nodeid++, expr->id);
		printByStr(id, nodeid++, "=");
		printExpr(expr->left, id);
		break;
	case _ARRASSIGN:
		printByStr(id, nodeid++, expr->id);
		printByNum(id, nodeid++, expr->celval);
		printByStr(id, nodeid++, "=");
		printExpr(expr->left, id);
		break;
	case _CELVAL:
		printByNum(id, nodeid++, expr->celval);
		break;
	case _VESHVAL:
		printByFloat(id, nodeid++, expr->veshval);
		break;
	case _ARRID:
		printByStr(id, nodeid++, expr->id);
		printByNum(id, nodeid++, expr->celval);
		break;
	case _ID:
		printByStr(id, nodeid++, expr->id);
		break;
	case _FUNCCALL:
		printByStr(id, nodeid++, "FuncCall");
		printByStr(nodeid-2, nodeid++, expr->id);
		if (expr->arglist != NULL)
			printExprList(expr->arglist, nodeid-3);
		break;
	}
}

void printIdList(struct IdListInfo * idlist, int idfrom)
{
	int id = nodeid++;
	struct IdListInfo * il = idlist->first;
	printByStr(idfrom, id, "Idlist");
	do {
		printId(il, id);
		il = il->next;
	} while (il != NULL);
}

void printId(struct IdListInfo * idlist, int idfrom)
{
	int id = nodeid++;
	if (idlist->celval == -1)
	{
		printByStr(idfrom, id, "ID");
		printByStr(id, nodeid++, idlist->id);
	}
	else
	{
		printByStr(idfrom, id, "ARRID");
		printByStr(id, nodeid++, idlist->id);
		printByNum(id, nodeid++, idlist->celval);
	}
}

void printByStr(int parent, int child, char * name)
{
	printNode(child, name);
	printRelation(parent, child);
}

void printByNum(int parent, int child, int name)
{
	char num[1000];
	_itoa(name, num, 10);
	printNode(child, num);
	printRelation(parent, child);
}

void printByFloat(int parent, int child, float name)
{
	char num[1000];
	sprintf(num, "%f", name);
	printNode(child, num);
	printRelation(parent, child);
}

void printNode(int id, char * name)
{
	char num[1000];
	_itoa(id, num, 10);
	fputs("a", file);
	fputs(num, file);
	fputs(" [label=\"", file);
	fputs(name, file);
	fputs("\"];\n", file);
}

void printRelation(int parent, int child)
{
	char num[1000];
	_itoa(parent, num, 10);
	fputs("a", file);
	fputs(num, file);
	fputs("->a", file);
	_itoa(child, num, 10);
	fputs(num, file);
	fputs(";\n", file);
}

char * getTypeName(int type_id)
{
	switch (type_id)
	{
	case 1: return "CEL"; 
	case 2: return "VESH"; 
	case 3: return "LOG"; 
	case 4: return "SIM"; 
	case 5: return "LIT"; 
	case 6: return "TAB"; 
	case 7: return "CELTAB"; 
	case 8: return "VESHTAB"; 
	case 9: return "LOGTAB"; 
	case 10: return "SIMTAB"; 
	case 11: return "LITTAB"; 
	}
}

char * getArgTypeName(int argtype_id)
{
	switch (argtype_id)
	{
	case 1: return "ARG"; 
	case 2: return "RES"; 
	case 3: return "ARGRES"; 
	}
}

char * transliterateId(char * id)
{
	char res[256];
	char * tmp;
	int i = 0;
	memset(res, 0, sizeof(res));
	for (i = 0; i < strlen(id); ++i)
	{
		tmp = transliterateChar(id[i]);
		if (i == 0)
			strcpy(res, tmp);
		else
			strcat(res, tmp);
	}
	res[strlen(res)] = '\0';
	return res;
}

char * transliterateChar(char ch)
{
	char res[2];
	switch (ch)
	{
	case 'à':
		return "a";
	case 'á':
		return "b";
	case 'â':
		return "v";
	case 'ã':
		return "g";
	case 'ä':
		return "d";
	case 'å':
		return "e";
	case '¸':
		return "e";
	case 'æ':
		return "j";
	case 'ç':
		return "z";
	case 'è':
		return "i";
	case 'é':
		return "y";
	case 'ê':
		return "k";
	case 'ë':
		return "l";
	case 'ì':
		return "m";
	case 'í':
		return "n";
	case 'î':
		return "o";
	case 'ï':
		return "p";
	case 'ð':
		return "r";
	case 'ñ':
		return "s";
	case 'ò':
		return "t";
	case 'ó':
		return "u";
	case 'ô':
		return "f";
	case 'õ':
		return "h";
	case 'ö':
		return "c";
	case '÷':
		return "ch";
	case 'ø':
		return "sh";
	case 'ù':
		return "sh";
	case 'ú':
		return "";
	case 'û':
		return "i";
	case 'ü':
		return "\'";
	case 'ý':
		return "e";
	case 'þ':
		return "u";
	case 'ÿ':
		return "ya";
	default:
		res[0] = ch;
		res[1] = '\0';
		return res;
	}
}