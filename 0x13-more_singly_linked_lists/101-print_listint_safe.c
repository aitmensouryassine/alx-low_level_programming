#include "lists.h"

/**
 * is_node_exist - checks if the address of node already exists
 * @ptr: pointer to addresses of nodes
 * @p: a pointer to thje address to check
 * Return: 1 when exist, and 0 when not
 */
int is_node_exist(int **ptr, int *p)
{
	int i = 0;

	while (ptr[i])
		if (ptr[i++] == p)
			return (1);

	return (0);
}

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: the head of the list
 * Return: the number of the nodes in a list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t nodes = 0;
	const listint_t *tmp = head;
	int **ptr;
	int i = 0;

	ptr = malloc(sizeof(**ptr));

	while (tmp)
	{
		if (is_node_exist(ptr, (void *)tmp))
		{
			printf("-> [%p] %d\n", (void *)tmp, tmp->n);
			return (nodes);
		}
		printf("[%p] %d\n", (void *)tmp, tmp->n);
		nodes++;

		*(ptr + i) = malloc(sizeof(ptr));
		*(ptr + i) = (int *)tmp;
		i++;

		tmp = tmp->next;
	}

	return (nodes);
}
