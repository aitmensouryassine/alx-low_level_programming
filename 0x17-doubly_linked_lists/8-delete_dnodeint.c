#include "lists.h"

/**
 * delete_dnodeint_at_index -  deletes the node at index index of a
 * dlistint_t linked list.
 * @head: the head of the list
 * @index: is the index of the node that should be deleted. Index starts at 0
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	unsigned int i = 0;
	dlistint_t *tmp, *next, *prev;

	if (!(*head))
		return (-1);
	while ((*head)->prev)
		*head = (*head)->prev;
	tmp = *head;
	if (index == 0)
	{
		if (tmp->next == NULL)
			*head = NULL;
		else
			tmp->next->prev = NULL,	*head = tmp->next;
		free(tmp);
		return (1);
	}
	while (tmp)
	{
		if (i == index)
		{
			if (tmp->next == NULL)
			{
				tmp->prev->next = NULL;
				*head = tmp->prev;
			}
			else
			{
				prev = tmp->prev, next = tmp->next;
				prev->next = next, next->prev = prev;
			}
			free(tmp);
			return (1);
		}
		tmp = tmp->next, i++;
	}

	return (-1);
}
