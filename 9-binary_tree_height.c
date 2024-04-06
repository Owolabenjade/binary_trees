#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_height - Measures the height of a binary tree.
 * @tree: A pointer to the root node of the tree to measure the height.
 *
 * Return: The height of the tree. If tree is NULL, return 0.
 */
 
 size_t max(size_t a, size_t b)
{
	return (a > b) ? a : b;
}

size_t binary_tree_height(const binary_tree_t *tree)
{
	if (!tree || (!tree->left && !tree->right))
		return (0);

	return (1 + max(binary_tree_height(tree->left),
	binary_tree_height(tree->right)));
}

