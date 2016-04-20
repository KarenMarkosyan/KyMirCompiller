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


extern YYSTYPE yylval;
