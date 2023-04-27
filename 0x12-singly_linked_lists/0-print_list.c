#include "lists.h"

/**
 * print_list - prints a singly linked list
 * @h: the linked list head (a pointer)
 * Return: the number of nodes in a linked list
 */
size_t print_list(const list_t *h)
{
	size_t n = 0;
	char *str;
	int len = 0;

	while (h)
	{
		str = h->str, len = h->len;
		if (!str)
			str = "(nil)", len = 0;

		printf("[%i] %s\n", len, str);
		h = h->next;
		n++;
	}

	return (n);
}
