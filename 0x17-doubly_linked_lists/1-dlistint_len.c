#include "lists.h"

/**
 * dlistint_len - returns the number of elements indouble linked  list
 * @h: the head of the list
 * Return: the size of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	int size = 0;

	if (h == NULL)
		return (0);

	while (h->prev != NULL)
		h = h->prev;

	while (h != NULL)
	{
		h = h->next;
		size++;
	}

	return (size);
}
