#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 *
 * Return: Pointer to the lowest common ancestor node, otherwise NULL.
*/
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
	const binary_tree_t *tmp, *tmp2;

	if (first == NULL || second == NULL)
		return (NULL);

	for (tmp = first; tmp; tmp = tmp->parent)
	{
		/* Traverse upwards from 'first' */
		for (tmp2 = second; tmp2; tmp2 = tmp2->parent)
		{
			/* Traverse upwards from 'second' */
			if (tmp == tmp2) /* Common ancestor found */
				return ((binary_tree_t *)tmp);
		}
	}
	return (NULL); /* No common ancestor */
}

