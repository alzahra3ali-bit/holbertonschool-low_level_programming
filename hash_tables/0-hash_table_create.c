hash_table_t *hash_table_create(unsigned long int size)
{
hash_table_t*  MyTable;
MyTable = malloc(sizeof(size));
if (MyTable == NULL)
{
return(NULL);
}
MyTable->size = size;
hash_node_t** [size] array;
array = malloc(sizeof(hash_node_t)*size);
if (array == NULL)
{
free(MyTable);
return(NULL);
}
MyTable->array = array;
int i;
for(i = 0; i< size; i++)
{
array[i] = NULL;
}
return(MyTable);
}
