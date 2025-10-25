%{
#include <stdio.h>
#include <stdlib.h>

int yylex(void);
void yyerror(const char *s);

%}

/* Token declarations */
%token PROGRAM FUNCTION VAR INTEGER STRING WHILE DO IF THEN ELSE BEGIN_ END_
%token identifier constant string_literal
%token relop assignop mulop addop
%token LPAREN RPAREN comma semicolon colon period


/* Start symbol */
%start program
%nonassoc THEN
%nonassoc ELSE

%%
program:
	PROGRAM identifier semicolon declaration_list_opt function_declaration_list_opt compound_statement period 
	;

declaration_list_opt:
	declaration_list |
	;
	
declaration_list:
	declaration_list_opt VAR variable_list colon type semicolon
	;

variable_list: 
	identifier |
	variable_list comma identifier
	;

type:
	INTEGER |
	STRING
	;

function_declaration_list_opt:
	function_declaration_list |
	;

function_declaration_list:
	function_declaration_list_opt function_declaration semicolon
	;

function_declaration:
	function_header declaration_list_opt compound_statement
	;

function_header:
	FUNCTION identifier LPAREN parameter_list RPAREN colon type semicolon 
	;
	
parameter_list:
	variable_list colon type |
	parameter_list semicolon variable_list colon type
	;
	
compound_statement:
	BEGIN_ statement_list END_
	;
	
statement_list:
	statement |
	statement_list semicolon statement
	;

statement:
	identifier assignop expression |
	selection_statement |
	iteration_statement |
	compound_statement |
	function_statement /* To deal with function calls such as writeln, readln etc */
	;
selection_statement:
	IF expression THEN statement ELSE statement  |
	IF expression THEN statement %prec THEN
	;

iteration_statement:
	WHILE expression DO statement
	;
function_statement:
	identifier LPAREN expression_list RPAREN 
	;
	
expression_list:
	expression |
	expression_list comma expression
	;

expression:
	simple_expression |
	simple_expression relop simple_expression
	;

simple_expression:
	term |
	simple_expression addop term
	;
term:
	factor |
	term mulop factor
	;
factor:
	identifier |
	constant |
	string_literal |
	LPAREN expression RPAREN |
	identifier LPAREN expression_list RPAREN 
	;
	
		
%%

void yyerror(const char *s) {
    printf("%s\n",s);
}

