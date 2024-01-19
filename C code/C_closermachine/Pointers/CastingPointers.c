#include <stdio.h>
#include <stdlib.h>

int main()
{
    void *myPointer; // Puntero sin ningun tipo

    // Este puntero apunta a la dirección de:
    char *ptr_tipado = (char *)malloc(100); // 100 bytes de memoria

    // Son lo mismo en ambas lineas
    ptr_tipado[50] = 'A';
    printf("%c\n", ptr_tipado[50]);
    *(ptr_tipado + 50) = 'B';
    printf("%c\n", *(ptr_tipado + 50));

    /*
        It is usual to express the size of the block of memory to be allocated in terms
        of the size of the proposed elements. That is, you would write:
        to allocate an “array” of 100 char. The same works for any type of element:
        type pointer=malloc(n*sizeof(type))
        and is the pointer equivalent of declaring an array of n elements.
    */
    char *ptr = (char *)malloc(100 * sizeof(char));

    /*
        The real advantage of allocating memory on the heap is that it is dynamic. For
        example, if you want to create an array that can change its size you need to
        write something like
    */
    char *myarray = (char *)malloc(100);
    for (int i = 0; i < 100; i++)
    {
        myarray[i] = i;
    }

    // Crecemos el tamaño mayor de 100 bytes
    myarray = (char *)realloc(myarray, 200);
    for (int i = 100; i < 200; i++)
    {
        myarray[i] = i;
    }

    // Mostramos el contenido del bloque de memoria
    for (int i = 0; i < 200; i++)
    {
        printf("[%d]= %d\n", i, myarray[i]);
    }

    return 0;
}