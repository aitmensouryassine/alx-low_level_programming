#include "lists.h"

/**
 * pop_listint - deletes the head node of a listint_t linked list
 * @head: the head of the list
 * Return: returns the head node’s data (n).
 */
int pop_listint(listint_t **head)
{
	int n;
	listint_t *tmp;

	if (!(*head))
		return (0);

	tmp = (*head)->next;

	n = (*head)->n;
	free(*head);

	*head = tmp;

	return (n);
}
