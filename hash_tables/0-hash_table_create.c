#include "hash_tables.h"
/*
 *hash_table_t - method creat a hash table
 *@size : is the size of hash table
 *Return : the new hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t*  MyTable;
MyTable = malloc(sizeof(size));
if (MyTable == NULL)
{
return(NULL);
}
MyTable->size = size;
hash_node_t** array;
array = malloc(sizeof(hash_node_t *)*size);
if (array == NULL)
{
free(MyTable);
return(NULL);
}
MyTable->array = array;
unsigned long int i;
for(i = 0; i< size; i++)
{
array[i] = NULL;
}
return(MyTable);
}
