#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    Since the malloc function may return a NULL
    value if it is unable to allocate memory,
    todo: it is a good practice
    to check for a NULL value before
    using the pointer as follows:
    */

    int *pi = (int *)malloc(sizeof(int));
    if (pi != NULL)
    {
        // El puntero debería estar bueno
    }
    else
    {
        // Puntero malo
    }

    return 0;
}