#include <stdio.h>

/**
 * main - prints the name of the program
 * @argc: number of arguments (unused)
 * @argv: array of arguments (contains the program name)
 *
 * Return: Always 0
 */
int main(int argc __attribute__((unused)), char *argv[])
{
	printf("%s\n", argv[0]);
	return (0);
}
