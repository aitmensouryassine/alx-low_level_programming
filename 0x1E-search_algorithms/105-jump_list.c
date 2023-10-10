#include "search_algos.h"
#include <math.h>

/**
 * jump_list - searches for a value in a sorted list of integers using
 * the Jump search algorithm
 * @list: is a pointer to the head of the list to search in
 * @size: is the number of nodes in list
 * @value: is the value to search for
 * Return: return a pointer to the first node where value is located
 * or NULL on failure
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	if (!list)
		return (NULL);
}
