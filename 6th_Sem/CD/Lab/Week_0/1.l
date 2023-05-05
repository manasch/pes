%{
    #include<stdio.h>
%}

%%
"HI"    {printf("BYE\n");}
.*      {printf("WRONG\n");}
%%

int yywrap() {
    return 1;
}

int main() {
    printf("Enter the string\n");
    yylex();
    return 0;
}
