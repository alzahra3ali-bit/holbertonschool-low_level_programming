#include "main.h"

/**
 * _strcpy - copies the string pointed to by src
 * @dest: buffer to copy to
 * @src: string to copy from
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}

	dest[i] = '\0'; /* Copy the null terminator */

	return (dest);
}
