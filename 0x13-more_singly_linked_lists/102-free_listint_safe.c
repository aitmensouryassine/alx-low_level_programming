#include "lists.h"

/**
 * address_difference - calculates the difference between two addresses
 * @addr1: firsdt address
 * @addr2: second address
 * Return: the difference
 */
int address_difference(listint_t *addr1, listint_t *addr2)
{
	return (addr1 - addr2);
}

/**
 * free_listint_safe - frees a listint_t list.
 * @h: the head of the list
 * Return: the number of the nodes in a list
 */
size_t free_listint_safe(listint_t **h)
{
	size_t nodes = 0;
	listint_t *tmp;

	if (!*h)
		return (nodes);

	while (*h)
	{
		nodes++;

		if (address_difference(*h, (*h)->next) <= 0)
		{
			free(*h);
			break;
		}

		tmp = (*h)->next;
		free(*h);
		*h = tmp;
	}
	*h = NULL;

	return (nodes);
}
