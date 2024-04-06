#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_leaf - Checks if a node is a leaf.
 * @node: A pointer to the node to check.
 *
 * Return: 1 if node is a leaf, otherwise 0. If node is NULL, return 0.
*/
int binary_tree_is_leaf(const binary_tree_t *node)
{
	if (node && !node->left && !node->right)
		return (1);
	return (0);
}

