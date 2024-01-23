#include <stdio.h>
#include <stdlib.h>

int main()
{

    /*
    * The malloc function
    todo: single argument specifies the number of bytes
    to allocate. If suc‐cessful, it returns a pointer
    to memory allocated from the heap. If it fails, it returns a null pointer
    */

    int *pi = (int *)malloc(sizeof(int)); // Creamos un espacio de memoria
    *pi = 5;                              // Asignamos dato a ese bloque
    printf("*pi: %d\n", *pi);             // Mostramos contenido al que se apunta
    free(pi);                             // liberamos ese espacio de memoria

    // Es buena practica signar dicho puntero NULL
    pi = NULL; // * SIGNIFICA QUE APUNTA A NADA
    printf("pi = %x", pi);

    /*
    * Memory is allocated for a string,
    allowing it to hold up to five characters plus
    the byte for the NUL termination character
    */
    char *pc = (char *)malloc(6);
    for (int i = 0; i < 8; i++) // !If we write past the end of the string, this extra memory will be corrupted.
    {                           // its actual placement and its original content depend on the compiler.
        pc[i] = 0;
        printf(" pc[%d]=%d ", i, *(pc + i));
    }

    return 0;
}