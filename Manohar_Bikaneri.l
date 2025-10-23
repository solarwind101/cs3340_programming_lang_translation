%{
#include <stdio.h>
#include <string.h>
#include "Manohar_Bikaneri.tab.h"

%}

%option noyywrap
/* ---------- Definitions ---------- */
WS              [ \t\r\n]+
LOWER           [a-z]
UPPER           [A-Z]
DIGIT           [0-9]
NZDIGIT         [1-9]
ID              {LOWER}+

/* Integer constants: either 0 OR optional sign FOLLOWED BY nonzero-first integer */
INTCONST        0|[-+]?{NZDIGIT}{DIGIT}*

/* String literal: single quotes, zero or more of letters/digits/space */
SCHAR           {LOWER}|{UPPER}|{DIGIT}|[ ]
STRING          \'({SCHAR})*\'

/* Single-line comment in { ... }, no newline */
COMMENT         \{[^}\n]*\}

/* ---------- Rules ---------- */
%%
{COMMENT}               { /* ignore */ }
{WS}                    { /* ignore */ }
PROGRAM|FUNCTION|VAR|INTEGER|STRING|WHILE|DO|IF|THEN|ELSE|BEGIN|END { OUT("KEYWORD"); }
{ID}                    { OUT("IDENTIFIER"); }
{INTCONST}              { OUT("CONSTANT"); }
{STRING}                { OUT("STRING_LITERAL"); }
"<="|">="|"<>"|":="     { OUT("PUNCTUATOR"); }
"*"                     { OUT("PUNCTUATOR"); }
"/"                     { OUT("PUNCTUATOR"); }
"+"                     { OUT("PUNCTUATOR"); }
"("                     { OUT("PUNCTUATOR"); }
")"                     { OUT("PUNCTUATOR"); }
"<"                     { OUT("PUNCTUATOR"); }
">"                     { OUT("PUNCTUATOR"); }
"="                     { OUT("PUNCTUATOR"); }
","                     { OUT("PUNCTUATOR"); }
";"                     { OUT("PUNCTUATOR"); }
"."                     { OUT("PUNCTUATOR"); }
":"                     { OUT("PUNCTUATOR"); }
"-"                     { OUT("PUNCTUATOR"); }
.                       { OUT("UNRECOGNIZED_CHARACTER"); }
%%
