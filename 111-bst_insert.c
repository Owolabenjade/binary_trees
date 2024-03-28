#include "binary_trees.h"

/**
 * bst_insert - Inserts a value into a Binary Search Tree.
 * @tree: Double pointer to the root node of the BST where the value is to be inserted.
 * @value: The value to be inserted.
 *
 * Description: Inserts a value into a BST. If the value is already present,
 * it is ignored. If the tree is empty, the created node becomes the root.
 * The function returns a pointer to the created node, or NULL on failure
 * or if the value is already present.
 *
 * Return: Pointer to the created node, or NULL.
 */
bst_t *bst_insert(bst_t **tree, int value)
{
    bst_t *current, *parent = NULL;

    if (tree == NULL)
        return (NULL);  /* Handle NULL tree pointer */

    /* Find the correct location in the tree for the new value */
    current = *tree;
    while (current != NULL)
    {
        parent = current; /* Track the parent for the new node */
        if (value < current->n)
            current = current->left;  /* Go left if value is less */
        else if (value > current->n)
            current = current->right; /* Go right if value is more */
        else
            return (NULL); /* Value already exists, do nothing */
    }

    /* Create and link the new node */
    bst_t *new_node = binary_tree_node(parent, value);
    if (new_node == NULL)
        return (NULL); /* Memory allocation failed */

    /* If the tree was empty, update the tree root */
    if (parent == NULL)
        *tree = new_node;
    else if (value < parent->n)
        parent->left = new_node; /* Insert as left child */
    else
        parent->right = new_node; /* Insert as right child */

    return (new_node);
}

