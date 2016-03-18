// LexerKymup.cpp: определяет точку входа для консольного приложения.
//

#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <stdio.h>
#include "stdafx.h"
#include "lex.yy.c"
#include "locale.h"
#include "string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "russian");
	freopen("output.txt", "w", stdout);
	yyin = fopen("1.txt", "r");
	yylex();
}

