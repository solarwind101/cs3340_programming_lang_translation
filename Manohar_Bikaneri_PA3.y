%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Manohar_Bikaneri_PA3_translator.h"

int yylex(void);
void yyerror(const char *s);
extern int yylineno; 
extern char *yytext;
%}

%union {
    int num;
    char *sval;
    symbol *sym;
    exprattr expr;
    stmtattr stmt;
    markerattr mark;
    intlist *ilist;
    symlist *slist;
    arglist *alist;
}

%token PROGRAM FUNCTION VAR INTEGER STRING WHILE DO IF THEN ELSE BEGIN_ END_
%token <sym> identifier
%token <num> constant
%token <sval> string_literal
%token <num> relop
%token <num> addop
%token <num> mulop

%token LPAREN RPAREN comma semicolon colon period assignop

/* precedence */
%nonassoc THEN
%nonassoc ELSE


%type <expr> expression simple_expression term factor
%type <stmt> statement statement_list compound_statement
%type <stmt> selection_statement iteration_statement function_statement
%type <mark> M
%type <slist> variable_list
%type <sval> type
%type <alist> expression_list
%type <sym> function_intro

/* Start Symbol */
%start program

%%

program:
        PROGRAM identifier semicolon declaration_list_opt function_declaration_list_opt compound_statement period
        {
            emit(OP_STOP, NULL, NULL, NULL);
        }
        ;

declaration_list_opt:
        declaration_list |
        ;

declaration_list:
        declaration_list_opt VAR variable_list colon type semicolon
        {
            symlist *curr = $3;
            int size = (strcmp($5, "INTEGER") == 0) ? SIZE_INT : SIZE_STRING;
            while (curr) {
                updateSymbolInfo(curr->sym, $5, size, "local");
                curr = curr->next;
            }
        }
        ;

variable_list:
        identifier
        {
            $$ = makeSymList($1);
        }
    |   variable_list comma identifier
        {
            $$ = mergeSymLists($1, makeSymList($3));
        }
        ;

type:
        INTEGER { $$ = "INTEGER"; }
    |   STRING  { $$ = "STRING"; }
        ;

function_declaration_list_opt:
        function_declaration_list |
        ;

function_declaration_list:
        function_declaration_list_opt function_declaration semicolon
        ;

function_declaration:
        function_header declaration_list_opt compound_statement
        {
            /* Return to parent scope */
            if (ST_current && ST_current->parent) {
                ST_current = find_symboltable_by_name(ST_current->parent);
            }
            emit(OP_RETURN, NULL, NULL, NULL); 
        }
        ;


function_intro:
        FUNCTION identifier
        {
            ST_current = createSymbolTable($2->name);
            $2->nested_symboltable_name = xstrdup($2->name);
            $$ = $2; 
        }
        ;

function_header:
        function_intro LPAREN parameter_list RPAREN colon type semicolon
        {
       
            updateSymbolInfo($1, $6, 0, NULL); 
            
            symbol *retVar = lookupSymbol($1->name);
            updateSymbolInfo(retVar, $6, SIZE_INT, "return_var");
        }
        ;

parameter_list:
        variable_list colon type 
        {
             symlist *curr = $1;
             int size = (strcmp($3, "INTEGER") == 0) ? SIZE_INT : SIZE_STRING;
             while (curr) {
                updateSymbolInfo(curr->sym, $3, size, "param");
                curr = curr->next;
             }
        }
    |   parameter_list semicolon variable_list colon type
        {
             symlist *curr = $3;
             int size = (strcmp($5, "INTEGER") == 0) ? SIZE_INT : SIZE_STRING;
             while (curr) {
                updateSymbolInfo(curr->sym, $5, size, "param");
                curr = curr->next;
             }
        }
        ;

compound_statement:
        BEGIN_ statement_list END_
        {
            $$ = $2;
        }
        ;

statement_list:
        statement 
        {
            $$ = $1;
        }
    |   statement_list semicolon statement
        {
            stmtattr res;
            if ($1.nextlist) backpatch($1.nextlist, $3.nextlist ? ((markerattr*)(&($3)))->instr : nextinstr()); 
            res.nextlist = $3.nextlist;
            $$ = res;
        }
        ;

statement:
        identifier assignop expression
        {
            stmtattr res;
            res.nextlist = NULL;
            if ($3.place) emit(OP_COPY, $3.place->name, NULL, $1->name);
            $$ = res;
        }
    |   selection_statement
    |   iteration_statement
    |   compound_statement
    |   function_statement
    ;

selection_statement:
    IF expression THEN M statement ELSE M statement
    {
        backpatch($2.truelist, $4.instr);
        backpatch($2.falselist, $7.instr);
        stmtattr res;
        res.nextlist = mergeLists($5.nextlist, $8.nextlist);
        res.nextlist = mergeLists(res.nextlist, $2.is_boolean ? NULL : NULL); 
        $$ = res;
    }
  | IF expression THEN M statement %prec THEN
    {
        backpatch($2.truelist, $4.instr);
        stmtattr res;
        res.nextlist = mergeLists($5.nextlist, $2.falselist);
        $$ = res;
    }
  ;

iteration_statement:
    WHILE M expression DO M statement
    {
        backpatch($3.truelist, $5.instr);
        backpatch($6.nextlist, $2.instr);
        char *t_start = int_to_str($2.instr);
        emit(OP_GOTO, NULL, NULL, t_start);
        free(t_start);
        stmtattr res;
        res.nextlist = $3.falselist;
        $$ = res;
    }
  ;

function_statement:
    identifier LPAREN expression_list RPAREN
    {
        stmtattr res;
        res.nextlist = NULL;
        
        if (strcmp($1->name, "readln") == 0 || strcmp($1->name, "read") == 0) {
            arglist *cur = $3;
            while(cur) {
                emit(OP_READ, cur->name, NULL, NULL);
                cur = cur->next;
            }
        } 
        else if (strcmp($1->name, "writeln") == 0 || strcmp($1->name, "write") == 0) {
             arglist *cur = $3;
            while(cur) {
                emit(OP_PRINT, cur->name, NULL, NULL);
                cur = cur->next;
            }
        }
        else {
            int argc = 0;
            arglist *cur = $3;
            while (cur) {
                emit(OP_PARAM, cur->name, NULL, NULL);
                argc++;
                cur = cur->next;
            }
            char buf[10];
            snprintf(buf, 10, "%d", argc);
            emit(OP_CALL, $1->name, buf, NULL); 
        }
        $$ = res;
    }
  ;

expression_list:
    expression 
    {
        $$ = makeArgList($1.place ? $1.place->name : "");
    }
    | expression_list comma expression
    {
        $$ = mergeArgLists($1, makeArgList($3.place ? $3.place->name : ""));
    }
    ;

expression:
    simple_expression
    {
        $$ = $1;
    }
  | simple_expression relop simple_expression
    {
        exprattr res;
        res.is_boolean = 1;
        res.place = NULL;
        
        Opcode op = OP_IF_EQ; 
        switch($2) {
            case RELOP_LT: op = OP_IF_LT; break;
            case RELOP_LE: op = OP_IF_LE; break;
            case RELOP_GT: op = OP_IF_GT; break;
            case RELOP_GE: op = OP_IF_GE; break;
            case RELOP_EQ: op = OP_IF_EQ; break;
            case RELOP_NE: op = OP_IF_NE; break;
        }

        res.truelist = makeList(nextinstr());
        res.falselist = makeList(nextinstr() + 1);
        emit(op, $1.place ? $1.place->name : NULL, $3.place ? $3.place->name : NULL, NULL);
        emit(OP_GOTO, NULL, NULL, NULL);
        $$ = res;
    }
  ;

simple_expression:
    term
    {
        $$ = $1;
    }
  | simple_expression addop term
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("INTEGER");
        if ($2 == '+') emit(OP_ADD, $1.place ? $1.place->name : NULL, $3.place ? $3.place->name : NULL, t->name);
        else emit(OP_SUB, $1.place ? $1.place->name : NULL, $3.place ? $3.place->name : NULL, t->name);
        res.place = t;
        $$ = res;
    }
  ;

term:
    factor
    {
        $$ = $1;
    }
  | term mulop factor
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("INTEGER");
        if ($2 == '*') emit(OP_MUL, $1.place ? $1.place->name : NULL, $3.place ? $3.place->name : NULL, t->name);
        else emit(OP_DIV, $1.place ? $1.place->name : NULL, $3.place ? $3.place->name : NULL, t->name);
        res.place = t;
        $$ = res;
    }
  ;

factor:
    identifier
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        res.place = $1;
        $$ = res;
    }
  | constant
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("INTEGER");
        char *lit = int_to_str($1);
        emit(OP_COPY, lit, NULL, t->name);
        free(lit);
        res.place = t;
        $$ = res;
    }
  | string_literal
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        symbol *t = genTemp("STRING");
        emit(OP_COPY, $1, NULL, t->name);
        free($1);
        res.place = t;
        $$ = res;
    }
  | LPAREN expression RPAREN
    {
        $$ = $2;
    }
  | identifier LPAREN expression_list RPAREN
    {
        exprattr res;
        res.is_boolean = 0;
        res.truelist = res.falselist = NULL;
        
        int argc = 0;
        arglist *cur = $3;
        while (cur) {
            emit(OP_PARAM, cur->name, NULL, NULL);
            argc++;
            cur = cur->next;
        }

        symbol *t = genTemp("INTEGER");
        char buf[10];
        snprintf(buf, 10, "%d", argc);
        emit(OP_CALL, $1->name, buf, t->name);
        res.place = t;
        $$ = res;
    }
  ;

M:
    {
        markerattr m;
        m.instr = nextinstr();
        $$ = m;
    }
  ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Syntax Error: %s at line %d at token '%s'\n", s, yylineno, yytext);
}

int main(int argc, char **argv) {
    ST_current = createSymbolTable("global");
    ST_global = ST_current;

    if (yyparse() == 0) {
        print_symboltables();
        print_quads();
    }
    return 0;
}
