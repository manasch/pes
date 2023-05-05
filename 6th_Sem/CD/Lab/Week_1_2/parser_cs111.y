%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    int yylex();
    void yyerror(const char *);
    extern int yylineno;
    extern char *yytext;
    int errCount = 0;
    
%}

%start  S
%token  T_INT T_CHAR T_FLOAT T_DOUBLE T_VOID
%token  T_WHILE T_SWITCH T_DEFAULT
%token  T_FOR T_DO
%token  T_IF T_ELSE
%token  T_MAIN T_INCLUDE T_HEADER
%token  T_LE T_GE T_LT T_GT T_EQ T_NEQ
%token  T_ID T_NUM T_STRLITERAL
%token  T_INC T_DEC T_LOR T_AND
%token  T_LNOT T_BOR T_BAND T_BXOR
%token  T_MUL T_DIV T_PLU T_MIN T_ASGN
%token  T_OB T_CB T_SOB T_SCB T_COB T_CCB
%token  T_COM

%%
S   :   PROG {if (errCount == 0) {printf("Valid Syntax\n"); YYACCEPT;}}
    ;

PROG    :   T_INCLUDE T_LT T_HEADER T_GT PROG
        |   MAIN PROG
        |   DECLR ';' PROG
        |   ASSGN ';' PROG
        |   error ';' PROG
        |
        ;

DECLR   :   TYPE LISTVAR
        ;

LISTVAR :   LISTVAR T_COM T_ID
        |   T_ID
        ;

TYPE    :   T_INT
        |   T_FLOAT
        |   T_DOUBLE
        |   T_CHAR
        ;

ASSGN   :   T_ID T_ASGN EXPR
        ;

EXPR    :   EXPR RELOP E
        |   E
        ;

E   :   E T_PLU T
    |   E T_MIN T
    |   T
    ;

T   :   T T_MUL F
    |   T T_DIV F
    |   F
    ;

F   :   T_OB EXPR T_CB
    |   T_ID
    |   T_NUM
    |   T_STRLITERAL
    ;

RELOP   :   T_LT
        |   T_GT
        |   T_LE
        |   T_GE
        |   T_EQ
        |   T_NEQ
        ;

MAIN    :   TYPE T_MAIN T_OB EMPTY_LISTVAR T_CB T_COB STMT T_CCB
        ;

EMPTY_LISTVAR   :   LISTVAR
                |
                ;

STMT    :   SINGLESTMT STMT
        |   BLOCK STMT
        |
        ;

SINGLESTMT  :   DECLR ';'
            |   ASSGN ';'
            |   T_IF T_OB COND T_CB STMT
            |   T_IF T_OB COND T_CB STMT T_ELSE STMT
            |   WHILE_LOOP
            |   error ';'
            ;

BLOCK   :   T_COB STMT T_CCB
        ;

WHILE_LOOP  :   T_WHILE T_OB COND T_CB WHILE_LOOP
            |   WHILE_BODY
            ;

COND    :   EXPR
        |   ASSGN
        ;

WHILE_BODY  :   T_COB STMT T_CCB
            |
            ;

%%

void yyerror(const char *s) {
    printf("Error: %s, line number: %d, token: %s\n", s, yylineno, yytext);
}

int main() {
    yyparse();
    return 0;
}
