#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new hash table, or NULL if failed
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *my_table;
	unsigned long int i;

	my_table = malloc(sizeof(hash_table_t));
	if (my_table == NULL)
		return (NULL);

	my_table->size = size;
	my_table->array = malloc(sizeof(hash_node_t *) * size);
	if (my_table->array == NULL)
	{
		free(my_table);
		return (NULL);
	}

	for (i = 0; i < size; i++)
		my_table->array[i] = NULL;

	return (my_table);
}
