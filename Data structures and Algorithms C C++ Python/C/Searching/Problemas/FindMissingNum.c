/*
Given an array of n-1 elements, which are in the range of 1 to n. There are no
duplicates in the array. One of the integer is missing. Find the missing
element.
*/
#include <stdio.h>

int findmisisngnumer1(int arr[], int size);
int findmisisngnumee7(int arr[], int size, int range);

int main()
{
    // Quita un elemento del arreglo
    int arr[] = {1, 2, 3, 4, 5, 6, 8, 9, 10}, size, rslt;

    size = sizeof(arr) / sizeof(int);
    printf("Son %d elementos\n", size);

    // rslt = findmisisngnumer1(arr, size);
    rslt = findmisisngnumee7(arr, size, size + 1);

    printf("Resulado: %d", rslt);

    return 0;
}

/*
First approach:
Exhaustive search or Brute force, for each value in the range
1 to n, find if there is some element in array which have the same value. This
is done using two for loop, first loop to select value in the range 1 to n and
the second loop to find if this element is in the array or not.
The Time Complexity is O(n**2) and Space Complexity is O(1)
*/
int findmisisngnumer1(int arr[], int size)
{
    int i, j, found = 0;
    for (i = 1; i <= size; i++)
    {
        found = 0;
        for (j = 0; j < size; j++)
        {
            if (arr[j] == i)
            {
                found = 1;
                break;
            }
        }
        if (found == 0)
        {
            return i;
        }
    }
}

/*
!Second approach:
Sorting, Sort all the elements in the array and after this in a
single scan, we can find the duplicates.
Sorting algorithms take O(n.log n) time and single scan take O(n) time.
The Time Complexity of an algorithm is O(n.log n) and Space Complexity is
O(1)

!Third approach:
Hash-Table, using Hash-Table, we can keep track of the
elements we have already seen and we can find the missing element in just
one scan.
Hash-Table insert and find take constant time O(1) so the total Time
Complexity of the algorithm is O(n) time. Space Complexity is also O(n)

!Forth approach:
Counting, we know the range of the input so counting will
work. As we know that, the elements in the array are in the range 0 to n-1.
We can reserve and array of length n and when we see an element we can
increase its count. In just one single scan, we know the missing element.
Counting approach just uses an array so insert and find take constant time
O(1) so the total Time Complexity of the algorithm is O(n) time. Space
Complexity for creating count array is also O(n)

!Fifth approach:
You are allowed to modify the given input array. Modify the
given input array in such a way that in the next scan you can find the missing
element.
When you scan through the array. When at index “index”, the value stored in
the array will be arr[index] so add the number “n + 1” to arr[ arr[ index]].
Always read the value from the array using a reminder operator “%”. When
you scan the array for the first time and modified all the values, then one
single scan you can see if there is some value in the array which is smaller
than “n+1” that index is the missing number.
In this approach, the array is scanned two times and the Time Complexity of
this algorithm is O(n). Space Complexity is O(1)

!Sixth approach:
Summation formula to find the sum of n numbers from 1 to
n. Subtract the values stored in the array and you will have your missing
number.
The Time Complexity of this algorithm is O(n). Space Complexity is O(1)
*/

/*
!!!!!!!!!!!!!!!!!!!!
!Seventh approach:
!!!!!!!!!!!!!!!!!!!!
XOR approach to find the sum of n numbers from 1 to n.
XOR the values stored in the array and you will have your missing number.
The Time Complexity of this algorithm is O(n). Space Complexity is O(1).

Note: Same problem can be asked in many forms (sometimes you have to do
the xor of the range sometime you do not):
1. There are numbers in the range of 1-n out of which all appears single time
but one that appear two times.
2. All the elements in the range 1-n are appearing 16 times and one element
appear 17 times. Find the element that appears 17 times.
*/

int findmisisngnumee7(int arr[], int size, int range)
{
    int i;
    int xorSum = 0;
    // aplicamos el xor a todos los numeros desde el 1 al range
    for (i = 1; i <= range; i++)
    {
        xorSum ^= i;
    }
    // xor ahora con los elementos del array
    for (i = 0; i < size; i++)
    {
        xorSum ^= arr[i];
    }
    return xorSum;
}