#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int *pi = (int *)malloc(sizeof(int));
    *pi = 5;
    printf("*pi: %d\n", *pi);
    free(pi);

    //! El bloque que apuntaba pi ya no es utilizable practicamente !
    ///// *pi = 10;

    pi = NULL; // Especificamos que apunta "nada" por el momentos

    return 0;
}

/*
Here the try block encloses any statements that might cause an exception to be thrown
at runtime. The finally block will be executed regardless of whether an exception is
thrown. The free function is guaranteed to be executed.
*/
void exceptionExample()
{
    int *pi = NULL;
    __try
    {
        pi = (int *)malloc(sizeof(int));
        *pi = 5;
        printf("%d\n", *pi);
    }
    __finally
    {
        free(pi);
    }
}