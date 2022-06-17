// Name: Manas Chebrolu
// SRN: PES1UG20CS111
#include "bst.h"
#include <stdlib.h>

/*
 ** Do not use global variables.
 ** Mark any functions that you declare in this file that are not in the header as static
 ** Do not use static variables
 ** All occurences of count_ptr indicate that the number of comparison
 ** operations need to be stored in the location pointed by it
 ** The implementation can assume it is initialized to 0.
*/

// Initializes the root of the bst
void init_bst(bst_t *bst)
{
    bst->root = NULL;
}

// Helper function to recursively insert a node
static node_t *recursive_insert(node_t *node, int key, int *count_ptr)
{
    if (node == NULL)
    {
        node_t *temp = (node_t *) malloc(sizeof(node_t));
        temp->key = key;
        temp->left = temp->right = NULL;
        return temp;
    }

    if (++(*count_ptr) && key < node->key)
    {
        node->left = recursive_insert(node->left, key, count_ptr);
    }
    else
    {
        node->right = recursive_insert(node->right, key, count_ptr);
    }

    return node;
}

// Inserts element key into the Binary search tree
// Stores the number of comparisons at the location
// pointed by count_ptr
void insert(bst_t *tree, int key, int *count_ptr)
{
    tree->root = recursive_insert(tree->root, key, count_ptr);
}

// Finds the inorder successor of the current node
static node_t *inorder_successor(node_t *node)
{
    if (node->left)
        return inorder_successor(node->left);
    else
        return node;
}

// Helper function to recursively delete an element
static node_t *recursive_delete(node_t *node, int key, int *count_ptr)
{
    if (node == NULL)
        return node;    
    else if (++(*count_ptr) && key < node->key)
        node->left = recursive_delete(node->left, key, count_ptr);
    else if (++(*count_ptr) && key > node->key)
        node->right = recursive_delete(node->right, key, count_ptr);
    else
    {
        if (node->left == NULL) // Only a right child
        {
            node_t *temp = node->right;
            free(node);
            return temp;
        }
        else if (node->right == NULL)
        {
            node_t *temp = node->left;
            free(node);
            return temp;
        }
        else // Both left and right child exist
        {
            node_t *temp = inorder_successor(node->right);
            node->key = temp->key;
            node->right = recursive_delete(node->right, temp->key, count_ptr);
        }
        
    }
    return node;
}

// Delete key from the BST
// Replaces node with in-order successor
void delete_element(bst_t *tree, int key, int *count_ptr)
{
    tree->root = recursive_delete(tree->root, key, count_ptr);
}

// Helper funciton to search for the key element
static int recursive_search(node_t *node, int key, int *count_ptr)
{
    if (node == NULL)
        return -1;
    
    if (++(*count_ptr) && key < node->key)
        return recursive_search(node->left, key, count_ptr);
    else if (++(*count_ptr) && key > node->key)
        return recursive_search(node->right, key, count_ptr);
    else // Element is found
        return key;
}

// Searches for the element key in the bst
// Returns the element if found, else -1
int search(const bst_t *tree, int key, int *count_ptr)
{
    return recursive_search(tree->root, key, count_ptr);
}

// Helper function to find the maximum element in a bst
static int recursive_find_max(node_t *node)
{
    if (node)
    {
        if (node->right == NULL)
            return node->key;
        else
            return recursive_find_max(node->right);
    }
    else
        return -1;
}

// Returns the maximum element in the BST
int find_max(const bst_t *tree, int *count_ptr)
{
    return recursive_find_max(tree->root);
}

// Helper function to free the bst
static void recursive_free(node_t *node)
{
    if (node != NULL)
    {
        recursive_free(node->left);
        recursive_free(node->right);
        free(node);
    }
}

// Deletes all the elements of the bst
void free_bst(bst_t *bst) 
{
    recursive_free(bst->root);
    bst->root = NULL;
}

// Deletes all the elements if the bst and ensures it can be used again
void clear_bst(bst_t *bst)
{
    recursive_free(bst->root);
    bst->root = NULL;
}
