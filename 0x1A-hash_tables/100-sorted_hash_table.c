#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: the size of the hash table
 * Return: A pointer to created hash table
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	shash_node_t **array;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;

	array = malloc(sizeof(shash_node_t *) * size);
	if (!array)
		return (NULL);

	ht->array = array;
	for (i = 0; i < ht->size; i++)
		ht->array[i] = NULL;

	return (ht);
}
/**
 * shash_table_set - inserts a key/value pair (node) in the sorted
 * (Sorted by ASCCI code) list at the right place.
 * @ht: the sorted hash table
 * @key: the key
 * @value: the value
 * Return: 1 on success, 0 on failure
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new_shash_node;

	if (!ht || !key || !value)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	new_shash_node = create_shash_node(key, value);
	if (!new_shash_node)
		return (0);

	add_node_to_sorted_list(ht, new_shash_node);
	add_node_to_list(ht, index, new_shash_node);

	return (1);
}

/**
 * add_node_to_list - adds a node to the list
 * @ht: the hash table
 * @index: the index of the key/value pair
 * @new_shash_node: the new hash node
 */
void add_node_to_list(shash_table_t *ht, unsigned long int index,
		      shash_node_t *new_shash_node)
{
	shash_node_t *head;

	head = ht->array[index];

	if (!head)
	{
		ht->array[index] = new_shash_node;
		return;
	}

	while (head)
	{
		if (strcmp(head->key, new_shash_node->key) == 0)
		{
			free(head->value);
			head->value = strdup(new_shash_node->value);

			/* free new shash node (no need to use it) */
			free(new_shash_node->key);
			free(new_shash_node->value);
			free(new_shash_node);
			return;
		}
		head = head->next;
	}

	new_shash_node->next = ht->array[index];
	ht->array[index] = new_shash_node;
}

/**
 * add_node_to_sorted_list - add the new node to the sorted list
 * @ht: the sorted hash table
 * @new_shash_node: the new hash node
 */
void add_node_to_sorted_list(shash_table_t *ht, shash_node_t *new_shash_node)
{
	shash_node_t *shead, *curr;

	shead = ht->shead;
	if (!shead)
	{
		ht->shead = new_shash_node;
		ht->stail = new_shash_node;
		return;
	}

	if (strcmp(new_shash_node->key, shead->key) <= 0)
	{
		new_shash_node->snext = shead;
		new_shash_node->sprev = NULL;

		shead->sprev = new_shash_node;
		ht->shead = new_shash_node;
		return;
	}

	curr = shead->snext;
	while (curr)
	{
		if (strcmp(new_shash_node->key, curr->key) <= 0)
		{
			new_shash_node->snext = curr;
			new_shash_node->sprev = curr->sprev;

			curr->sprev->snext = new_shash_node;
			curr->sprev = new_shash_node;
			return;
		}
		curr = curr->snext;
	}

	ht->stail->snext = new_shash_node;
	new_shash_node->sprev = ht->stail;
	new_shash_node->snext = NULL;
	ht->stail = new_shash_node;
}

/**
 * create_shash_node - create a sorted hash table node
 * @key: the key
 * @value: the value
 * Return: the address to the sorted hash table node, or NULL on failure
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
	shash_node_t *shash_node;

	shash_node = malloc(sizeof(shash_node_t));
	if (!shash_node)
		return (NULL);

	shash_node->key = strdup(key);
	shash_node->value = strdup(value);
	shash_node->next = NULL;
	shash_node->sprev = NULL;
	shash_node->snext = NULL;

	if (!shash_node->key || !shash_node->value)
	{
		free(shash_node);
		return (NULL);
	}

	return (shash_node);
}

/**
 * shash_table_get - gets element value with a key
 * @ht: the sorted hash table
 * @key: the key
 * Return: the value
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *head;

	if (!ht || !key)
		return (NULL);

	index = key_index((unsigned char *)key, ht->size);
	head = ht->array[index];

	while (head)
	{
		if (strcmp(head->key, key) == 0)
			return (head->value);

		head = head->next;
	}

	return (NULL);
}

/**
 * shash_table_print - print the hash table using the sorted linked list
 * @ht: the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *shead;
	int comma_flag = 0;

	if (!ht || !ht->shead)
		return;

	shead = ht->shead;

	printf("{");
	while (shead)
	{
		if (comma_flag)
		{
			printf(", ");
			comma_flag = 0;
		}

		printf("'%s': '%s'", shead->key, shead->value);
		comma_flag = 1;
		shead = shead->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print the hash tables key/value pairs in
 * reverse order using the sorted linked list
 * @ht: the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *stail;
	int comma_flag = 0;

	if (!ht || !ht->stail)
		return;

	stail = ht->stail;

	printf("{");

	while (stail)
	{
		if (comma_flag)
		{
			printf(", ");
			comma_flag = 0;
		}
		printf("'%s': '%s'", stail->key, stail->value);
		comma_flag = 1;
		stail = stail->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *tmp;

	if (!ht || !ht->shead)
		return;

	while (ht->shead)
	{
		tmp = ht->shead->snext;

		free(ht->shead->key);
		free(ht->shead->value);
		free(ht->shead);

		ht->shead = tmp;
	}
	free(ht->array);
	free(ht);
}
