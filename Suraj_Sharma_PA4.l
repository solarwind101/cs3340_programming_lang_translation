%{
#include <stdio.h>
#include <string.h>
#include "Suraj_Sharma_PA4_translator.h"
#include "Suraj_Sharma_PA4.tab.h"
%}

%option noyywrap
%option yylineno

WS              [ \t\r\n]+
LOWER           [a-z]
UPPER           [A-Z]
DIGIT           [0-9]
NZDIGIT         [1-9]
ID              {LOWER}+
ESCCHAR         \\[nt'"]
MATSYMBL        [=+/*-]
STRPNCTR        [][,./\\|;:{}[_!@#$%^&*]
INTCONST        0|[-+]?{NZDIGIT}{DIGIT}*
SCHAR           {LOWER}|{UPPER}|{DIGIT}|{ESCCHAR}|{MATSYMBL}|{STRPNCTR}|[ ]
STRINGL         \'({SCHAR})*\'
COMMENT         \{[^}\n]*\}

%%
{COMMENT}               { }
{WS}                    { }
PROGRAM                 { return PROGRAM; }
FUNCTION                { return FUNCTION; }
VAR                     { return VAR; }
INTEGER                 { return INTEGER; }
STRING                  { return STRING; }
WHILE                   { return WHILE; }
DO                      { return DO; }
IF                      { return IF; }
THEN                    { return THEN; }
ELSE                    { return ELSE; }
BEGIN                   { return BEGIN_; }
END                     { return END_; } 

{ID}                    { yylval.sym = lookupSymbol(yytext); return identifier; }
{INTCONST}              { yylval.num = atoi(yytext); return constant; }
{STRINGL}               { yylval.sval = strdup(yytext); return string_literal; }

"<="                    { yylval.num = RELOP_LE; return relop; }
">="                    { yylval.num = RELOP_GE; return relop; }
"<>"                    { yylval.num = RELOP_NE; return relop; }
"<"                     { yylval.num = RELOP_LT; return relop; }
">"                     { yylval.num = RELOP_GT; return relop; }
"="                     { yylval.num = RELOP_EQ; return relop; }

":="                    { return assignop; }
"*"                     { yylval.num = '*'; return mulop; }
"/"                     { yylval.num = '/'; return mulop; }
"+"                     { yylval.num = '+'; return addop; }
"-"                     { yylval.num = '-'; return addop; }

"("                     { return LPAREN; }
")"                     { return RPAREN; }
","                     { return comma; }
";"                     { return semicolon; }
"."                     { return period; }
":"                     { return colon; }

.                       { printf("Parsing Error: Unknown character '%s' at line %d\n", yytext, yylineno); return -1; }
%%
