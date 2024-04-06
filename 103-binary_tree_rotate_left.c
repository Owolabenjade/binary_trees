#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: Pointer to the root node of the tree to rotate.
 *
 * Return: Pointer to the new root node after rotation.
*/
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *new_root, *temp;

	if (tree == NULL || tree->right == NULL)
		return (tree); /* Cannot rotate */

	new_root = tree->right;
	temp = new_root->left;
	new_root->left = tree;
	tree->right = temp;

	/* Update parents if necessary */
	if (temp)
		temp->parent = tree;

	return (new_root); 
}

