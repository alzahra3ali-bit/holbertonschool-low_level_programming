#include "main.h"
/**
 * the value i is like a counter 
 * a for loop that implement a n time 
 * inside the loop there is array that all its element is (b)
 * the  return statment return the array with the new values
 */
char *_memset(char *s, char b, unsigned int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        s[i] = b;
    }

    return (s);
}
