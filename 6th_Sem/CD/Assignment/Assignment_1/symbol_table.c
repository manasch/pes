#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symbol_table.h"

table *init_table() {
    table *t = (table *) malloc(sizeof(table));
    t->head = NULL;
    return t;
}

symbol *init_symbol(char *name, int size, int type, int line, int scope) {
    symbol *sym = (symbol *) malloc(sizeof(symbol));
    sym->name = (char *) malloc(sizeof(char) * (strlen(name) + 1));
    sym->val = (char *) malloc(sizeof(char) * (15));

    strcpy(sym->name, name);
    sym->size = size;
    sym->type = type;
    sym->line = line;
    sym->scope = scope;
    strcpy(sym->val, "~");
    sym->next = NULL;
    
    return sym;
}

void insert_symbol(char *name, int size, int type, int line, int scope) {
    symbol *sym = init_symbol(name, size, type, line, scope);
    if (t->head == NULL) {
        t->head = sym;
        return;
    }

    symbol *p = t->head;
    // traverse till the end
    while (p->next != NULL)
        p = p->next;
    
    p->next = sym;
}

void insert_val(char *name, char *val, int line) {
    if (strcmp(val, "~") == 0 || t->head == NULL)
        return ;
    
    symbol *p = t->head;
    while (p != NULL && strcmp(p->name, name) != 0)
        p = p->next;
    
    if (p != NULL) {
        strcpy(p->val, val);
        p->line = line;
    }

    return;
}

char *retrieve_val(char *name) {
    char *val = "~";
    if (t->head == NULL) return val;

    symbol *p = t->head;
    while (p != NULL && strcmp(p->name, name) != 0)
        p = p->next;

    if (p != NULL)
        val = p->val;
    
    return val;
}

int retrieve_type(char *name) {
    int type = -1;
    if (t->head == NULL) return type;

    symbol *p = t->head;
    while (p != NULL && strcmp(p->name, name) != 0)
        p = p->next;

    if (p != NULL)
        type = p->type;
    
    return type;
}

int check_sym_tab(char *name) {
    if (t->head == NULL) return 0;

    symbol *p = t->head;
    while (p != NULL && strcmp(p->name, name) != 0)
        p = p->next;
    
    if (p != NULL) return 1;
    return 0;
}

void display_sym_tab() {
    printf("Name\tSize\tType\tLineNo.\tScope\tValue\n");
    if (t->head == NULL) return;
    
    symbol *p = t->head;
    while (p != NULL) {
        printf("%s\t%d\t%d\t%d\t%d\t%s\n", p->name, p->size, p->type, p->line, p->scope, p->val);
        p = p->next;
    }
}

int type_check(char *val) {
    char *s = strchr(val, '\"');
    if (s != NULL)
        return 1;
    
    s = strchr(val, '.');
    if (s != NULL)
        return 3;
    return 2;
}

int size(int type) {
    if (type == 3)
        return 4;
    if (type == 4)
        return 8;
    return type;
}
