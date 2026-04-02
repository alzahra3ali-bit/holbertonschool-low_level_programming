#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space
 * which contains a copy of the string given as a parameter
 * @str: string to duplicate
 *
 * Return: pointer to the duplicated string, or NULL if str = NULL
 * or if memory allocation fails
 */
char *_strdup(char *str)
{
	char *dup;
	int i, len;

	if (str == NULL)
		return (NULL);

	/* حساب طول السلسلة */
	len = 0;
	while (str[len] != '\0')
		len++;

	/* تخصيص ذاكرة للطول + 1 للنهاية '\0' */
	dup = malloc((len + 1) * sizeof(char));
	if (dup == NULL)
		return (NULL);

	/* نسخ النص */
	for (i = 0; i < len; i++)
		dup[i] = str[i];

	/* إضافة النهاية */
	dup[len] = '\0';

	return (dup);
}
