#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index index of
 * a listint_t linked list.
 * @head: the head of the list
 * @index: index of the node to delete
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *tmp = *head, *tmp1 = *head;
	unsigned int i = 0;

	if (*head && index == 0)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
		return (1);
	}

	if (*head && index > 0)
	{
		tmp = *head;
		while (tmp && i <= index)
		{
			if (i == index)
			{
				tmp1->next = tmp->next;
				free(tmp);
				return (1);
			}
			tmp1 = tmp; /* node i - 1 */
			tmp = tmp->next; /* i */
			i++;
		}
	}

	return (-1);
}
