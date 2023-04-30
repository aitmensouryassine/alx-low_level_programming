#include "lists.h"

/**
 * is_node_checked - checks if a node already checked
 * @head: head of the list
 * @curr: the current node
 * Return: 1 if checked, and 0 when not
 */
int is_node_checked(const listint_t *head, const listint_t *curr, size_t nodes)
{
	size_t i = 0;

	while (i < nodes)
	{
		if (head == curr)
			return (1);
		head = head->next;
		i++;
	}

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
	const listint_t *curr = head;

	while (curr)
	{
		printf("[%p] %d\n", (void *)curr, curr->n);
		nodes++;
		curr = curr->next;

		if (is_node_checked(head, curr, nodes))
		{
			printf("-> [%p] %d\n", (void *)curr, curr->n);
			return (nodes);
		}
		if (!head)
			exit(98);
	}

	return (nodes);
}
