#include <stdio.h>
#define Nelementos 20

int main()
{
    int *pointer;
    int myVar = 445;
    int myArray[Nelementos] = {1, 2, 3};

    int size = sizeof(int) * Nelementos;
    printf("size: %d bytes\n", size);

    pointer = myArray;
    printf("%d\n", pointer[0]); // EL puntero ahora puede fungir como myArray

    // La direcion de tal Ith elemento del array
    /*
        This calculation is so standard for pointers that C makes it the default and:
        myPointer+I;
        is taken to mean not +I but +sizeof(int)*I.
    */
    for (int i = 0; i < Nelementos; i++)
    {
        printf("%p ->> %d\n", pointer + sizeof(int) * i, *(pointer + i));
    }

    return 0;
}