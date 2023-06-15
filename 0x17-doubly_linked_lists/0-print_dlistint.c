#include "listst.h"

/**
 * print_dlistin - prints all the elements of a dlistint_t list.
 * @h: the head of the list
 * Return: the size of the list
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t size = 0;
	dlistint_t *tmp = h;

	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}

	return (size);
}
