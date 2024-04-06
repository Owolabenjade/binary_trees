#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_depth - Measures the depth of a node in a binary tree.
 * @tree: Pointer to the node to measure the depth of.
 *
 * Return: Depth of the node, or 0 if tree is NULL.
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
    size_t depth = 0;

    if (tree == NULL) 
        return (0); 

    while (tree->parent != NULL)
    {
        depth++;
        tree = tree->parent;
    }

    return (depth);
}

/**
 * binary_tree_size - Measures the size of a binary tree.
 * @tree: Pointer to the root node of the tree to measure.
 *
 * Return: Size of the tree, or 0 if tree is NULL.
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
    if (tree == NULL) 
        return (0);

    return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: Pointer to the root node of the tree to check.
 *
 * Return: 1 if perfect, 0 otherwise (includes if tree is NULL).
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    int depth, num_nodes;

    if (tree == NULL) 
        return (0); 

    depth = binary_tree_depth(tree);
    num_nodes = binary_tree_size(tree);

    /* Check if num_nodes is 2^(depth + 1) - 1 */
    return (num_nodes == (1 << (depth + 1)) - 1); 
}

