#include "main.h"

void print_rev(char *s)
{
    int len = 0;

    /* احسب طول النص */
    while (s[len] != '\0')
    {
        len++;
    }

    /* آخر حرف هو len - 1 */
    len--;

    /* اطبع بالعكس */
    while (len >= 0)
    {
        _putchar(s[len]);
        len--;
    }

    _putchar('\n');
}
