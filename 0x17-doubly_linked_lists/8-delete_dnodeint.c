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
	dlistint_t *tmp = *head, *next, *prev;

	if (!tmp)
		return (-1);

	while (tmp->prev)
		tmp = tmp->prev;

	if (index == 0)
	{
		if (tmp->next == NULL)
		{
			free(tmp);
			*head = NULL;
			return (1);
		}
		tmp->next->prev = NULL;
		*head = tmp->next;
		free(tmp);
		return (1);
	}
	while (tmp)
	{
		if (i == index)
		{
			prev = tmp->prev;
			next = tmp->next;
			prev->next = next;
			next->prev = prev;

			free(tmp);
			return (1);
		}
		tmp = tmp->next;
		i++;
	}

	return (-1);
}
