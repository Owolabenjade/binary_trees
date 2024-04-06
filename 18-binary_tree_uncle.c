#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_sibling - Finds the sibling of a node in a binary tree.
 * @node: Pointer to the node to find the sibling of.
 *
 * Return: Pointer to the sibling node, otherwise NULL:
 *         - If `node` is NULL
 *         - If `node`'s parent is NULL
 *         - If `node` has no sibling
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL)
        return (NULL); 

    if (node == node->parent->left)
        return (node->parent->right); 
    else
        return (node->parent->left); 
}

/**
 * binary_tree_uncle - Finds the uncle of a node in a binary tree.
 * @node: Pointer to the node to find the uncle of.
 *
 * Return: Pointer to the uncle node, otherwise NULL:
 *         - If `node` is NULL
 *         - If `node` has no uncle (no grandparent)
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
    if (node == NULL || node->parent == NULL || node->parent->parent == NULL)
        return (NULL);  

    return (binary_tree_sibling(node->parent));
}

