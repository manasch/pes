%{
    #define YYSTYPE char*
    // #define DEBUG
    #ifdef DEBUG
    #define DISP printf("Token @ %d: %s\n", yylineno, yytext)
    #else
    #define DISP do {} while(0)
    #endif
    
    #include "y.tab.h"
    #include <stdio.h>
    extern void yyerror(const char *); // declare the error handling function
    extern YYSTYPE yylval;
%}

/* Regular definitions */
digit   [0-9]
letter  [a-zA-Z_]
id  {letter}({letter}|{digit})*
digits  {digit}+
opFraction  (\.{digits})?
opExponent  ([Ee][+-]?{digits})?
number  {digits}{opFraction}{opExponent}
%option yylineno

%option noyywrap

%%
[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] ;
\/\/(.*) ; // ignore comments
[\t\n] ; // ignore whitespaces
"int"       {DISP; return T_INT;}
"char"      {DISP; return T_CHAR;}
"double"    {DISP; return T_DOUBLE;}
"float"	    {DISP; return T_FLOAT;}
"while"     {DISP; return T_WHILE;}
"if"        {DISP; return T_IF;}
"else"      {DISP; return T_ELSE;}
"do"        {DISP; return T_DO;}
"#include"  {DISP; return T_INCLUDE;}
"main"      {DISP; return T_MAIN;}
"for"       {DISP; return T_FOR;}
"true"      {DISP; return T_TRUE;}
"false"     {DISP; return T_FALSE;}
\".*\"      {yylval = strdup(yytext); DISP; return T_STRLITERAL;}
"=="        {DISP; return T_EQCOMP;}
"!="        {DISP; return T_NOTEQUAL;}
">="        {DISP; return T_GREATEREQ;}
"<="        {DISP; return T_LESSEREQ;}
"++"        {DISP; return T_INCR;}
"--"        {DISP; return T_DECR;}
"("         {DISP; return *yytext;}
")"         {DISP; return *yytext;}
"["         {DISP; return *yytext;}
"]"         {DISP; return *yytext;}
"."         {DISP; return *yytext;}
","         {DISP; return *yytext;}
"{"         {DISP; return *yytext;}
"}"         {DISP; return *yytext;}
"*"         {DISP; return *yytext;}
"+"         {DISP; return *yytext;}
";"         {DISP; return *yytext;}
"-"         {DISP; return *yytext;}
"/"         {DISP; return *yytext;}
"="         {DISP; return *yytext;}
">"         {DISP; return *yytext;}
"<"         {DISP; return *yytext;}
"!"         {DISP; return *yytext;}
"|"         {DISP; return T_OR;}
"&"         {DISP; return T_AND;}
"||"        {DISP; return T_OROR;}
"&&"        {DISP; return T_ANDAND;}
{number}    {
            yylval = strdup(yytext);  //stores the value of the number to be used later for symbol table insertion
            DISP;
            return T_NUM;
            }
{id}\.h {DISP; return T_HEADER;}  // ending in .h => header file name
{id}    {
            yylval = strdup(yytext); //stores the identifier to be used later for symbol table insertion
            DISP;
            return T_ID;
        }
.       {} // anything else => ignore
%%

// This is required for cygwin gcc atleast, without which it doesn't work
// int yywrap() {
//     DISP; return 1;
// }
