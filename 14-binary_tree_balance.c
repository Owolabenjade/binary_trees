#include "binary_trees.h"

/**
 * height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: height of the tree
 * If tree is NULL, height is 0
 */
size_t height(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    size_t left_height = height(tree->left);
    size_t right_height = height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: balance factor
 * If tree is NULL, return 0
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    if (!tree)
        return (0);

    return height(tree->left) - height(tree->right);
}

