#include <stdio.h>

int main()
{
    int myVar = 123;
    int *mypointer = &myVar;

    printf("Dato: %d\n", *mypointer);
    printf("Direccion de memoria del dato: %p\n", mypointer);
    printf("Direccion del puntero: %p\n", &mypointer);

    return 0;
}