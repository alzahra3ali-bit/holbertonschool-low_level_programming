#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - allocates memory using malloc
 * @b: number of bytes to allocate
 *
 * Return: pointer to allocated memory
 *         if malloc fails, terminates process with status 98
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b); /* حاول حجز الذاكرة */
	if (ptr == NULL) /* لو malloc فشل */
		exit(98);    /* نوقف البرنامج مع الحالة 98 */

	return (ptr);    /* رجع المؤشر للذاكرة */
}
