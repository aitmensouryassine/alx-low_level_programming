#include "lists.h"

/**
 * reverse_listint - reverses a listint_t linked list.
 * @head: the head of the list
 * Return: a pointer to the first node of the reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *curr = *head, *prev = NULL;

	while (curr)
	{
		*head = curr->next;
		curr->next = prev;

		prev = curr;
		curr = *head;
	}
	*head = prev;

	return (*head);
}
