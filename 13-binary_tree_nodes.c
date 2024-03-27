#include "binary_trees.h"

/**
 * binary_tree_nodes - Counts the nodes with at least one child in a binary tree.
 * @tree: A pointer to the root node of the tree to count the number of nodes.
 *
 * Return: The number of nodes with at least one child. If tree is NULL, return 0.
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    /* Node is a parent if either left or right is not NULL */
    if (tree->left || tree->right)
        return 1 + binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
    else
        return binary_tree_nodes(tree->left) + binary_tree_nodes(tree->right);
}

