/*
Given an array of n elements. Find the majority element, which
appears more than n/2 times. Return 0 in case there is
no majority element.

! Moore’s Voting Algorithm
*/

#include <stdio.h>
#include "D:\Progrmacion\Data structures and Algorithms C C++ Python\C\Searching\Random_Array.h"

int getmayor1(int arr[], int size);
int getmayor2(int arr[], int size);
int moore_voting(int arr[], int size);

int main()
{
    int N = 10, lim_inf = 0, lim_max = 3, max;

    int *arr = generar_array_aleatorio(N, lim_inf, lim_max);
    printf("Array aleatorio: ");
    for (int i = 0; i < N; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Ejecutamos las funciones

    // max = getmayor1(arr, N);
    // max = getmayor2(arr, N);
    max = moore_voting(arr, N);

    printf("\n Return: %d\n", max);

    return 0;
}

/*
! First approach:
Exhaustive search or Brute force, for each element in array
find how many times this particular value appears in array. Keep track of the
maxCount and when some element count is greater than maxCount then
update the maxCount. This is done using two for loop, first loop to select the
element and second loop to count the occurrence of that element.

Once we have the final, maxCount we can see if it is greater than n/2, if it is
greater than we have a majority if not we do not have any majority.

The Time Complexity is O(n**2) + O(1) = O(n**2) and Space Complexity is O(1)
*/
int getmayor1(int arr[], int size)
{
    int i, j;
    int max = 0, count = 0, maxcount = 0;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
            if (count > maxcount)
            {
                max = arr[i];
                maxcount = count;
            }
        }
    }
    // Despues de revisar todos los elementos
    if (maxcount > (size / 2))
    {
        return max;
    }
    else
    {
        printf(" No existe!");
        return 0;
    }
}

/*
! Second approach:
Sorting, Sort all the elements in the array. If there is a
majority than the middle element at the index n/2 must be the majority
number. So just single scan can be used to find its count and see if the
majority is there or not.

Sorting algorithms take O(n.logn) time and single scan take O(n) time.
The Time Complexity of an algorithm is O(n.log n) and Space Complexity is O(1)
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

int getmayor2(int arr[], int size)
{
    int majIndex = size / 2, count = 1;
    int i;
    int candidate;

    bubble_sort(arr, size);

    candidate = arr[majIndex];
    count = 0;

    for (i = 0; i < size; i++)
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    if (count > size / 2)
    {
        return arr[majIndex];
    }
    else
    {
        printf(" No existe!");
        return 0;
    }
}

/*
! Third approach:
? Moore’s Voting Algorithm
! Es el mejor método que el anterior asta despues de 10 elementos de inputs
This is a cancelation approach (Moore’s Voting Algorithm),
if all the elements stand against the majority and each element is cancelled
with one element of majority if there is majority then majority prevails.

· Set the first element of the array as majority candidate and initialize the
count to be 1.

· Start scanning the array.

o If we get some element whose value same as a majority candidate,
then we increase the count.

o If we get an element whose value is different from the majority
candidate, then we decrement the count.

o If count become 0, that means we have a new majority candidate.
Make the current candidate as majority candidate and reset count to 1

o At the end, we will have the only probable majority candidate.
· Now scan through the array once again to see if that candidate we found
above have appeared more than n/2 times.

Counting approach just scans throw array two times. The Time Complexity
of the algorithm is O(n) time. Space Complexity for creating count array is
also O(1)

*/
int moore_voting(int arr[], int size)
{
    int majIndex = 0, count = 1;
    int i;
    int candidate;

    for (i = 1; i < size; i++) // Descartamos candidatos
    {
        if (arr[majIndex] == arr[i])
        {
            count++;
        }
        else
        {
            count--;
        }

        if (count == 0)
        {
            majIndex = i;
            count = 1;
        }
    }

    candidate = arr[majIndex]; // Ultimo posible candidato
    count = 0;

    for (i = 0; i < size; i++) // Contamos cuantas apararece
    {
        if (arr[i] == candidate)
        {
            count++;
        }
    }

    if (count > size / 2) // Pasa la prueba finañl?
    {
        return arr[majIndex];
    }
    else
    {
        printf("\nNo existe\n");
        return 0;
    }
}