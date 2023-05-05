a: lex.yy.c y.tab.c
	gcc lex.yy.c y.tab.c -ll

lex.yy.c: lexer_cs111.l
	lex lexer_cs111.l

y.tab.c y.tab.h: parser_cs111.y
	yacc -d parser_cs111.y -Wno

clean:
	rm -f y.tab.h y.tab.c lex.yy.c a.exe a.out
