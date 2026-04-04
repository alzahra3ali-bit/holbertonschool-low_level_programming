#include <stdlib.h>
#include "dog.h"

/**
 * str_len - returns the length of a string
 * @s: string
 * Return: length
 */
int str_len(char *s)
{
    int i = 0;
    while (s[i])
        i++;
    return i;
}

/**
 * new_dog - creates a new dog
 * @name: name of the dog
 * @age: age of the dog
 * @owner: owner of the dog
 * Return: pointer to new dog, or NULL if it fails
 */
dog_t *new_dog(char *name, float age, char *owner)
{
    dog_t *d;
    int i;

    if (!name || !owner)
        return NULL;

    d = malloc(sizeof(dog_t));
    if (!d)
        return NULL;

    d->name = malloc(str_len(name) + 1);
    if (!d->name)
    {
        free(d);
        return NULL;
    }
    for (i = 0; name[i]; i++)
        d->name[i] = name[i];
    d->name[i] = '\0';

    d->owner = malloc(str_len(owner) + 1);
    if (!d->owner)
    {
        free(d->name);
        free(d);
        return NULL;
    }
    for (i = 0; owner[i]; i++)
        d->owner[i] = owner[i];
    d->owner[i] = '\0';

    d->age = age;

    return d;
}
