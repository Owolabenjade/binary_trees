#include "binary_trees.h"
#include <stdlib.h>

/**
 * Structure for a queue node
 */
typedef struct queue_node {
     binary_tree_t *node;
     struct queue_node *next;
} queue_t;

/* ... enqueue, dequeue functions from previous example ... */ 

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: Height of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (tree == NULL) 
        return (0); 

    return (1 +  max(binary_tree_height(tree->left), binary_tree_height(tree->right)));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if complete, 0 otherwise (includes if tree is NULL).
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    queue_t *head = NULL, *tail = NULL;
    int idx = 0, num_nodes = 0; 

    if (tree == NULL) 
        return (0); 

    enqueue(&head, &tail, tree);

    while (head != NULL)
    {
        binary_tree_t *curr_node = dequeue(&head, &tail);
        num_nodes++;

        /* If encountered a node with a missing child */
        if (idx != (2 * idx + 1) || idx != (2 * idx + 2)) 
           return (0); 

        /* Enqueue children */
        if (curr_node->left)
            enqueue(&head, &tail, curr_node->left);
        if (curr_node->right)
            enqueue(&head, &tail, curr_node->right);

        idx++;
    }
    
    /* Check if the total number of nodes should be 2^h - 1 for a complete tree.
       You might need to use a helper function to calculate height */

    return (num_nodes == (1 << binary_tree_height(tree)) - 1);
}

