typedef struct expression_node {
    struct expression_node *first;
    struct expression_node *second;
    struct expression_node *third;
    struct expression_node *fourth;
    char *val;
} expression_node;

expression_node *init_exp_node(char *val, expression_node *first, expression_node *second, expression_node *third, expression_node *fourth);
void display_exp_tree(expression_node *exp_node);
