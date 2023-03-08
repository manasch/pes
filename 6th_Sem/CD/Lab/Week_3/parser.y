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
    void yyerror(char *s);
    int yylex();
    extern int yylineno;
%}

%start START
%token T_INT T_CHAR T_DOUBLE T_FLOAT
%token T_WHILE T_IF T_ELSE T_DO
%token T_INCLUDE T_MAIN T_HEADER
%token T_STRLITERAL
%token T_EQCOMP T_NOTEQUAL T_GREATEREQ T_LESSEREQ
%token T_NUM T_ID

%%

START   :   PROG {printf("Valid syntax\n"); YYACCEPT;}
        ;

PROG    :   MAIN PROG
        |   DECLR ';' PROG
        |   ASSGN ';' PROG
        |
        ;

DECLR   :   TYPE LISTVAR
        ;

LISTVAR :   LISTVAR ',' VAR
        |   VAR
        ;

VAR :   T_ID '=' EXPR   {
                            if (check_sym_tab($1)) {
                                printf("Variable %s is already declared\n", $1);
                                yyerror($1);
                            }
                            else {
                                insert_symbol($1, size(type), type, yylineno, scope);
                                insert_val($1, vval, yylineno);
                                vval = "~";
                                type = -1;
                            }
                        }
    |   T_ID            {
                            if (check_sym_tab($1)) {
                                printf("Variable %s is already declared\n", $1);
                                yyerror($1);
                            }
                            else {
                                insert_symbol($1, size(type), type, yylineno, scope);
                                type = -1;
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
                                                                printf("Variable %s is not declared\n", $1);
                                                                yyerror($1);
                                                            }
                                                            insert_val($1, vval, yylineno);
                                                            vval = "~";
                                                            type = -1;
                                                        }
        ;

EXPR    :   EXPR REL_OP E
        |   E {vval = $1;}
        ;

// Expression grammar
E   :   E '+' T {
                    if (vtype == 2) // Int
                        sprintf($$, "%d", (atoi($1) + atoi($3)));
                    else if (vtype == 3)    // Float or Double
                        sprintf($$, "%lf", (atof($1) + atof($3)));
                    else {
                        printf("Character used in arithmetic\n");
                        yyerror($$);
                        $$ = "~";
                    }
                }
    |   E '-' T {
                    if (vtype == 2) // Int
                        sprintf($$, "%d", (atoi($1) - atoi($3)));
                    else if (vtype == 3)    // Float or Double
                        sprintf($$, "%lf", (atof($1) - atof($3)));
                    else {
                        printf("Character used in arithmetic\n");
                        yyerror($$);
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
                        printf("Character used in arithmetic\n");
                        yyerror($$);
                        $$ = "~";
                    }
                }
    |   T '/' F {
                    if (vtype == 2)
                        sprintf($$, "%d", (atoi($1) / atoi($3)));
                    else if (vtype == 3)
                        sprintf($$, "%lf", (atof($1) / atof($3)));
                    else {
                        printf("Character used in arithmetic\n");
                        yyerror($$);
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
                            printf("Variable %s is not initialized\n", $1);
                            yyerror($1);
                        }
                        else {
                            $$ = strdup(val_check);
                            vtype = type_check(val_check);
                            // Checks for matching type
                            if (vtype != type && type != -1) {
                                printf("Mismatch type\n");
                                yyerror($1);
                            }
                        }
                    }
                }
    |   T_NUM   {
                    $$ = strdup($1);
                    vtype = type_check($1);
                    // Checks for matching type
                    if (vtype != type && type != -1) {
                        printf("Mismatch type\n");
                        yyerror($1);
                    }
                }
    |   T_STRLITERAL    {
                            $$ = strdup($1);
                            vtype = 1; // type_check($1);
                            // Checks for matching type
                            if (vtype != type) {
                                printf("Mismatch type\n");
                                yyerror($1);
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
                ;

BLOCK   :   '{' {++scope;} STMT '}' {--scope;}
        ;

COND    :   EXPR
        |   ASSGN
        ;

%%

// Error handling function
void yyerror(char *s) {
    printf("Error: %s at Line %d\n", s, yylineno);
}

int main(int argc, char *argv[]) {
    t = init_table();
    yyparse();
    display_sym_tab();
    return 0;
}
