#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Performs a left-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Description: This function performs a left rotation on a binary tree.
 * The right child of the root becomes the new root of the subtree,
 * the original root becomes the left child of the new root, and
 * the left child of the new root (if it exists) becomes the right child
 * of the original root. The operation preserves the binary search tree properties.
 *
 * Return: A pointer to the new root node of the tree once rotated.
 * If tree is NULL, or the rotation cannot be performed, returns the original tree.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_tree_t *tree)
{
    binary_tree_t *new_root;

    if (tree == NULL || tree->right == NULL)
        return tree; /* Return the original tree if rotation is not possible */

    new_root = tree->right; /* The new root is the current right child */
    tree->right = new_root->left; /* The left child of the new root becomes the right child of the old root */

    if (new_root->left != NULL)
        new_root->left->parent = tree; /* Update the parent of the moved node, if it exists */

    new_root->left = tree; /* The old root becomes the left child of the new root */
    new_root->parent = tree->parent; /* Update the parent pointer of the new root */
    tree->parent = new_root; /* The parent of the old root is now the new root */

    return new_root; /* Return the new root of the subtree */
}

