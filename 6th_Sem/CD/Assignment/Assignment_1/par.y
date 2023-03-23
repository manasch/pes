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

DECLR   :   TYPE LISTVAR
        ;

LISTVAR :   LISTVAR ',' VAR
        |   VAR
        ;

VAR :   T_ID '=' EXPR   {
                            if (check_sym_tab($1)) {
                                // printf("Variable %s is already declared\n", $1);
                                yyerror(strdup("Variable is already declared"));
                            }
                            else {
                                insert_symbol($1, size(type), type, yylineno, scope);
                                insert_val($1, vval, yylineno);
                                // vval = "~";
                                // type = -1;
                            }
                        }
    |   T_ID            {
                            if (check_sym_tab($1)) {
                                // printf("Variable %s is already declared\n", $1);
                                yyerror(strdup("Variable is already declared"));
                            }
                            else {
                                insert_symbol($1, size(type), type, yylineno, scope);
                                // type = -1;
                            }
                        }

// Assign type here to be returned to the declaration grammar
TYPE    :   T_INT {type = INT;}
        |   T_FLOAT {type = FLOAT;}
        |   T_DOUBLE {type = DOUBLE;}
        |   T_CHAR {type = CHAR;}
        ;

// Grammar for assignment
ASSGN   :   T_ID {type = retrieve_type($1);} '=' EXPR   {
                                                            if (!check_sym_tab($1)) {
                                                                // printf("Variable %s is not declared\n", $1);
                                                                yyerror(strdup("Variable is not declared"));
                                                            }
                                                            insert_val($1, vval, yylineno);
                                                            // vval = "~";
                                                            // type = -1;
                                                        }
        ;

EXPR    :   EXPR REL_OP E
        |   EXPR LOGICAL_OP E
        |   E UNARY
        |   E {vval = $1;}
        ;

UNARY   :   T_INCR
        |   T_DECR
        ;

// Expression grammar
E   :   E '+' T {
                    if (vtype == 2) // Int
                        sprintf($$, "%d", (atoi($1) + atoi($3)));
                    else if (vtype == 3)    // Float or Double
                        sprintf($$, "%lf", (atof($1) + atof($3)));
                    else {
                        // printf("Character used in arithmetic\n");
                        yyerror(strdup("Character used in arithmetic"));
                        $$ = "~";
                    }
                }
    |   E '-' T {
                    if (vtype == 2) // Int
                        sprintf($$, "%d", (atoi($1) - atoi($3)));
                    else if (vtype == 3)    // Float or Double
                        sprintf($$, "%lf", (atof($1) - atof($3)));
                    else {
                        // printf("Character used in arithmetic\n");
                        yyerror(strdup("Character used in arithmetic"));
                        $$ = "~";
                    }
                }
    |   T {$$ = $1;}
    ;

T   :   T '*' F {
                    if (vtype == 2)
                        sprintf($$, "%d", (atoi($1) * atoi($3)));
                    else if (vtype == 3)
                        sprintf($$, "%lf", (atof($1) * atof($3)));
                    else {
                        // printf("Character used in arithmetic\n");
                        yyerror(strdup("Character used in arithmetic"));
                        $$ = "~";
                    }
                }
    |   T '/' F {
                    if (vtype == 2)
                        sprintf($$, "%d", (atoi($1) / atoi($3)));
                    else if (vtype == 3)
                        sprintf($$, "%lf", (atof($1) / atof($3)));
                    else {
                        // printf("Character used in arithmetic\n");
                        yyerror(strdup("Character used in arithmetic"));
                        $$ = "~";
                    }
                }
    |   F {$$ = $1;}
    ;

F   :   '(' EXPR ')'
    |   T_ID    {
                    if (check_sym_tab($1)) {
                        char *val_check = retrieve_val($1);
                        if (strcmp(val_check, "~") == 0) {
                            // printf("Variable %s is not initialized\n", $1);
                            yyerror(strdup("Variable is not initialized"));
                        }
                        else {
                            $$ = strdup(val_check);
                            vtype = type_check(val_check);
                            // Checks for matching type
                            if (vtype != type && type != -1) {
                                // printf("Mismatch type\n");
                                yyerror(strdup("Mismatch type"));
                            }
                        }
                    }
                }
    |   T_NUM   {
                    $$ = strdup($1);
                    vtype = type_check($1);
                    // Checks for matching type
                    if (vtype != type && type != -1) {
                        // printf("Mismatch type\n");
                        yyerror(strdup("Mismatch type"));
                    }
                }
    |   T_STRLITERAL    {
                            $$ = strdup($1);
                            vtype = 1; // type_check($1);
                            // Checks for matching type
                            if (vtype != type) {
                                // printf("Mismatch type\n");
                                yyerror(strdup("Mismatch type"));
                            }
                        }
    ;

REL_OP  :   T_LESSEREQ
        |   T_GREATEREQ
        |   '<'
        |   '>'
        |   T_EQCOMP
        |   T_NOTEQUAL
        ;

LOGICAL_OP  :   T_OROR
            |   T_ANDAND
            ;

// Grammar for main function
MAIN    :   TYPE T_MAIN '(' EMPTY_LISTVAR ')' '{' {++scope;} STMT '}' {--scope;}
        ;

// Arguement list can be empty, or have a list of variables
EMPTY_LISTVAR   :   LISTVAR
                |   // Lambda
                ;

// Statments can be standalone, or parts of blocks
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
                |   error
                ;

ITERATOR    :   WHILE
            |   DO
            |   FOR
            ;

DO  :   T_DO WHILE_BODY WHILE

FOR :   T_FOR '(' FOR_COND  ';' STMT ';' EXPR ')' '{' {++scope;} STMT '}' {--scope;}

FOR_COND    :   DECLR
            |   ASSGN
            ;

WHILE   :   T_WHILE '(' COND ')' WHILE_BODY
        ;

WHILE_BODY  :   STMT_NO_BLOCK
            |   BLOCK
            |
            ;

BLOCK   :   '{' {++scope;} STMT '}' {--scope;}
        ;

COND    :   EXPR
        |   ASSGN
        ;

%%

// Error handling function
void yyerror(char *s) {
    printf("Error: %s, line number: %d, token: %s\n", s, yylineno, yytext);
}

int main(int argc, char *argv[]) {
    t = init_table();
    if (!yyparse())
        printf("Parsing Successful\n");
    else
        printf("Parsing Unsuccessful\n");
    
    printf("\n-----Symbol Table-----\n");
    display_sym_tab();
    return 0;
}

