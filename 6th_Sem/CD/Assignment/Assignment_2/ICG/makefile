CC=gcc
UNAME := $(shell uname)
LEX=flex
YACC=yacc
ICG_QUAD=icg_quad.txt

ifeq ($(UNAME), Linux)
OPTIONS=-g -ll
OUTPUT=a.out
else
OPTIONS=-g
OUTPUT=a.exe
endif

a: y.tab.c lex.yy.c
	$(CC) $^ $(OPTIONS)

y.tab.c y.tab.h: parser.y
	$(YACC) -yd $< -Wno

lex.yy.c: lexer.l
	$(LEX) $<

clean:
	rm -f *.tab.* *.yy.* *.out *.exe *.o *.txt

test:
	cat test_input_1.c | ./$(OUTPUT)
	@printf "\n"
	cat $(ICG_QUAD)
	@printf "\n"
	cat test_input_2.c | ./$(OUTPUT)
	@printf "\n"
	cat $(ICG_QUAD)
	@printf "\n"
	cat test_input_3.c | ./$(OUTPUT)
	@printf "\n"
	cat $(ICG_QUAD)
	@printf "\n"
	cat test_input_4.c | ./$(OUTPUT)
	@printf "\n"
	cat $(ICG_QUAD)
	@printf "\n"
	cat test_input_5.c | ./$(OUTPUT)
	@printf "\n"
	cat $(ICG_QUAD)

NUMBERS=1 2
run:
	$(foreach val, $(NUMBERS), echo;  cat ./sample_test_$(val).c | ./$(OUTPUT); echo ; cat $(ICG_QUAD); echo ;)
