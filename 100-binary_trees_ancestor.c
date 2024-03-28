#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 * @first: Pointer to the first node.
 * @second: Pointer to the second node.
 * Return: Pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first, const binary_tree_t *second)
{
    const binary_tree_t *temp_first, *temp_second;

    if (!first || !second)
        return NULL;

    temp_first = first;
    while (temp_first)
    {
        temp_second = second;
        while (temp_second)
        {
            if (temp_first == temp_second)
                return (binary_tree_t *)temp_first;
            temp_second = temp_second->parent;
        }
        temp_first = temp_first->parent;
    }
    return NULL;
}

