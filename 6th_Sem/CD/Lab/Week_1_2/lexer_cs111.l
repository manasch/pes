%{
    #include <stdio.h>
    #include "y.tab.h"

    extern void yyerror(const char *s);
%}

digit   [0-9]
letter  [a-zA-Z]
id  ({letter}|_)({letter}|{digit}|_)*
digits  {digit}+
fraction    (\.{digits})?
exponent    ([Ee][-+]?{digits})?
number  {digits}{fraction}{exponent}

%%
\/\/.*  ;
"/*"([^*]|\*+[^*/])*\*+"/" {++yylineno;}
[' '\t\f\r]    ;
\n  {++yylineno;}

"#include"  {return T_INCLUDE;}
"main"   {return T_MAIN;}
"int"   {return T_INT;}
"char"  {return T_CHAR;}
"float"  {return T_FLOAT;}
"double"  {return T_DOUBLE;}
"void"  {return T_VOID;}
"while" {return T_WHILE;}
"switch"    {return T_SWITCH;}
"default"   {return T_DEFAULT;}
[\'\"](.*)[\'\"]   {return T_STRLITERAL;}
"for" {return T_FOR;}
"do" {return T_DO;}
"if" {return T_IF;}
"else" {return T_ELSE;}
"<="    {return T_LE;}
">="    {return T_GE;}
"<"     {return T_LT;}
">"     {return T_GT;}
"=="    {return T_EQ;}
"!="    {return T_NEQ;}
"++"    {return T_INC;}
"--"    {return T_DEC;}
"||"    {return T_LOR;}
"&&"    {return T_AND;}
"*" {return T_MUL;}
"/" {return T_DIV;}
"+" {return T_PLU;}
"-" {return T_MIN;}
"=" {return T_ASGN;}
"!" {return T_LNOT;}
"|" {return T_BOR;}
"&" {return T_BAND;}
"^" {return T_BXOR;}
"(" {return T_OB;}
")" {return T_CB;}
"[" {return T_SOB;}
"]" {return T_SCB;}
"{" {return T_COB;}
"}" {return T_CCB;}
";" {return *yytext;}
"," {return T_COM;}
{number}    {return T_NUM;}
{id}\.[hHcC]  {return T_HEADER;}
{id}    {return T_ID;}
.   {yyerror("Unrecognized Token");}
%%

int yywrap() {
    return 1;
}
