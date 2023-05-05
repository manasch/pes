CC=gcc
UNAME := $(shell uname)
LEX=flex
YACC=yacc

ifeq ($(UNAME), Linux)
OPTIONS=-g -ll
else
OPTIONS=-g
endif

a: y.tab.c lex.yy.c
	$(CC) $^ $(OPTIONS)

y.tab.c y.tab.h: parser.y
	$(YACC) -yd $< -Wno

lex.yy.c: lexer.l
	$(LEX) $<

clean:
	rm -f *.tab.* *.yy.* *.out *.exe *.o
