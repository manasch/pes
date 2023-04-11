#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abstract_syntax_tree.h"

expression_node *init_exp_node(char *val, expression_node *first, expression_node *second, expression_node *third, expression_node *fourth) {
    expression_node *node = (expression_node *) malloc(sizeof(expression_node));

    node->first = first;
    node->second = second;
    node->third = third;
    node->third = fourth;
    node->val = val;

    return node;
}

void display_exp_tree(expression_node *exp_node) {
    if (exp_node == NULL)
        return;
    
    printf("%s\n", exp_node->val);
    display_exp_tree(exp_node->first);
    display_exp_tree(exp_node->second);
    display_exp_tree(exp_node->third);
    display_exp_tree(exp_node->fourth);
}
