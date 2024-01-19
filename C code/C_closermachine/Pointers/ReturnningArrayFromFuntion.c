#include <stdio.h>
#include <stdlib.h>

int *zero()
{
    int arr[10]; //! ES UNA VARIABLE LOCAL A LA FUNCION
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    /*
    The calling program doesn’t get a
    pointer to an array of ints, but a pointer into a block of memory that was an
    array of ints before it was freed.
    */
    return arr;
}

int *zero2()
{
    int *arr = (int *)malloc(10 * sizeof(int));
    for (int i = 0; i < 10; i++)
    {
        arr[i] = 0;
    }
    return arr;
}

int main()
{
    int *arr1 = zero2();
    printf("direccion de arr1: %p\n", arr1);

    int *arr2 = zero2(); // Segundo arreglo con ceros???
    printf("direccion de arr2: %p\n", arr2);

    return 0;
}