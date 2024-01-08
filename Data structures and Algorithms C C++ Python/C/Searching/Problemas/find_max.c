/*
### Find max, appearing element in an array ###

Given an array of n numbers, find the element, which appears maximum
number of times.
*/
#include <stdio.h>
#include <stdlib.h>
#include "D:\Progrmacion\Data structures and Algorithms C C++ Python\C\Searching\Random_Array.h"

int libro1(int arr[], int size);
int libro2(int arr[], int size);
int libro3(int arr[], int size, int lim_max);

int main()
{
    int N = 20, lim_inf = 0, lim_max = 10, max;

    int *arr = generar_array_aleatorio(N, lim_inf, lim_max);
    printf("Array aleatorio: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // provamos funciones

    // max = libro1(arr, N);
    // max = libro2(arr, N);
    max = libro3(arr, N, lim_max);

    printf("\n Se repite mas veces el numero: %d", max);

    return 0;
}

/*
! First approach:
Exhaustive search or Brute force, for each element in array
find how many times this particular value appears in array. Keep track of the
maxCount and when some element count is greater than maxCount then
update the maxCount. This is done using two for loop, first loop to select the
element and second loop to count the occurrence of that element.
The Time Complexity is O(n^2), and Space Complexity is O(1)
*/
int libro1(int arr[], int size)
{
    int i, j;
    int max = arr[0], count = 1, maxcount = 1;

    for (i = 0; i < size; i++)
    {
        count = 1;
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++; // Contamos las veces que se repite un valor
            }
        }
        if (count > maxcount)
        {
            max = arr[i];
            maxcount = count; // Cantidad de repeticiones de un numero
        }
    }
    return max;
}

/*
! Second approach:
Sorting, Sort all the elements in the array and after this in a
single scan, we can find the counts.
Sorting algorithms take O(n.log(n)) time
and single scan take O(n) time. The Time Complexity of an
algorithm is O(n.log(n)) and Space Complexity is O(1)
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

int libro2(int arr[], int size)
{
    int max = arr[0], maxcount = 1, curr = arr[0], currcount = 1;
    int i;
    bubble_sort(arr, size);

    for (i = 0; i < size; i++)
    {
        if (arr[i] == arr[i - 1])
        {
            currcount++;
        }
        else
        {
            currcount = 1; // Solo hay uno del valor arr[i-1]
            curr = arr[i];
        }

        if (currcount > maxcount) // le coa el lugar del max?
        {
            maxcount = currcount;
            max = curr; // valor mayoritario
        }
    }
    return max;
}

/*
!!! Third approach:
Counting, This approach is only possible if we know the
range of the input. If we know that, the elements in the array are
in the range 0 to n-1. We can reserve and array of length n and
when we see an element we can increase its count. In just one
single scan, we know the duplicates. If we know the range of the
elements, then this is the fastest way to find the max count.
Counting approach just uses array so to increase count take
constant time O(1) so the total Time Complexity of the algorithm
is O(n) time. Space Complexity for creating count array is also O(n)
*/

int libro3(int arr[], int size, int lim_max)
{
    int max = arr[0], maxcount = 1;
    int *cout = (int *)calloc(sizeof(int), lim_max);
    int i;

    for (i = 0; i < size; i++)
    {
        cout[arr[i]]++;
        if (cout[arr[i]] > maxcount)
        {
            maxcount = cout[arr[i]];
            max = arr[i];
        }
    }

    return max;
}