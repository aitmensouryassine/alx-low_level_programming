#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: the head of the list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s = head, *f = head;

	if (!head)
		return (NULL);

	while (s && f && f->next)
	{
		s = s->next;
		f = f->next->next;

		if (s == f)
		{
			break;
		}
	}

	if (!s)
		return (NULL);

	s = head;
	while (s != f && s && f)
	{
		s = s->next;
		f = f->next;

		if (s == f)
		{
			return (s);
		}
	}

	return (NULL);
}
