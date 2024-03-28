#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_is_complete - checks if a binary tree is complete
 * @tree: pointer to the root node of the tree to check
 * Return: 1 if complete, 0 if not or if tree is NULL
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
    const binary_tree_t **queue;
    int front = 0, back = 0, non_full_node = 0, size = 1024;

    if (!tree)
        return (0);

    queue = malloc(sizeof(*queue) * size);
    if (!queue)
        return (0);

    queue[back++] = tree;

    while (front < back)
    {
        const binary_tree_t *current = queue[front++];

        if (!current->left)
            non_full_node = 1;
        else
        {
            if (non_full_node)
            {
                free(queue);
                return (0);
            }
            if (back >= size)
            {
                size *= 2;
                queue = realloc(queue, sizeof(*queue) * size);
                if (!queue)
                    return (0); // Memory allocation error
            }
            queue[back++] = current->left;
        }

        if (!current->right)
            non_full_node = 1;
        else
        {
            if (non_full_node)
            {
                free(queue);
                return (0);
            }
            if (back >= size)
            {
                size *= 2;
                queue = realloc(queue, sizeof(*queue) * size);
                if (!queue)
                    return (0); // Memory allocation error
            }
            queue[back++] = current->right;
        }
    }

    free(queue);
    return (1);
}

