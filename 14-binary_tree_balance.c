#include "binary_trees.h"

/**
 * binary_tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: The height of the tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
    size_t height_left, height_right;

    if (tree == NULL)
        return (0);

    height_left = tree->left ? 1 + binary_tree_height(tree->left) : 0;
    height_right = tree->right ? 1 + binary_tree_height(tree->right) : 0;

    return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: The balance factor or 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
    int balance;
    int height_left, height_right;

    if (tree == NULL)
        return (0);

    height_left = tree->left ? binary_tree_height(tree->left) : -1;
    height_right = tree->right ? binary_tree_height(tree->right) : -1;

    balance = height_left - height_right;
    return (balance);
}

