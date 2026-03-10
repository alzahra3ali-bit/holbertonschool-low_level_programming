#include "main.h"

/**
 * print_chessboard - prints the chessboard
 * @a: pointer to an array of 8 characters
 *
 * Return: void
 */
void print_chessboard(char (*a)[8])
{
	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			/* الوصول للعنصر في الصف i والعمود j */
			_putchar(a[i][j]);
		}
		/* طباعة سطر جديد بعد كل 8 أحرف */
		_putchar('\n');
	}
}
