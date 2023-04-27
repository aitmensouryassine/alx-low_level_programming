#include "lists.h"

/**
 * free_list - frees a list_t list.
 * @head: head of the list
 */
void free_list(list_t *head)
{
	list_t *tmp;

	while (head)
	{
		tmp = head;
		free(tmp->str);
		head = head->next;
		free(tmp);
	}
}
