%{
    #include "abstract_syntax_tree.c"
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    void yyerror(char* s);                                          // error handling function
    int yylex();                                                    // declare the function performing lexical analysis
    extern int yylineno;                                            // track the line number
%}

%union                                                              // union to allow nodes to store return different datatypes
{
    char* text;
    expression_node* exp_node;
}



%token <text> T_ID T_NUM T_IF T_ELSE

%type <text> RELOP

%type <exp_node> E T F S C SEQ ASSGN

/* specify start symbol */
%start START


%%
START : SEQ     {
                    display_exp_tree($1->first);
                    printf("Valid syntax\n");
                    YYACCEPT;
                }
        ;

SEQ :   S SEQ   {$$ = init_exp_node(strdup("seq"), init_exp_node(strdup("S"), $1, NULL, NULL, NULL), init_exp_node(strdup("seq"), $2, NULL, NULL, NULL), NULL, NULL);}
    |   S       {$$ = init_exp_node(strdup("S"), $1, NULL, NULL, NULL);}
    |           {$$ = NULL;}
    ;

S   :   T_IF '(' C ')' '{' SEQ '}' SEQ  {$$ = init_exp_node(strdup("if"), $3, $6, NULL, init_exp_node(strdup("seq"), $8, NULL, NULL, NULL));}
    |   T_IF '(' C ')' '{' SEQ '}' T_ELSE '{' SEQ '}' SEQ   {$$ = init_exp_node(strdup("if-else"), $3, $6, $10, init_exp_node(strdup("seq"), $12, NULL, NULL, NULL));}
    |   ASSGN {$$ = $1;}
    ;

C   :   E RELOP E {$$ = init_exp_node(strdup($2), $1, $3, NULL, NULL);}

RELOP   :   '<' {$$ = "<";}
        |   '>' {$$ = ">";}
        |   '>' '=' {$$ = ">=";}
        |   '<' '=' {$$ = "<=";}
        |   '=' '=' {$$ = "==";}
        |   '!' '=' {$$ = "!=";}
        ;

/* Grammar for assignment */
ASSGN : T_ID '=' E ';'  {$$ = init_exp_node(strdup("="), init_exp_node($1, NULL, NULL, NULL, NULL), $3, NULL, NULL);}
    ;

/* Expression Grammar */
E   :   E '+' T {$$ = init_exp_node(strdup("+"), $1, $3, NULL, NULL);}
    |   E '-' T {$$ = init_exp_node(strdup("-"), $1, $3, NULL, NULL);}
    |   T       {$$ = $1;}
    ;
    
    
T   :   T '*' F {$$ = init_exp_node(strdup("*"), $1, $3, NULL, NULL);}
    |   T '/' F {$$ = init_exp_node(strdup("/"), $1, $3, NULL, NULL);}
    |   F       {$$ = $1;}
    ;

F   :   '(' E ')'   {$$ = $2;}
    |   T_ID        {$$ = init_exp_node(strdup($1), NULL, NULL, NULL, NULL);}
    |   T_NUM       {$$ = init_exp_node(strdup($1), NULL, NULL, NULL, NULL);}
    ;

%%


/* error handling function */
void yyerror(char* s)
{
    printf("Error :%s at %d\n", s, yylineno);
}


/* main function - calls the yyparse() function which will in turn drive yylex() as well */
int main(int argc, char* argv[])
{
    yyparse();
    return 0;
}
