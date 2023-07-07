#include "hash_tables.h"

/**
 * hash_table_delete - deletes a hash table
 * @ht: the hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *tmp, *head;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		head = ht->array[i];
		if (head)
			while (head)
			{
				tmp = head->next;

				free(head->key);
				free(head->value);
				free(head);

				head = tmp;
			}
	}
	free(ht->array);
	free(ht);
}
