%{
    #include "symbol_table.c"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    
    #define YYSTYPE char *

    // Initial declarations of variables
    int type = -1;
    char *vval = "~";
    int vtype = -1;
    int scope = 0;
    int array_size = 1;
    void yyerror(char *s);
    int yylex();
    extern int yylineno;
    extern char *yytext;
%}

%start START
%token T_INT T_CHAR T_DOUBLE T_FLOAT
%token T_WHILE T_IF T_ELSE T_DO T_FOR
%token T_INCLUDE T_MAIN T_HEADER
%token T_OR T_AND
%token T_STRLITERAL
%token T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ
%token T_NUM T_ID
%token T_INCR T_DECR T_OROR T_ANDAND
%token T_TRUE T_FALSE

%%

START   :   PROG {YYACCEPT;}
        ;

PROG    :   T_INCLUDE '<' T_HEADER '>' PROG
        |   MAIN PROG
        |   DECLR ';' PROG
        |   ASSGN ';' PROG
        |   error ';' PROG
        |
        ;

MAIN    :   TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' {++scope;} STMT '}' {--scope;}
        ;

EMPTY_LISTVAR   :   LISTVAR
                |
                ;

STMT    :   STMT_NO_BLOCK STMT
        |   BLOCK STMT
        |
        ;

STMT_NO_BLOCK   :   DECLR ';'
                |   ASSGN ';'
                |   EXPR ';'
                |   T_IF '(' COND ')' {++scope;} STMT {--scope;}
                |   T_IF '(' COND ')' {++scope;} STMT {--scope;} T_ELSE STMT
                |   ITERATOR
                |   ';'
                |   error PROG
                ;

BLOCK   :   '{' STMT '}'
        ;

COND    :   EXPR
        |   ASSGN
        ;

ASSGN   :   T_ID '=' EXPR
        |   ARRID '=' EXPR
        ;

DECLR   :   TYPE LISTVAR
        |   TYPE LISTVAR ARRVAR
        ;

ARRVAR  :   '=' EXPR
        |   INITARR
        ;

TYPE    :   T_INT {type = INT;}
        |   T_FLOAT {type = FLOAT;}
        |   T_DOUBLE {type = DOUBLE;}
        |   T_CHAR {type = CHAR;}
        ;

LISTVAR :   LISTVAR ',' T_ID
        |   LISTVAR ',' ARRID INITARR
        |   ARRID INITARR
        |   T_ID
        ;

ARRID   :   T_ID '[' ARRINDEX ']'
        ;

ARRINDEX    :   T_NUM
            |   EXPR
            ;

INITARR :   '=' '{' ARRCONTENT '}'
        |   '=' T_STRLITERAL
        |
        ;

ARRCONTENT  :   T_NUM
            |   T_NUM ',' ARRCONTENT
            |   T_STRLITERAL ',' ARRCONTENT
            ;

EXPR    :   EXPR LOGICAL_OP E
        |   EXPR BINARY_OP E
        |   EXPR REL_OP E
        ;

LOGICAL_OP  :   T_OROR
            |   T_ANDAND
            ;

BINARY_OP   :   T_OR
            |   T_AND
            ;

REL_OP  :   T_EQCOMP
        |   T_NOTEQUAL
        |   '<'
        |   '>'
        |   T_LESSEREQ
        |   T_GREATEREQ
        ;

