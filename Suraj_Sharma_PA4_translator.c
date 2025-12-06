#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Suraj_Sharma_PA4_translator.h"
#include <stdarg.h>
#include <ctype.h>

static symbolTable **all_symboltables = NULL;
static int all_symtab_count = 0;
static int all_symtab_cap = 0;

symbolTable *ST_global = NULL;
symbolTable *ST_current = NULL;

quadarray Q = { .data = NULL, .count = 0, .cap = 0 };

typedef struct {
    symbolTable *st;
    int start_index;
    int end_index;
} FunctionBlock;

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

void print_quads(const char *filename) {
    FILE *fp = fopen(filename, "w");
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


/*
 * st_lookup_non_create:
 * Searches for a symbol by name across the symbol table hierarchy (current to global).
 * @param name: The lexeme of the symbol to look up.
 * @return: Pointer to the existing symbol entry, or NULL if not found.
 */
symbol *st_lookup_non_create(const char *name) {
    if (!name) return NULL;
    symbolTable *it = ST_current;

    while (it) {
        for (int i = 0; i < it->count; ++i) {
            if (it->entries[i] && it->entries[i]->name && strcmp(it->entries[i]->name, name) == 0)
                return it->entries[i];
        }

        // The global scope with parent: NULL
        if (!it->parent) break;
        it = find_symboltable_by_name(it->parent);
    }
    return NULL;
}

/*
 * x86_emit:
 * Helper function to write a line of assembly code to the output file.
 * @param f: File pointer to the assembly output file
 * @param format: The format string for the assembly instruction.
 */
void x86_emit(FILE *f, const char *format, ...) {
    va_list args;
    va_start(args, format);
    vfprintf(f, format, args);
    va_end(args);
}

/*
 * st_to_x86_addr_expr:
 * Translates a symbolic name (variable/constant) from the Symbol Table
 * into its corresponding x86/IA-32 assembly address expression (IA-32, AT&T Syntax).
 *
 * @param name: The symbol name/constant string from the TAC quad.
 * @param st_func: The Symbol Table of the function currently being compiled.
 * @return: A dynamically allocated string containing the assembly operand
 * (e.g., "$10", "global_var", "-4(%ebp)"). Will be freed by the caller.
 */
char *st_to_x86_addr_expr(const char *name, symbolTable *st_func) {
    if (!name || name[0] == '\0') return xstrdup("");

    // 1. Constant (Immediate Value)?
    // Checks for starting digits or leading sign/digit combination (e.g., "10", "-5")
    if (isdigit(name[0]) || (name[0] == '-' && isdigit(name[1]))) {
        char *buf = malloc(strlen(name) + 2);
        if (!buf) exit(1);
        sprintf(buf, "$%s", name);
        return buf;
    }

    // 2. String Literal?
    // Return the literal itself
    if (name[0] == '\'') {
        return xstrdup(name);
    }

    symbol *s = st_lookup_non_create(name);
    if (!s) {
        fprintf(stderr, "FATAL: Operand '%s' not found in symbol table.\n", name);
        return xstrdup("UNKNOWN_SYMBOL");
    }

    // 3. Global Variable or Function Name
    if (st_func == ST_global || (s->scope && strcmp(s->scope, "func") == 0)) {
        return xstrdup(name);
    }

    // 4. Stack Variable (Local, Temp, Parameter) - Relative to %ebp
    int offset = s->offset;
    char buf[64];

    if (s->scope && strcmp(s->scope, "param") == 0) {
        // Parameters: Positive offset from %ebp
        // EBP + 8 is the 1st parameter.
        // We add 2 * SIZE_INT (8 bytes) to account for the stored EBP and Return Address.
        int x86_offset = offset + (2 * SIZE_INT);
        sprintf(buf, "%d(%%ebp)", x86_offset);
    } else {
        // Local/Temp variables: Negative offset from %ebp
        // EBP - 4 is the 1st local/temp.
        int x86_offset = -(offset + s->size);
        sprintf(buf, "%d(%%ebp)", x86_offset);
    }

    return xstrdup(buf);
}

/*
 * x86_gen_data_section:
 * Generates the .data section of the assembly file, defining space for global
 * variables and labels for string literals.
 *
 * @param f: File pointer to the assembly output file (.asm).
 */
void x86_gen_data_section(FILE *f) {
    x86_emit(f, "\n/*==== DATA SECTION ==== */\n");
    x86_emit(f, ".data\n");

    symbolTable *st_gbl = ST_global;
    if (st_gbl) {
        for (int i = 0; i < st_gbl->count; ++i) {
            symbol *e = st_gbl->entries[i];


            if (e && e->scope && strcmp(e->scope, "local") == 0 && strcmp(e->type, "INTEGER") == 0) {
                // Allocate space for the global integer variable
                x86_emit(f, "\t.globl %s\n", e->name);
                x86_emit(f, "%s:\t.long 0\n", e->name); // Allocate 4 bytes, initialized to 0
            }
        }
    }

    x86_emit(f, ".extern readln\n");
    x86_emit(f, ".extern writeln\n");
}

/*
 * x86_gen_function:
 * Generates the assembly code for a function or program block.
 * @param f: File pointer to the assembly output file (.asm).
 * @param st_func: The Symbol Table for the function being generated.
 * @param start_quad: The index of the first quad in the function body.
 * @param end_quad: The index of the last quad in the function body.
 */
void x86_gen_function(FILE *f, symbolTable *st_func, int start_quad, int end_quad) {

    symbolTable *st_saved = ST_current;

    ST_current = st_func;

    // --- Function Label and Prologue ---
    x86_emit(f, "\n/* --- FUNCTION: %s --- */\n", st_func->name);
    x86_emit(f, ".text\n");
    x86_emit(f, "\t.globl %s\n", st_func->name);
    x86_emit(f, "%s:\n", st_func->name);

    int local_size = st_func->current_offset;
    x86_emit(f, "\tpushl %%ebp\n");
    x86_emit(f, "\tmovl %%esp, %%ebp\n");
    x86_emit(f, "\tsubl $%d, %%esp\n", local_size);

    // --- Quad Translation ---
    for (int i = start_quad; i <= end_quad && i < Q.count; ++i) {
        quad *q = &Q.data[i];

        x86_emit(f, "\n.L%d:\n", i);

        // Memory Binding
        char *arg1_x86 = st_to_x86_addr_expr(q->arg1, st_func);
        char *arg2_x86 = st_to_x86_addr_expr(q->arg2, st_func);
        char *result_x86 = st_to_x86_addr_expr(q->result, st_func);

        switch (q->op) {
            case OP_COPY: // result = arg1
                x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86);
                x86_emit(f, "\tmovl %%eax, %s\n", result_x86);
                break;

            case OP_ADD: // result = arg1 + arg2
                x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86);
                x86_emit(f, "\taddl %s, %%eax\n", arg2_x86);
                x86_emit(f, "\tmovl %%eax, %s\n", result_x86);
                break;

            case OP_SUB: // result = arg1 - arg2
                x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86);
                x86_emit(f, "\tsubl %s, %%eax\n", arg2_x86);
                x86_emit(f, "\tmovl %%eax, %s\n", result_x86);
                break;

            case OP_MUL: // result = arg1 * arg2
                // Imull uses the two-operand form: dest = dest * src
                x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86);
                x86_emit(f, "\timull %s, %%eax\n", arg2_x86);
                x86_emit(f, "\tmovl %%eax, %s\n", result_x86);
                break;

            case OP_DIV: // result = arg1 / arg2
                // Arg1 (dividend) -> EAX. EDX must be cleared/sign-extended. Arg2 is divisor.
                x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86);
                x86_emit(f, "\tcltd\n");                     // Convert EAX (32-bit) to EDX:EAX (64-bit dividend)
                x86_emit(f, "\tidivl %s\n", arg2_x86);       // Divide by arg2. Quotient is in EAX.
                x86_emit(f, "\tmovl %%eax, %s\n", result_x86); // Store quotient
                break;

            // --- Relational Jumps (cmpl arg2, EAX) ---
            case OP_IF_LT: x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86); x86_emit(f, "\tcmpl %s, %%eax\n", arg2_x86); x86_emit(f, "\tjl .L%s\n", q->result); break;
            case OP_IF_LE: x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86); x86_emit(f, "\tcmpl %s, %%eax\n", arg2_x86); x86_emit(f, "\tjle .L%s\n", q->result); break;
            case OP_IF_GT: x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86); x86_emit(f, "\tcmpl %s, %%eax\n", arg2_x86); x86_emit(f, "\tjg .L%s\n", q->result); break;
            case OP_IF_GE: x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86); x86_emit(f, "\tcmpl %s, %%eax\n", arg2_x86); x86_emit(f, "\tjge .L%s\n", q->result); break;
            case OP_IF_EQ: x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86); x86_emit(f, "\tcmpl %s, %%eax\n", arg2_x86); x86_emit(f, "\tje .L%s\n", q->result); break;
            case OP_IF_NE: x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86); x86_emit(f, "\tcmpl %s, %%eax\n", arg2_x86); x86_emit(f, "\tjne .L%s\n", q->result); break;

            case OP_GOTO: // goto L_target
                x86_emit(f, "\tjmp .L%s\n", q->result);
                break;

            // --- Function Call Management. CDECL: Arguments pushed R->L; caller cleans up stack.---
            case OP_PARAM: // param arg1
                x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86);
                x86_emit(f, "\tpushl %%eax\n");
                break;

            case OP_CALL: // result = call func_name, N_params
                {
                    int num_params = q->arg2 ? atoi(q->arg2) : 0;
                    int stack_cleanup = num_params * SIZE_INT;

                    x86_emit(f, "\tcall %s\n", q->arg1);
                    x86_emit(f, "\taddl $%d, %%esp\n", stack_cleanup);

                    if (q->result) { // Store return value from EAX
                         x86_emit(f, "\tmovl %%eax, %s\n", result_x86);
                    }
                }
                break;

            case OP_RETURN: // return (arg1)
                if (q->arg1) {
                    x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86); // Move return value to EAX
                }
                break;

            // --- I/O Operations (External library calls) ---
            case OP_READ: // read arg1
                x86_emit(f, "\tleal %s, %%eax\n", arg1_x86);
                x86_emit(f, "\tpushl %%eax\n");
                x86_emit(f, "\tcall readln\n");
                x86_emit(f, "\taddl $4, %%esp\n");
                break;

            case OP_PRINT: // print arg1
                // Push the VALUE or the string literal address.
                x86_emit(f, "\tmovl %s, %%eax\n", arg1_x86);
                x86_emit(f, "\tpushl %%eax\n");
                x86_emit(f, "\tcall writeln\n");
                x86_emit(f, "\taddl $4, %%esp\n");
                break;

            case OP_STOP:
                break;

            default:
                x86_emit(f, "\t# UNHANDLED OPCODE: %d\n", q->op);
                break;
        }
        free(arg1_x86); free(arg2_x86); free(result_x86);
    }

    ST_current = st_saved;

    // --- Epilogue / State Restore ---
    if (Q.data[end_quad].op == OP_STOP) {
        // System Exit (for the main program block)
        x86_emit(f, "\tmovl $1, %%eax\n");
        x86_emit(f, "\txorl %%ebx, %%ebx\n");
        x86_emit(f, "\tint $0x80\n");
    } else {
        // Standard Function Epilogue
        x86_emit(f, "\tmovl %%ebp, %%esp\n");
        x86_emit(f, "\tpopl %%ebp\n");
        x86_emit(f, "\tret\n");
    }
}

/*
 * find_function_boundaries:
 * Scans the Global ST and the Quad Array to find all code blocks (functions + main)
 * and determines their corresponding quad index ranges.
 *
 * @param blocks: An array of FunctionBlock (caller-allocated) to be populated.
 * @return: The total count of function blocks found.
 */
int find_function_boundaries(FunctionBlock blocks[]) {
    int block_count = 0;
    int current_quad_start = 0;

    if (!ST_global) return 0;

    // First pass: Process all user-defined functions
    // Functions have nested_symboltable_name set
    for (int i = 0; i < ST_global->count; ++i) {
        symbol *e = ST_global->entries[i];
        
        // Only process symbols that have a nested symbol table (i.e., functions)
        if (e->nested_symboltable_name) {
            symbolTable *st_func = find_symboltable_by_name(e->nested_symboltable_name);
            if (!st_func) continue;

            // Find the OP_RETURN that marks the end of this function
            int end_quad = -1;
            for (int j = current_quad_start; j < Q.count; ++j) {
                if (Q.data[j].op == OP_RETURN) {
                    end_quad = j;
                    break;
                }
            }

            if (end_quad != -1) {
                blocks[block_count].st = st_func;
                blocks[block_count].start_index = current_quad_start;
                blocks[block_count].end_index = end_quad;
                block_count++;
                current_quad_start = end_quad + 1;
            }
        }
    }

    // Second pass: The main program block
    // After all functions, remaining quads belong to the main program
    // The main program uses ST_global and ends with OP_STOP
    if (current_quad_start < Q.count) {
        // Find OP_STOP
        int end_quad = Q.count - 1;
        for (int j = current_quad_start; j < Q.count; ++j) {
            if (Q.data[j].op == OP_STOP) {
                end_quad = j;
                break;
            }
        }
        
        blocks[block_count].st = ST_global;
        blocks[block_count].start_index = current_quad_start;
        blocks[block_count].end_index = end_quad;
        block_count++;
    }

    return block_count;
}

/*
 * x86_generate_all:
 * Driver Function:
 * @param out_filename: The name of the output assembly file
 */
void x86_generate_all(const char *out_filename) {
    FILE *f = fopen(out_filename, "w");
    if (!f) {
        perror("Error opening output file");
        return;
    }
    
    x86_emit(f, "\t.file \"nanopascal.np\"\n");
    
    // Max number of functions/blocks is limited by ST_global size
    FunctionBlock blocks[ST_global->count > 0 ? ST_global->count + 1 : 2]; // +1 for main
    int num_blocks = find_function_boundaries(blocks);
    
    x86_gen_data_section(f);
    
    // --- Generate all functions FIRST (before main wrapper) ---
    for (int i = 0; i < num_blocks; ++i) {
        x86_gen_function(f, blocks[i].st, blocks[i].start_index, blocks[i].end_index);
    }
    
    // --- GCC Main Wrapper ---
    x86_emit(f, "\n/* --- GCC MAIN WRAPPER --- */\n");
    x86_emit(f, ".text\n");
    x86_emit(f, ".globl main\n");
    x86_emit(f, "main:\n");
    x86_emit(f, "\tpushl %%ebp\n");
    x86_emit(f, "\tmovl %%esp, %%ebp\n");
    
    // Call the main program
    if (num_blocks > 0) {
        // The main program is the last block 
        x86_emit(f, "\tcall %s\n", blocks[num_blocks - 1].st->name);
    } else {
        x86_emit(f, "\t# No code blocks found to execute.\n");
    }
    
    // Exit gracefully after main
    x86_emit(f, "\tmovl $0, %%eax\n");
    x86_emit(f, "\tpopl %%ebp\n");
    x86_emit(f, "\tret\n");
    
    fclose(f);
}