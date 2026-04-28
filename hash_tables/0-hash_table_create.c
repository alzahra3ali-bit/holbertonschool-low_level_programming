#include "hash_tables.h"

/**
 * hash_table_create - creates a hash table
 * @size: size of the hash table
 *
 * Return: pointer to the new hash table, or NULL if failed
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *MyTable;
	hash_node_t **array;
	unsigned long int i;

	MyTable = malloc(sizeof(hash_table_t));
	if (MyTable == NULL)
		return (NULL);

	MyTable->size = size;

	array = malloc(sizeof(hash_node_t *) * size);
	if (array == NULL)
	{
		free(MyTable);
		return (NULL);
	}

	MyTable->array = array;

	for (i = 0; i < size; i++)
		MyTable->array[i] = NULL;

	return (MyTable);
}
