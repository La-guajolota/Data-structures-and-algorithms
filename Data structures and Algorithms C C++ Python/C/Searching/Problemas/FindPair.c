/*
Given an array of n numbers, find two elements such
that their sum is equal to “value”
*/
#include <stdio.h>
#include "D:\Progrmacion\Data structures and Algorithms C C++ Python\C\Searching\Random_Array.h"

int findpair1(int *arr, int size, int value);
int findpair2(int *arr, int size, int value);

int main()
{
    // Modificables
    int size = 50, value = 7;

    int *array_aleatorio = generar_array_aleatorio(size, -100, 100);

    // Métodos propuestos
    // int rslt = findpair1(array_aleatorio, size, 43);
    int rslt = findpair2(array_aleatorio, size, value);

    printf("rslt=%d", rslt);

    return 0;
}

/*
!First approach:
Exhaustive search or Brute force, for each element in array
find if there is some other element, which sum up to the desired
value. This is done using two for loop, first loop to select the
element and second loop to find another element.
The Time Complexity is O(n**2) and Space Complexity is O(1)
*/
int findpair1(int *arr, int size, int value)
{
    int i, j;
    for (i = 0; i < size; i++)
    {
        for (j = i + 1; i < size; i++)
        {
            if ((arr[i] + arr[j]) == value)
            {
                printf("El par es %d + %d\n", arr[i], arr[j]);
                return 1;
            }
        }
        return 0;
    }
}

/*
!Second approach:
Sorting, Steps are as follows:
1. Sort all the elements in the array.
2. Take two variable first and second. Variable first= 0 and second = size -1
3. Compute sum = arr[first]+arr[second]
4. If the sum is equal to the desired value, then we have the solution
5. If the sum is less than the desired value, then we will increase first
6. If the sum is greater than the desired value, then we will decrease the second
7. We repeat the above process till we get the desired pair or we get first >= second (don’t have a pair)

Sorting algorithms take O(n.log n) time and single scan take O(n) time.
The Time Complexity of an algorithm is O(n.log n) and Space Complexity is
O(1)
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

int findpair2(int *arr, int size, int value)
{
    int first = 0, second = size - 1;
    int curr;
    bubble_sort(arr, size);

    while (first < second)
    {
        curr = arr[first] + arr[second];
        if (curr == value)
        {
            printf("El par es %d + %d\n", arr[first], arr[second]);
            return 1;
        }
        else if (curr < value)
        {
            first++;
        }
        else // curr > value
        {
            second--;
        }
    }
    return 0;
}

/*
! Third approach:
Hash-Table, using Hash-Table, we can keep track of the
elements we have already seen and we can find the pair in just one scan.

1. For each element, insert the value in Hashtable. Let say current value is
arr[index]
2. If the value - arr[index] is already in a Hashtable.
3. If value - arr[index] is in the Hashtable then we have the desired pair.
4. Else, proceed to the next entry in the array.

Hash-Table insert and find take constant time O(1) so the total Time
Complexity of the algorithm is O(n) time. Space Complexity is also O(n)
*/

/*
! Forth approach:
Counting, This approach is only possible if we know the
range of the input. If we know that, the elements in the array are in the range
0 to n-1. We can reserve and array of length n and when we see an element
we can increase its count. In place of the Hashtable in the above approach, we
will use this array and will find out the pair.

Counting approach just uses an array so insert and find take constant time
O(1) so the total Time Complexity of the algorithm is O(n) time. Space
Complexity for creating count array is also O(n)
*/