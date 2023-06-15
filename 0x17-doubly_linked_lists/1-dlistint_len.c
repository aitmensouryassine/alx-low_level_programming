#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * dlistint_len - prints all the elements of a dlistint_t list.
 * @h: the head of the list
 * Return: the size of the list
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t size = 0;
	const dlistint_t *tmp = h;

	while (tmp->prev)
		tmp = tmp->prev;

	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}

	return (size);
}
