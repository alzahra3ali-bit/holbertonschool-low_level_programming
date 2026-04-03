#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * string_nconcat - concatenates s1 with first n bytes of s2
 * @s1: first string
 * @s2: second string
 * @n: number of bytes from s2 to concatenate
 *
 * Return: pointer to newly allocated string, or NULL if fails
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *new_str;
	unsigned int len_s1, len_s2, total_len, i, j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len_s1 = strlen(s1);
	len_s2 = strlen(s2);

	if (n > len_s2)
		n = len_s2;

	total_len = len_s1 + n + 1;

	new_str = malloc(total_len);
	if (new_str == NULL)
		return (NULL);

	for (i = 0; i < len_s1; i++)
		new_str[i] = s1[i];

	for (j = 0; j < n; j++)
		new_str[i + j] = s2[j];

	new_str[i + j] = '\0';

	return (new_str);
}
