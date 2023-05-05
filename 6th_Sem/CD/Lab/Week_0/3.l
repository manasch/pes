/*Displaying the line numbers of a file*/

%{
    int yylineno;
%}

%%
(.*)(\n)    printf("%4d\t%s", yylineno++, yytext);
%%

int yywrap() {
    return 1;
}

int main() {
    yyin = fopen("3.l", "r");
    yylex();
    fclose(yyin);
    return 0;
}
