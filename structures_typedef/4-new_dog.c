#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dog.h"

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 *
 * Return: pointer to new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;
    
    if (!name || !owner)
        return NULL;

    /* Allocate memory for struct dog */
    d = malloc(sizeof(dog_t));
    if (d == NULL)
        return NULL;

    /* Allocate memory and copy name */
    d->name = malloc(strlen(name) + 1);
    if (d->name == NULL)
    {
        free(d);
        return NULL;
    }
    strcpy(d->name, name);

    /* Allocate memory and copy owner */
    d->owner = malloc(strlen(owner) + 1);
    if (d->owner == NULL)
    {
        free(d->name);
        free(d);
        return NULL;
    }
    strcpy(d->owner, owner);

    d->age = age;

    return d;
}
