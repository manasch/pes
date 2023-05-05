typedef struct expression_node {
    struct expression_node *first;
    struct expression_node *second;
    struct expression_node *third;
    char *val;
} expression_node;

expression_node *init_exp_node(char *val, expression_node *first, expression_node *second, expression_node *third);
void display_exp_tree(expression_node *exp_node);
