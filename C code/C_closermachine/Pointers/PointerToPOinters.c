#include <stdio.h>
#include <stdlib.h>

int main()
{
    int entero = 1;
    int **ptr2;
    int *ptr1 = &entero;

    ptr2 = &ptr1; // Puntero a un puntero de tipo int

    int arr2[4][4] = {{0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}, {0, 1, 2, 3}};
    int *columna = &arr2; // ?Apnta a la primera columna

    // Otra manera de crear un array 2d
    int **arr1 = malloc(10 * sizeof(int *)); // Arreglo de punteros
    for (int i = 0; i < 10; i++)             // Colocamos espacios de memoria cada columna
    {
        *(arr1 + i) = malloc(10 * sizeof(int));
        // arr1[i] = malloc(10 * sizeof(int));
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            arr1[i][j] = i * j;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            printf("%d\n", arr1[i][j]);
        }
    }
    /*
        Notice that building the array in this way gives us some flexibility. For
        example, you don’t have to make each column the same size. This idea is
        more useful when you are creating a one-dimensional array of strings, say,
        which vary in length.
    */

    return 0;
}