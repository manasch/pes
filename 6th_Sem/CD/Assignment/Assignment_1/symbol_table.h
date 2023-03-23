#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 3

typedef struct symbol {
    char *name;
    int size;
    int type;
    int line;
    int scope;
    char *val;
    struct symbol *next;
} symbol;

typedef struct table {
    symbol *head;
} table;

static table *t;

table *init_table();
symbol *init_symbol(char *name, int size, int type, int lineno, int scope);
void insert_symbol(char *name, int size, int type, int lineno, int scope);
void insert_val(char *name, char *val, int line);
int check_sym_tab(char *name);
void display_sym_tab();
char *retrieve_val(char *name);
int retrieve_type(char *name);
int type_check(char *value);
int size(int type);
