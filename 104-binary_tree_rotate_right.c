#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Performs a right-rotation on a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Description: This function performs a right rotation on a binary tree,
 * making the left child of the root become the new root of the subtree,
 * while the original root becomes the right child of the new root.
 * The process involves updating the parent-child relationships
 * to maintain the binary tree's structure.
 *
 * Return: A pointer to the new root node of the tree once rotated,
 * or NULL if the rotation could not be performed.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
    binary_tree_t *new_root, *tmp_right;

    if (!tree || !tree->left)
        return (tree); /* If tree is NULL or doesn't have a left child, no rotation is done. */

    new_root = tree->left; /* The new root is the current left child of the original root. */
    tmp_right = new_root->right; /* Temporarily store the right child of the new root. */

    new_root->right = tree; /* The original root becomes the right child of the new root. */
    tree->left = tmp_right; /* The saved right child of the new root becomes the left child of the original root. */

    /* Update parent pointers */
    if (tmp_right)
        tmp_right->parent = tree; /* Set the parent of the moved node, if it exists. */
    if (tree->parent)
        new_root->parent = tree->parent; /* Link the new root with the parent of the original root, if it exists. */
    tree->parent = new_root; /* Set the parent of the original root to the new root. */

    return (new_root); /* Return the new root after rotation. */
}

