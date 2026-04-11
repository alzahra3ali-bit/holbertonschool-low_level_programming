#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_c - prints char
 */
void print_c(va_list args, char *sep)
{
	printf("%s%c", sep, va_arg(args, int));
}

/**
 * print_i - prints integer
 */
void print_i(va_list args, char *sep)
{
	printf("%s%d", sep, va_arg(args, int));
}

/**
 * print_f - prints float
 */
void print_f(va_list args, char *sep)
{
	printf("%s%f", sep, va_arg(args, double));
}

/**
 * print_s - prints string
 */
void print_s(va_list args, char *sep)
{
	char *s = va_arg(args, char *);

	if (!s)
		s = "(nil)";

	printf("%s%s", sep, s);
}

/**
 * print_all - prints anything
 */
void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	int j;
	char *sep = "";

	struct printer
	{
		char type;
		void (*func)(va_list, char *);
	};

	struct printer p[] = {
		{'c', print_c},
		{'i', print_i},
		{'f', print_f},
		{'s', print_s}
	};

	va_start(args, format);

	while (format && format[i])
	{
		j = 0;

		while (j < 4)
		{
			if (format[i] == p[j].type)
			{
				p[j].func(args, sep);
				sep = ", ";
			}

			j++;
		}

		i++;
	}

	printf("\n");

	va_end(args);
}
