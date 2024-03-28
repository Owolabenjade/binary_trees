#include "binary_trees.h"

/**
 * check_bst - Helper function to check if a binary tree is a BST.
 * @tree: A pointer to the current node of the tree.
 * @min: The minimum value the current node can have.
 * @max: The maximum value the current node can have.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise.
 */
int check_bst(const binary_tree_t *tree, int min, int max)
{
    if (tree == NULL)
        return (1);

    if (tree->n <= min || tree->n >= max)
        return (0);

    return (check_bst(tree->left, min, tree->n) &&
            check_bst(tree->right, tree->n, max));
}

/**
 * binary_tree_is_bst - Checks if a binary tree is a valid Binary Search Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid BST, and 0 otherwise. If tree is NULL, return 0.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
    if (tree == NULL)
        return (0);

    return (check_bst(tree, INT_MIN, INT_MAX));
}

