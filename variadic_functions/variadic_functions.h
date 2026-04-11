#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h>

/**
 * sum_them_all - returns the sum of all its parameters
 */
int sum_them_all(const unsigned int n, ...);

/**
 * print_numbers - prints numbers followed by a new line
 */
void print_numbers(const char *separator, const unsigned int n, ...);

/**
 * print_strings - prints strings followed by a new line
 */
void print_strings(const char *separator, const unsigned int n, ...);

#endif
