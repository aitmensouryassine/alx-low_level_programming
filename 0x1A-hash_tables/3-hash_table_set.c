#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value
 * Return: 1 on success, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *head, *new_hash_node;

	if (!ht || !key)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	new_hash_node = create_hash_node(key, value);
	if (!new_hash_node)
		return (0);

	head = ht->array[index];

	if (!head)
	{
		ht->array[index] = new_hash_node;
		return (1);
	}

	while (head)
	{
		if (strcmp(head->key, key) == 0)
		{
			free(head->value);
			head->value = strdup(value);

			/* free new has node (no need to use it) */
			free(new_hash_node->key);
			free(new_hash_node->value);
			free(new_hash_node);
			return (1);
		}
		head = head->next;
	}

	new_hash_node->next = ht->array[index];
	ht->array[index] = new_hash_node;

	return (1);
}

/**
 * create_hash_node - create a hash table node
 * @key: the key
 * @value: the value
 * Return: the address to the hash node, or NULL on failure
 */
hash_node_t *create_hash_node(const char *key, const char *value)
{
	hash_node_t *hash_node;

	hash_node = malloc(sizeof(hash_node_t));
	if (!hash_node)
		return (NULL);

	hash_node->key = strdup(key);
	hash_node->value = strdup(value);
	hash_node->next = NULL;

	if (!hash_node->key || !hash_node->value)
	{
		free(hash_node);
		return (NULL);
	}

	return (hash_node);
}
