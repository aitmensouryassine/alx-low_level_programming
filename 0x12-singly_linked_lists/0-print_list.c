#include "lists.h"

/**
 * print_list - prints a singly linked list
 * @h: the linked list head (a pointer)
 * Return: the number of nodes in a linked list
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;

	while (h)
	{
		printf("[%i] %s\n", h->len, h->str);
		h = h->next;
		n++;
	}

	return n;
}
