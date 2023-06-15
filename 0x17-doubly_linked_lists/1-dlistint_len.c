#include "lists.h"

/**
 * dlistint_len - prints all the elements of a dlistint_t list.
 * @h: the head of the list
 * Return: the size of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int size = 0;

	if (!h)
		return (0);

	while (h->prev)
		h = h->prev;

	while (h)
	{
		h = h->next;
		size++;
	}

	return (size);
}
