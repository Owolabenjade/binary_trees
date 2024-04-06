#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is full, 0 if not, or if tree is NULL.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    /* If leaf node */
    if (!tree->left && !tree->right)
        return 1;

    /* If both left and right exist, check if both subtrees are full */
    if (tree->left && tree->right)
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);

    /* If neither of the above conditions are met, the tree isn't full */
    return (0);
}

