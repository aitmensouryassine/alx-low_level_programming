#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list.
 * @head: the head of the list
 * @n: node data
 * Return: the address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *tmp = *head;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (!(*head))
	{
		*head = node;
		node->prev = NULL;
	}
	else
	{
		while (tmp->next)
			tmp = tmp->next;

		node->prev = tmp;
		tmp->next = node;
	}

	return (node);
}
