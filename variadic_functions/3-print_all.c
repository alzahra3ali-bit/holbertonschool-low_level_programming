#include "variadic_functions.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_all - prints anything
 * @format: list of argument types
 */

void print_all(const char * const format, ...)
{
	va_list args;
	int i = 0;
	char *sep = "";
	char *s;

	va_start(args, format);

	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			printf("%s%c", sep, va_arg(args, int));
			sep = ", ";
		}

		if (format[i] == 'i')
		{
			printf("%s%d", sep, va_arg(args, int));
			sep = ", ";
		}

		if (format[i] == 'f')
		{
			printf("%s%f", sep, va_arg(args, double));
			sep = ", ";
		}

		if (format[i] == 's')
		{
			s = va_arg(args, char *);
			if (!s)
				s = "(nil)";
			printf("%s%s", sep, s);
			sep = ", ";
		}

		i++;
	}

	printf("\n");

	va_end(args);
}
