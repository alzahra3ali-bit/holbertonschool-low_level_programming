#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_get - retrieves a value associated with a key
 * @ht: the hash table you want to look into
 * @key: the key you are looking for
 *
 * Return: the value associated with the element, or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
hash_node_t node;
unsigned long int index;
if (key == 0 || *key == "\0" || ht == 0)
{
return (NULL);
}
index = key_index ((const unsigned char *)key,ht->size);
node = array[index];
while (node){
if (strcmp(node->key,key))
{
return(node->value);
}
node = node->next;
}
return (NULL);
}
