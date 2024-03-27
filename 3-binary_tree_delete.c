#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree.
 * @tree: A pointer to the root node of the tree to delete.
 */
void binary_tree_delete(binary_tree_t *tree)
{
    if (!tree)
        return;

    /* Recursively delete left subtree */
    binary_tree_delete(tree->left);

    /* Recursively delete right subtree */
    binary_tree_delete(tree->right);

    /* Delete current node */
    free(tree);
}
