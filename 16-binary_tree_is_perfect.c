#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: The height of the tree. If tree is NULL, height is 0.
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    if (!tree || (!tree->left && !tree->right))
        return 0;
    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);
    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * binary_tree_is_full - Checks if a binary tree is full.
 * @tree: A pointer to the root node of the tree to check.
 * Return: 1 if the tree is full, 0 if not.
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
    if (!tree)
        return 0;
    if (!tree->left && !tree->right)
        return 1;
    if (tree->left && tree->right)
        return binary_tree_is_full(tree->left) && binary_tree_is_full(tree->right);
    return 0;
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if tree is perfect, 0 if not or if tree is NULL.
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
    if (!tree)
        return 0;

    size_t left_height = binary_tree_height(tree->left);
    size_t right_height = binary_tree_height(tree->right);

    if (left_height == right_height && binary_tree_is_full(tree))
        return 1;
    return 0;
}

