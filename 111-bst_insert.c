#include "binary_trees.h"
#include <stdlib.h>

/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST.
 * @value: Value to insert into the tree.
 *
 * Return: Pointer to the newly created node, or NULL on failure.
*/
binary_tree_t *bst_insert(bst_t **tree, int value)
{
	bst_t *new_node, *current;

	if (tree == NULL) 
		return (NULL); 

	if (*tree == NULL) /* Empty tree or reached insertion point */
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node; /* Update root pointer if needed */
		return (new_node);
	}

	current = *tree;
	while (current) 
	{
		if (value < current->n) 
		{
			if (current->left == NULL) 
			{
				new_node = binary_tree_node(current, value);
				current->left = new_node;
				return (new_node);
			} 
			else
				current = current->left; 
		} 
		else if (value > current->n) 
		{
			if (current->right == NULL)
			{
				new_node = binary_tree_node(current, value);
				current->right = new_node;
				return (new_node);
			}
		   else
				current = current->right;
		}
		else  /* Duplicate value */
			return (NULL);
	}
	return (NULL); /* Shouldn't reach here */
}
