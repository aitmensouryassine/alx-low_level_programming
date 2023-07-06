#include "hash_tables.h"

/**
 * hash_table_set - adds an element to the hash table
 * @ht: the hash table
 * @key: the key
 * @value: the value
 * Return: 0 on success, 1 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	hash_node_t *head, *new_hash_node;

	index = key_index((unsigned char *)key, ht->size);
	head = ht->array[index];

	new_hash_node = create_hash_node(key, value);
	if (!new_hash_node)
		return (1);

	if (!head)
	{
		ht->array[index] = new_hash_node;
		return (0);
	}

	while (head)
	{
		if (strcmp(head->key, key) == 0)
		{
			strcpy(head->value, value);
			return (0);
		}
		head = head->next;
	}

	new_hash_node->next = ht->array[index];
	ht->array[index] = new_hash_node;

	return (0);
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

	hash_node->key = malloc(sizeof(key));
	hash_node->value = malloc(sizeof(value));
	hash_node->next = NULL;

	if (!hash_node->key || !hash_node->value)
	{
		free(hash_node);
		return (NULL);
	}

	strcpy(hash_node->key, key);
	strcpy(hash_node->value, value);

	return (hash_node);
}
