#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Manohar_Bikaneri_PA3_translator.h"

static symbolTable **all_symboltables = NULL;
static int all_symtab_count = 0;
static int all_symtab_cap = 0;

symbolTable *ST_global = NULL;
symbolTable *ST_current = NULL;

quadarray Q = { .data = NULL, .count = 0, .cap = 0 };

char *xstrdup(const char *s) {
    if (!s) return NULL;
    size_t n = strlen(s);
    char *r = malloc(n + 1);
    if (!r) exit(1);
    memcpy(r, s, n + 1);
    return r;
}

char *int_to_str(int v) {
    char buf[32];
    int n = snprintf(buf, sizeof(buf), "%d", v);
    if (n < 0) exit(1);
    char *r = malloc((size_t)n + 1);
    if (!r) exit(1);
    memcpy(r, buf, (size_t)n + 1);
    return r;
}

symbolTable *createSymbolTable(const char *name) {
    symbolTable *st = malloc(sizeof(symbolTable));
    if (!st) exit(1);
    st->name = xstrdup(name ? name : "<anon>");
    st->parent = ST_current ? xstrdup(ST_current->name) : NULL;
    st->cap = 8;
    st->count = 0;
    st->current_offset = 0; 
    st->entries = calloc((size_t)st->cap, sizeof(symbol *));
    if (!st->entries) exit(1);
    
    if (all_symtab_count == all_symtab_cap) {
        all_symtab_cap = all_symtab_cap ? all_symtab_cap * 2 : 8;
        all_symboltables = realloc(all_symboltables, (size_t)all_symtab_cap * sizeof(symbolTable *));
        if (!all_symboltables) exit(1);
    }
    all_symboltables[all_symtab_count++] = st;
    
    if (ST_global == NULL) ST_global = st;
    if (ST_current == NULL) ST_current = st;
    return st;
}

symbolTable *find_symboltable_by_name(const char *name) {
    if (!name) return NULL;
    for (int i = 0; i < all_symtab_count; ++i)
        if (all_symboltables[i] && all_symboltables[i]->name && strcmp(all_symboltables[i]->name, name) == 0)
            return all_symboltables[i];
    return NULL;
}

static symbol *append_entry(symbolTable *st, const char *name) {
    if (!st || !name) return NULL;
    if (st->count == st->cap) {
        st->cap *= 2;
        st->entries = realloc(st->entries, (size_t)st->cap * sizeof(symbol *));
        if (!st->entries) exit(1);
    }
    symbol *e = malloc(sizeof(symbol));
    if (!e) exit(1);
    e->name = xstrdup(name);
    e->type = xstrdup("unknown");
    e->scope = xstrdup("local"); 
    e->nested_symboltable_name = NULL;
    e->size = 0;
    e->offset = 0; 
    st->entries[st->count++] = e;
    return e;
}

symbol *lookupSymbol(const char *name) {
    if (!name) return NULL;
    if (!ST_current) {
        ST_current = createSymbolTable("global");
        ST_global = ST_current;
    }
    symbolTable *it = ST_current;
    while (it) {
        for (int i = 0; i < it->count; ++i) {
            if (it->entries[i] && it->entries[i]->name && strcmp(it->entries[i]->name, name) == 0)
                return it->entries[i];
        }
        if (!it->parent) break;
        it = find_symboltable_by_name(it->parent);
    }
    return append_entry(ST_current, name);
}

symbol *genTemp(const char *type) {
    static int tempcounter = 0;
    char tmpname[64];
    snprintf(tmpname, sizeof(tmpname), "t%d", ++tempcounter);
    if (!ST_current) {
        ST_current = createSymbolTable("global");
        ST_global = ST_current;
    }
    symbol *e = append_entry(ST_current, tmpname);
    if (e) {
        if (e->type) free(e->type);
        e->type = xstrdup(type);
        if (e->scope) free(e->scope);
        e->scope = xstrdup("temp");
    }
    return e;
}

void updateSymbolInfo(symbol *e, const char *type, int size, const char *scope) {
    if (!e) return;
    
    /* Type */
    if (e->type) free(e->type);
    e->type = xstrdup(type);
    
    /* Size */
    e->size = size;

    /* Scope */
    if (scope) {
        if (e->scope) free(e->scope);
        e->scope = xstrdup(scope);
    }

    if (ST_current && size > 0) {
        e->offset = ST_current->current_offset;
        ST_current->current_offset += size;
    }
}

void print_symboltables(void) {
    for (int tidx = 0; tidx < all_symtab_count; ++tidx) {
        symbolTable *st = all_symboltables[tidx];
        if (!st) continue;
        printf("--------------------\n");
        printf("ST: %s, Parent: %s\n", st->name, st->parent ? st->parent : "null");
        printf("--------------------\n");
        for (int i = 0; i < st->count; ++i) {
            symbol *e = st->entries[i];
            if (!e || !e->name) continue;
            
            if (e->name[0] == 't' && (e->name[1] >= '0' && e->name[1] <= '9')) continue; 
            
            /* Print format: <name>, <type>, <scope>, <nested> */
            printf("%s, %s, %s, %s\n", 
                   e->name,
                   e->type ? e->type : "unknown",
                   e->scope ? e->scope : "unknown",
                   e->nested_symboltable_name ? e->nested_symboltable_name : "null");
        }
    }
}

static void ensure_quad_capacity(void) {
    if (Q.count == Q.cap) {
        Q.cap = Q.cap ? Q.cap * 2 : 32;
        Q.data = realloc(Q.data, (size_t)Q.cap * sizeof(quad));
        if (!Q.data) exit(1);
    }
}

static char *dup_or_null(const char *s) { return s ? xstrdup(s) : NULL; }

int emit(Opcode op, const char *arg1, const char *arg2, const char *result) {
    int idx = Q.count;
    ensure_quad_capacity();
    Q.data[idx].op = op;
    Q.data[idx].arg1 = dup_or_null(arg1);
    Q.data[idx].arg2 = dup_or_null(arg2);
    Q.data[idx].result = dup_or_null(result);
    Q.count++;
    return idx;
}

int nextinstr(void) { return Q.count; }

void print_quads(void) {
    FILE *fp = fopen("Manohar_Bikaneri_PA3_quads.out", "w");
    if (!fp) {
        perror("Cannot open output file");
        exit(1);
    }

    for (int i = 0; i < Q.count; ++i) {
        quad *q = &Q.data[i];
        fprintf(fp, "%d:\t", i);

        switch (q->op) {
            case OP_ADD:
                fprintf(fp, "%s = %s + %s", q->result, q->arg1, q->arg2);
                break;
            case OP_SUB:
                fprintf(fp, "%s = %s - %s", q->result, q->arg1, q->arg2);
                break;
            case OP_MUL:
                fprintf(fp, "%s = %s * %s", q->result, q->arg1, q->arg2);
                break;
            case OP_DIV:
                fprintf(fp, "%s = %s / %s", q->result, q->arg1, q->arg2);
                break;
            case OP_COPY:
                fprintf(fp, "%s = %s", q->result, q->arg1);
                break;

            case OP_IF_LT:
                fprintf(fp, "if %s < %s goto %s", q->arg1, q->arg2, q->result);
                break;
            case OP_IF_LE:
                fprintf(fp, "if %s <= %s goto %s", q->arg1, q->arg2, q->result);
                break;
            case OP_IF_GT:
                fprintf(fp, "if %s > %s goto %s", q->arg1, q->arg2, q->result);
                break;
            case OP_IF_GE:
                fprintf(fp, "if %s >= %s goto %s", q->arg1, q->arg2, q->result);
                break;
            case OP_IF_EQ:
                fprintf(fp, "if %s == %s goto %s", q->arg1, q->arg2, q->result);
                break;
            case OP_IF_NE:
                fprintf(fp, "if %s != %s goto %s", q->arg1, q->arg2, q->result);
                break;

            case OP_GOTO:
                fprintf(fp, "goto %s", q->result);
                break;

            case OP_PARAM:
                fprintf(fp, "param %s", q->arg1);
                break;

            case OP_CALL:
                fprintf(fp, "%s = call %s, %s",
                        q->result ? q->result : "t0",
                        q->arg1,
                        q->arg2);
                break;

            case OP_RETURN:
                if (q->arg1)
                    fprintf(fp, "return %s", q->arg1);
                else
                    fprintf(fp, "return");
                break;

            case OP_READ:
                fprintf(fp, "read %s", q->arg1);
                break;

            case OP_PRINT:
                fprintf(fp, "print %s", q->arg1);
                break;

            case OP_STOP:
                fprintf(fp, "stop");
                break;

            default:
                fprintf(fp, "unknown");
                break;
        }

        fprintf(fp, "\n");
    }

    fclose(fp);
}


intlist *makeList(unsigned int index) {
    intlist *p = malloc(sizeof(intlist));
    if (!p) exit(1);
    p->index = (int)index;
    p->next = NULL;
    return p;
}

intlist *mergeLists(intlist *p1, intlist *p2) {
    if (!p1) return p2;
    if (!p2) return p1;
    intlist *it = p1;
    while (it->next) it = it->next;
    it->next = p2;
    return p1;
}

void backpatch(intlist *p, unsigned int target_index) {
    char *tstr = int_to_str((int)target_index);
    intlist *it = p;
    while (it) {
        int idx = it->index;
        if (idx >= 0 && idx < Q.count) {
            if (Q.data[idx].result) free(Q.data[idx].result);
            Q.data[idx].result = xstrdup(tstr);
        }
        it = it->next;
    }
    free(tstr);
}

symlist *makeSymList(symbol *s) {
    symlist *node = malloc(sizeof(symlist));
    node->sym = s;
    node->next = NULL;
    return node;
}

symlist *mergeSymLists(symlist *l1, symlist *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    symlist *t = l1;
    while(t->next) t = t->next;
    t->next = l2;
    return l1;
}

arglist *makeArgList(char *name) {
    arglist *node = malloc(sizeof(arglist));
    node->name = xstrdup(name);
    node->next = NULL;
    return node;
}

arglist *mergeArgLists(arglist *l1, arglist *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    arglist *t = l1;
    while(t->next) t = t->next;
    t->next = l2;
    return l1;
}
