#include <stdio.h>
#include <string.h> // para usar memset
#include <stdlib.h>

/*
*The calloc function
will allocate and clear memory
at the same time. Its prototype follows:

? void *calloc(size_t numElements, size_t elementSize);

todo: To clear memory means its contents are
todo: set to all binary zeros.
*/
int main()
{
    int *pi = calloc(5, sizeof(int));

    // !es lo mismo que hacer las siguiente dos lineas
    /*
    *The memset function
    will fill a block with a value.

    The first argument is a pointer to the buffer to fill.

    The second is the value used to fill the buffer, and

    the last argument is the number of bytes to be set.
    */
    int *pi2 = malloc(5 * sizeof(int));
    memset(pi2, 0, 5 * sizeof(int));

    return 0;
}