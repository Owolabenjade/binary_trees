#include "binary_trees.h"
#include <stdlib.h>

/**
 * enqueue - Adds a new node to the end of the queue
 * @head: Pointer to the head of the queue
 * @tail: Pointer to the tail of the queue
 * @node: Node to enqueue
 * struct queue_node: Structure for a queue node
*/
 
typedef struct queue_node
{
	 binary_tree_t *node;
	 struct queue_node *next;
} queue_t;

void enqueue(queue_t **head, queue_t **tail, const binary_tree_t *node)
{
	queue_t *new = malloc(sizeof(queue_t));

	if (new == NULL)
		return;

	new->node = (binary_tree_t *)node;
	new->next = NULL;
	if (*tail == NULL)
		*head = new; /* If the queue was empty */
	else
		(*tail)->next = new;
	*tail = new; /* Update tail pointer */
}

/**
 * dequeue - Removes the node at the head of the queue
 * @head: Pointer to the head of the queue
 * @tail: Pointer to the tail of the queue
 *
 * Return: The removed node, or NULL if the queue is empty
 */
 binary_tree_t *dequeue(queue_t **head, queue_t **tail)
{
	queue_t *tmp = *head;
	binary_tree_t *node;

	if (*head == NULL)
		return NULL;  /* Queue is empty */

	*head = (*head)->next;
	node = tmp->node;

	if (*head == NULL)
		*tail = NULL; /* Queue is now empty */

	free(tmp);
	return (node);
}

/**
 * binary_tree_levelorder - Traverses a binary tree using level-order traversal.
 * @tree: Pointer to the root node of the tree to traverse.
 * @func: Pointer to a function to call for each node.
*/
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	queue_t *head = NULL, *tail = NULL;

	if (tree == NULL || func == NULL)
		return;

	/* Enqueue the root */
	enqueue(&head, &tail, tree);

	while (head != NULL)
	{
		binary_tree_t *curr_node = dequeue(&head, &tail);
		func(curr_node->n); /* Process the node */

		/* Enqueue children */
		if (curr_node->left)
			enqueue(&head, &tail, curr_node->left);
		if (curr_node->right)
			enqueue(&head, &tail, curr_node->right);
	}
}

