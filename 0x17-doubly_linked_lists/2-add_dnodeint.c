#include "lists.h"

/**
 * add_dnodeint - adds a new node at the beginning of a
 * dlistint_t list.
 * @head: the head of the list
 * @n: node data
 * Return: the size of the list
 */
dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *node;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->prev = NULL;

	if (!(*head))
	{
		*head = node;
		node->next = NULL;
	}
	else
	{
		while ((*head)->prev != NULL)
			*head = (*head)->prev;

		node->next = *head;
		(*head)->prev = node;
		*head = node;
	}

	return (node);
}
