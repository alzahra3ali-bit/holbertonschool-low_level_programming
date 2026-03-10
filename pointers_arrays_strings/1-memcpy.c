#include "main.h"

/**
 * _memcpy - copies memory area
 * @dest: memory area where it is stored
 * @src: memory area where it is copied
 * @n: number of bytes to copy
 *
 * Return: pointer to dest
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}

	return (dest);
}
