#include "lists.h"

/**
 * add_node - adds a new node at the beginning of a list_t list.
 * @head: the head of the list
 * @str: a string to add as value for the node
 * Return: the address of the new element, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	unsigned int len = 0, i;
	list_t *new;

	while (str[len])
		len++;

	new = malloc(sizeof(list_t));
	if (!new)
		return (NULL);

	new->str = malloc(sizeof(char) + (len + 1));
	if (!(new->str))
		return (NULL);

	for (i = 0; str[i]; i++)
		new->str[i] = str[i];
	new->str[i] = '\0';

	new->len = len;
	new->next = *head;
	*head = new;

	return (*head);
}
