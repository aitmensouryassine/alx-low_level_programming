#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table.
 * @ht: the hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i, count = 0;
	hash_node_t *head;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		head = ht->array[i];
		if (head)
		{
			while (head)
			{
				if (count)
				{
					printf(", ");
					count = 0;
				}
				printf("'%s': '%s'", head->key, head->value);
				count = 1;
				head = head->next;
			}
		}
	}
	printf("}\n");
}
