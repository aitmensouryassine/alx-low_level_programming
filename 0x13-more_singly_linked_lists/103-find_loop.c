#include "lists.h"

/**
 * has_loop - check if a linked list has a loop
 * it uses Floyd's Cycle Detection Algorithm
 * @head: the head of the list
 * Return: the node where the intersection happened,
 * or NULL if there is no loop
 */
listint_t *has_loop(listint_t *head)
{
	listint_t *f = head, *s = head;

	while (s && f)
	{
		s = s->next;
		f = f->next->next;

		if (s == f)
			return (s);
	}

	return (NULL);
}

/**
 * find_listint_loop - finds the loop in a linked list.
 * @head: the head of the list
 * Return: The address of the node where the loop starts,
 * or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *s, *f;

	if (!head)
		return (NULL);

	f = first_intersection(head);
	if (!f)
		return (NULL);

	s = head;
	while (s != f)
	{
		s = s->next;
		f = f->next;
	}

	return (s);
}
