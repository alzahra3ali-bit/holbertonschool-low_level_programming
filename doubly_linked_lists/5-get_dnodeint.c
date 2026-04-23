#include <stdlib.h>
#include "lists.h"

/**
 *get_dnodeint_at_index - return the nth node
 * @index: it is the index for the node we want to get
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
dlistint_t *temp = head;
int i = 0;
while (temp != NULL)
{
if (i == index )
{
return (temp);
}
else
temp =  temp->next;
i++;
}
return (NULL);
}
