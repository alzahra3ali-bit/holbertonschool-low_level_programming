#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>

/**
 * struct hash_node_s - Node of a hash table
 */
typedef struct hash_node_s
{
    char *key;
    char *value;
    struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table structure
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;

/* function prototype */
hash_table_t *hash_table_create(unsigned long int size);

#endif
