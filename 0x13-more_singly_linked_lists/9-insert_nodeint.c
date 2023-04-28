#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position.
 * @head : head of the list
 * @idx: position of the new node
 * @n: data
 * Return: the new node, or NULL on failure
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new, *tmp, *tmp1;
	unsigned int i = 0;

	new = malloc(sizeof(listint_t));
	if (!new)
		return (NULL);
	new->n = n;

	if (!*head && idx == 0)
	{
		*head = new;
		new->next = NULL;
		return (new);
	}

	if (*head && idx == 0)
	{
		tmp = *head;
		*head = new;
		new->next = tmp;
		return (new);
	}

	tmp = *head;
	while (tmp)
	{
		if (i == idx - 1)
		{
			tmp1 = tmp->next;
			tmp->next = new;
			new->next = tmp1;
			return (new);
		}
		tmp = tmp->next;
		i++;
	}

	free(new);
	return (NULL);
}
