#include "lists.h"

/**
 * sum_dlistint - Calculate the sum of data in each node
 * @head: pointer to head of list
 * @sum: to sum data 
 *
 * Return: the sum of data
 */
int sum_dlistint(dlistint_t *head)
{
dlistint_t *temp = head;
int sum = 0;
while (temp != NULL)
{
sum += temp->n;
temp = temp->next;
}
return (sum);
}
