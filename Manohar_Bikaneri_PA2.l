%{
#include <stdio.h>
#include <string.h>
#include "Manohar_Bikaneri_PA2.tab.h"

%}

%option noyywrap
/* ---------- Definitions ---------- */
WS              [ \t\r\n]+
LOWER           [a-z]
UPPER           [A-Z]
DIGIT           [0-9]
NZDIGIT         [1-9]
ID              {LOWER}+
ESCCHAR         \\[nt'"]
MATSYMBL	[=+/*-]
STRPNCTR	[][,./\\|;:{}[_!@#$%^&*]

/* Integer constants: either 0 OR optional sign FOLLOWED BY nonzero-first integer */
INTCONST        0|[-+]?{NZDIGIT}{DIGIT}*

/* String literal: single quotes, zero or more of letters/digits/space */
SCHAR           {LOWER}|{UPPER}|{DIGIT}|{ESCCHAR}|{MATSYMBL}|{STRPNCTR}|[ ]
STRINGL          \'({SCHAR})*\'

/* Single-line comment in { ... }, no newline */
COMMENT         \{[^}\n]*\}

/* ---------- Rules ---------- */
%%
{COMMENT}               { /* ignore */ }
{WS}                    { /* ignore */ }
PROGRAM 		{ return PROGRAM; }
FUNCTION 		{ return FUNCTION; }
VAR 			{ return VAR; }
INTEGER			{ return INTEGER; }
STRING 			{ return STRING; }
WHILE 			{ return WHILE; }
DO			{ return DO; }
IF 			{ return IF; }
THEN 			{ return THEN; }
ELSE			{ return ELSE; }
BEGIN			{ return BEGIN_;}
END			{ return END_;} 
{ID}                    { return identifier; }
{INTCONST}              { return constant; }
{STRINGL}                { return string_literal; }
"<="|">="|"<>"          { return relop; }
":="			{ return assignop; }
"*"                     { return mulop; }
"/"                     { return mulop; }
"+"                     { return addop; }
"("                     { return LPAREN; }
")"                     { return RPAREN; }
"<"                     { return relop; }
">"                     { return relop; }
"="                     { return relop; }
","                     { return comma; }
";"                     { return semicolon; }
"."                     { return period; }
":"                     { return colon; }
"-"                     { return addop; }
.                       { return -1; }
%%
