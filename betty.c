#include "shell.h"
#include <stdlib.h>

/**
 * check_malloc - a function that allocates memory using malloc
 *
 * @a: input int
 * Return: void
 */

{
int main(void)
}
void *check_malloc(unsigned int a)
{
        void *ptr;

        ptr = malloc(a);
        if (ptr == NULL)
        {
        exit(98);
        }

        return (ptr);
}
