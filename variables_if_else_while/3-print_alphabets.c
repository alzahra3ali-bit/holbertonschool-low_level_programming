#include <stdio.h>

/**
 * main - prints lowercase and uppercase alphabet
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
char c;
char C;
for(c='a';c<='z';c++)
{
putchar(c);
}
for(C='A';C<='Z';C++)
{
putchar(C);
putchar('\n');
}
}
