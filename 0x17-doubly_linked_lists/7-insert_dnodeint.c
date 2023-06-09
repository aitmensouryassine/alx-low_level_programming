#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position.
 * @h: the head of the list
 * @idx: index of the list where the new node should be added
 * @n: new node data
 * Return: the address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;
	dlistint_t *head = *h, *node;

	node = malloc(sizeof(dlistint_t));
	if (!node)
		return (NULL);
	node->n = n;

	if (!head && idx != 0)
		return (NULL);

	if (!head && idx == 0)
		return (add_dnodeint(h, n));

	while (head->prev)
		head = head->prev;

	if (idx == 0)
		return (add_dnodeint(h, n));

	while (head)
	{
		if (i == idx)
		{
			node->next = head;
			node->prev = head->prev;
			head->prev->next = node;
			head->prev = node;

			return (node);
		}
		head = head->next;
		i++;
	}

	if (i == idx)
		return (add_dnodeint_end(h, n));

	return (NULL);
}
