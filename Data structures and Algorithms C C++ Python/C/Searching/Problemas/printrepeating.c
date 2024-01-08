/*
Given an array of n numbers, print the duplicate
elements in the array.
*/

#include <stdio.h>
#include "D:\Progrmacion\Data structures and Algorithms C C++ Python\C\Searching\Random_Array.h"

void misolucion(int arr[], int size);

void libro1(int arr[], int size);
void libro2(int arr[], int size);
void libro3(int arr[], int size);
void libro4(int arr[], int size);

int main()
{
    int N = 10, lim_inf = 0, lim_max = 10;

    int *arr = generar_array_aleatorio(N, lim_inf, lim_max);
    printf("Array aleatorio: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // provamos funcion
    // misolucion(arr, N);

    // libro1(arr, N);
    // libro2(arr, N);
    // libro3(arr, N);
    libro4(arr, N);

    return 0;
}

void misolucion(int arr[], int size)
{
    int registro[size], i;

    for (i = 0; i < size; i++)
    {
        registro[i] = 0; // Ningun repetido
    }

    for (i = 0; i < size; i++)
    {
        if (registro[arr[i]] == 1)
        { // Está ocupado?
            printf("Duplicado el %d\n", arr[i]);
        }
        else
        {
            registro[arr[i]] = 1; // Marcamos como recienemente registrado
        }
    }
}

// Otroas solcuines cond diferentes puntos de vista

/*
First approach: Exhaustive search or Brute force, for each element in array
find if there is some other element with the same value. This is done using
two for loop, first loop to select the element and second loop to find its
duplicate entry.
The Time Complexity is O(n^2) and Space Complexity is O(1)
*/
void libro1(int arr[], int size)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                printf("Duplicado: %d\n", arr[i]);
            }
        }
    }
}

/*
! Second approach:
Sorting, Sort all the elements in the array and after this in a
single scan, we can find the duplicates

Sorting algorithms take O(n.log(n)) time and single scan take O(n) time.
The Time Complexity of an algorithm is O(n.log(n)) and Space Complexity
is O(1)
*/
void intercambiar(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int array[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                // Intercambia los elementos si están en el orden incorrecto
                intercambiar(&array[j], &array[j + 1]);
            }
        }
    }
}

void libro2(int arr[], int size)
{
    int i;
    bubble_sort(arr, size);
    for (i = 1; i < size; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            printf("Se repitio: %d\n", arr[i]);
        }
    }
}

/*
Third approach:
Hash-Table, using Hash-Table, we can keep track of the
elements we have already seen and we can find the duplicates in just one
scan.

Hash-Table insert and find take constant time O(1) so the total Time
Complexity of the algorithm is O(n) time. Space Complexity is also O(n)
void libro3(int arr[], int size)
{
    HashTable h;
    int i;
    for (i = 0; i < size; i++)
    {
        if (findValue(h, arr[i]))
            printf(" %d ", arr[i]);
        else
            addValue(h, arr[i]);
    }
}
*/

/*
!Forth approach:
Counting, this approach is only possible if we know the
range of the input. If we know that, the elements in the array are in the range
0 to n-1. We can reserve and array of length n and when we see an element
we can increase its count. In just one single scan, we know the duplicates. If
we know the range of the elements, then this is the fastest way to find the
duplicates.

Counting approach just uses an array so insert and find take constant time
O(1) so the total Time Complexity of the algorithm is O(n) time. Space
Complexity for creating count array is also O(n)
*/
void libro4(int arr[], int size)
{
    int *count = (int *)calloc(sizeof(int), size);
    int i;
    for (i = 0; i < size; i++)
    {
        if (count[arr[i]] == 1)
            printf("duplicado  %d ", arr[i]);
        else
            count[arr[i]]++;
    }
}