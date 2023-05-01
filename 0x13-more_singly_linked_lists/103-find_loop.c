#include "lists.h"

/**
 * is_node_checked1 - checks if a node already checked
 * @head: head of the list
 * @curr: the current node
 * @nodes: number of checked nodes
 * Return: 1 if checked, and 0 when not
 */
int is_node_checked1(listint_t *head, listint_t *curr, size_t nodes)
{
	size_t i = 0;

	while (i < nodes)
	{
		if (head == curr)
			return (1);
		head = (head)->next;
		i++;
	}

	return (0);
}

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: the head of the list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	size_t nodes = 0;
	listint_t *curr = head;

	if (!head)
		return (NULL);

	while (curr)
	{
		curr = curr->next;
		nodes++;

		if (is_node_checked1(head, curr, nodes))
		{
			return (curr);
		}
	}

	return (NULL);
}
