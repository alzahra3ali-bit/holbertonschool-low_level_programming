#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times
 */
void print_alphabet_x10(void)
{
	char c;
	int counter = 0;
	while(counter < 10)
	{
		for(c = 'a'; c <= 'z'; c++)
		{
			_putchar(c);
		}
		counter++;
		_putchar('\n');
	}
}
