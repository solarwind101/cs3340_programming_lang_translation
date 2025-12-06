#ifndef __SURAJ_SHARMA_PA4_TRANSLATOR_H
#define __SURAJ_SHARMA_PA4_TRANSLATOR_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

#define SIZE_INT    4
#define SIZE_STRING 4

/* Relational Operators */
#define RELOP_EQ 1
#define RELOP_NE 2
#define RELOP_LT 3
#define RELOP_GT 4
#define RELOP_LE 5
#define RELOP_GE 6

typedef enum {
    OP_ADD,
    OP_SUB,
    OP_MUL,
    OP_DIV,
    OP_COPY,
    OP_IF_LT,
    OP_IF_LE,
    OP_IF_GT,
    OP_IF_GE,
    OP_IF_EQ,
    OP_IF_NE,
    OP_GOTO,
    OP_PARAM,
    OP_CALL,
    OP_RETURN,
    OP_READ,
    OP_PRINT,
    OP_STOP,
    OP_NOOP
} Opcode;

typedef struct symtab {
    char *name;
    char *parent;
    struct symtabentry **entries;
    int count;
    int cap;
    int current_offset;
} symbolTable;

typedef struct symtabentry {
    char *name;
    char *type;
    char *scope;
    char *nested_symboltable_name;
    int size;
    int offset;
} symbol;

extern symbolTable *ST_global;
extern symbolTable *ST_current;

symbolTable *createSymbolTable(const char *name);
symbol *lookupSymbol(const char *name);
symbol *genTemp(const char *type);
void updateSymbolInfo(symbol *s, const char *type, int size, const char *scope);

char *int_to_str(int v);
char *xstrdup(const char *s); 
symbolTable *find_symboltable_by_name(const char *name);

typedef struct quadentry {
    Opcode op;
    char *arg1;
    char *arg2;
    char *result;
} quad;

typedef struct quadarray {
    quad *data;
    int count;
    int cap;
} quadarray;

extern quadarray Q;

int emit(Opcode op, const char *arg1, const char *arg2, const char *result);
int nextinstr(void);
void print_symboltables(void);
void print_quads(const char *filename);
typedef struct intlist {
    int index;
    struct intlist *next;
} intlist;

intlist *makeList(unsigned int index);
intlist *mergeLists(intlist *p1, intlist *p2);
void backpatch(intlist *p, unsigned int target_index);

/* Structures for semantic attributes */

typedef struct exprattr {
    symbol *place;
    intlist *truelist;
    intlist *falselist;
    int is_boolean;
} exprattr;

typedef struct stmtattr {
    intlist *nextlist;
} stmtattr;

typedef struct markerattr {
    int instr;
} markerattr;


typedef struct symlist {
    symbol *sym;
    struct symlist *next;
} symlist;

symlist *makeSymList(symbol *s);
symlist *mergeSymLists(symlist *l1, symlist *l2);

typedef struct arglist {
    char *name;
    struct arglist *next;
} arglist;

arglist *makeArgList(char *name);
arglist *mergeArgLists(arglist *l1, arglist *l2);

symbol *st_lookup_non_create(const char *name);

// Memory Binding: Symbol to x86/IA-32 Address Expression
char *st_to_x86_addr_expr(const char *name, symbolTable *st_func); 

void x86_emit(FILE *f, const char *format, ...);
void x86_generate_all(const char *out_filename);
void x86_gen_data_section(FILE *f);
void x86_gen_function(FILE *f, symbolTable *st_func, int start_quad, int end_quad);

#ifdef __cplusplus
}
#endif

#endif
