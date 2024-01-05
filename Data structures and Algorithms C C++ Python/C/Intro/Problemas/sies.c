/*
Print all the maxima’s in an array. (A value is a maximum if the value
before and after its index are smaller than it is or does not exist.)

Hint:
!a) Start traversing array from the end and keep track of the max element.
! b) If we encounter an element > max, print the element and update max.
*/

#include <stdio.h>
#include <math.h>

#define x 30

void populate_array(int arr[], int size); // Popula el arreglo
void maximas(int arr[], int size);        // Encuentra todas las maximas (DERIVADAS)

int main()
{

    int y[x];

    int size = sizeof(y) / sizeof(int);
    populate_array(y, size);
    printf("Las maximas son: \n");

    maximas(y, size);

    return 0;
}

// DEFINICIONES DE LOS PROTOTIPADOS

void populate_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int)(5.0 * cos((double)(i * i) + 0.25) + 5.0);
        printf("%d ", arr[i]);
    }
}

void maximas(int arr[], int size)
{
    if (size >= 2)
    {
        int m = arr[size - 1]; // Ultimo elemento

        for (int i = size - 2; i >= 0; i--) // Iteramos el ultimo al primero
        {
            if (arr[i] >= m) // Encontramos maxima
            {
                m = arr[i];
                if (arr[i - 1] <= m) // Comparamos con el otro elemento de a lado
                {
                    printf("Valor: %d  arr[%d]\n", m, i);
                }
            }
            m = arr[i]; // Asumimos que el elemento sig es maxima
        }
    }
}