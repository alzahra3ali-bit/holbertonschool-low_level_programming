#include "lists.h"
#include <stdlib.h>
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: double pointer to head of list
 * @str: string to duplicate and store in node
 *
 * Return: address of new node, or NULL if failed
 */

list_t *add_node(list_t **head, const char *str)
{
list_t *newNode;
newNode = malloc (sizeof(list_t));
if(newNode == NULL)
return (NULL); newNode->str = strdup(str);
if (newNode->str == NULL)
{
free(newNode);
return (NULL);
}
newNode->len = strlen(str);
newNode->next = *head;
*head = newNode;
return (newNode);
}
