#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <iostream>
#include "tree_structs.h"

extern "C" FILE *yyin;
extern "C" int yyparse();

void main()
{
	setlocale(LC_ALL, "Russian");
	yyin = fopen("test.txt", "r"); //access file with test
	yyparse(); //send through parser
	//	system("repaint");
	system("pause"); 
}
//IDETIFIER ASSIGN expr {printf(""); $$=CreateIdExpr(_ASSIGN,$1,$3); }