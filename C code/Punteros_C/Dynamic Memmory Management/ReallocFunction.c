#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char *string1;
    char *string2;
    string1 = (char *)malloc(16 * sizeof(char));
    strcpy(string1, "0123456789AB"); // colocamos 16 bytes pero usamos 13

    string2 = realloc(string1, 8); // Reducimos el tamaño de memoria

    /*
    The heap manager was able to reuse the original block, and it did not modify its contents.
    However, the program continued to use more than the eight bytes requested. That is,
    we did not change the string to fit into the eight-byte block. In this example, we should
    have adjusted the length of the string so that it fits into the eight reallocated bytes. The
    simplest way of doing this is to assign a NUL character to address 507. Using more space
    than allocated is not a good practice and should be avoided
    */
    // Observamos resultados:
    printf("string1 valor: %p [%s]\n", string1, string1);
    printf("string2 valor: %p [%s]\n", string2, string2);

    //! Recolocamos más bloques de memoria de los necesarios
    char *string3;
    string3 = realloc(string1, 64);

    printf("string1 valor: %p [%s]\n", string1, string1);
    printf("string3 valor: %p [%s]\n", string3, string3);

    return 0;
}