#include "main.h"

/**
 * leet - encodes a string into 1337
 * @str: the string to encode
 *
 * Return: pointer to the encoded string
 */
char *leet(char *str)
{
	int i = 0;
	int j;
	char letters[] = "aAeEoOtTlL";
	char numbers[] = "4433007711";

	while (str[i] != '\0')
	{
		j = 0;
		while (letters[j] != '\0')
		{
			if (str[i] == letters[j])
			{
				str[i] = numbers[j];
				break;
			}
			j++;
		}
		i++;
	}

	return (str);
}
