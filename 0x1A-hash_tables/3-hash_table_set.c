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

	index = key_index((unsigned char *)key, ht->size);

	return (insert_hash_node(&(ht->array[index]), key, value));
}

/**
 * insert_hash_node - insert a hash node to the linked list
 * @head :the head of the list
 * @key: the key
 * @value: the value
 * Return: 0 on success, 1 otherwise
 */
int insert_hash_node(hash_node_t **head, const char *key,
			      const char *value)
{
	hash_node_t *tmp = *head, *new_hash_node;

	new_hash_node = create_hash_node(key, value);
	if (!new_hash_node)
		return (1);

	if (!tmp)
	{
		*head = new_hash_node;
		return (0);
	}

	while (tmp)
	{
		if (strcmp(tmp->key, key) == 0)
		{
			strcpy(tmp->value, value);
			return (0);
		}
		tmp = tmp->next;
	}

	new_hash_node->next = *head;
	*head = new_hash_node;

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

	if (!hash_node->key || !hash_node->value)
	{
		free(hash_node);
		return (NULL);
	}

	strcpy(hash_node->key, key);
	strcpy(hash_node->value, value);

	return (hash_node);
}
