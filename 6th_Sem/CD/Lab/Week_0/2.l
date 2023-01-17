/*Checking if the entered string is a valid or invalid identifier*/
%{
    #include<stdio.h>
%}

%%
[_a-zA-Z]([_a-zA-Z]|[0-9])* printf("Valid Identifier: %s\n", yytext);
.*  printf("Invalid Identifier: %s\n", yytext);
\n
%%

int yywrap() {
    return 1;
}

int main() {
    yylex();
    return 0;
}
