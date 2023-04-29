#include "lists.h"

/**
 * free_listint2 - frees a listint_t list.
 * @head: the head of the list
 */
void free_listint2(listint_t **head)
{
	listint_t *tmp;

	if (head)
	{
		while ((*head))
		{
			tmp = (*head)->next;
			free(*head);
			*head = tmp;
		}
		*head = NULL;
	}
}
