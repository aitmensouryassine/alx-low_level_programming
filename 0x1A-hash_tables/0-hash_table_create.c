#include "hash_tables.h"

/**
 * hash_table_create - function that creates a hash table.
 * @size: The size of the hash table
 * Return: pointer to the newly created hash table on success,
 * or NULL on failure
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;
	unsigned long int i;
	hash_node_t **array;

	ht = malloc(sizeof(hash_table_t));
	if (!ht)
		return (NULL);

	array = malloc(sizeof(hash_node_t));
	if (!array)
		return (NULL);

	*array = malloc(sizeof(hash_node_t) * size);
	if (!(*array))
		return (NULL);

	for (i = 0; i < size; i++)
		array[i] = NULL;

	ht->size = size;
	ht->array = array;

	return (ht);
}
