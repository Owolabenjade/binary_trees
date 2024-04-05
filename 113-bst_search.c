#include "binary_trees.h"

/**
 * bst_search - Searches for a value in a Binary Search Tree.
 * @tree: A pointer to the root node of the BST to search.
 * @value: The value to search for in the tree.
 *
 * Description: This function traverses the tree following BST properties
 * to find a node with the given value. It returns a pointer to the found node,
 * or NULL if the value is not found or the tree is empty.
 *
 * Return: A pointer to the node containing a value equals to `value`,
 * or NULL if `value` is not found or `tree` is NULL.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
    if (!tree)
        return (NULL);  /* Base case: value not found or tree is empty */

    if (tree->n == value)
        return ((bst_t *)tree);  /* Value found, cast const away */

    if (value < tree->n)
        return bst_search(tree->left, value);  /* Search left subtree */
    else
        return bst_search(tree->right, value);  /* Search right subtree */
}

