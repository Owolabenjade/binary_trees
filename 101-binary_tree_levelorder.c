#include "binary_trees.h"

/**
 * tree_height - Measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height.
 * Return: The height of the tree
 */
size_t tree_height(const binary_tree_t *tree)
{
    if (tree == NULL)
        return 0;

    size_t left_height = tree_height(tree->left);
    size_t right_height = tree_height(tree->right);

    return (left_height > right_height ? left_height + 1 : right_height + 1);
}

/**
 * print_current_level - prints nodes at the current level
 * @tree: pointer to the root node of the tree
 * @level: level to print
 * @func: pointer to a function to call for each node
 */
void print_current_level(const binary_tree_t *tree, size_t level, void (*func)(int))
{
    if (tree == NULL)
        return;
    if (level == 1)
        func(tree->n);
    else if (level > 1)
    {
        print_current_level(tree->left, level - 1, func);
        print_current_level(tree->right, level - 1, func);
    }
}

/**
 * binary_tree_levelorder - goes through a binary tree using level-order traversal
 * @tree: pointer to the root node of the tree to traverse
 * @func: pointer to a function to call for each node
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
    if (tree == NULL || func == NULL)
        return;

    size_t height = tree_height(tree);
    for (size_t i = 1; i <= height; i++)
        print_current_level(tree, i, func);
}

