/*
Find the duplicate elements in an array of size n where each element is in
the range 0 to n-1.

Hint:
//!Approach 1:

Compare each element with all the elements of the array (using two loops)
//O(n2) solution

//?Approach 2:

Maintain a Hash-Table. Set the hash value to 1 if we
encounter the element for the first time. When we same value again we
can see that the hash value is already 1 so we can print that
value. O(n) solution, but additional space is required.

*Approach 3:

We will exploit the constraint "every element is in the range
0 to n-1".We can take an array arr[] of size n and set all the elements to 0.
Whenever we get a value say val1. We will increment the value at
arr[var1] index by 1. In the end, we can traverse the array arr and print the
repeated values. Additional Space Complexity will be O(n) which will be
less than Hash-Table approach.
*/

#include <stdio.h>
#include <math.h>

#define x 10

void populate_array(int arr[], int size); // Popula el arreglo
void findDuplicate(int arr[], int size);

int main()
{

    int y[x];

    int size = sizeof(y) / sizeof(int);
    populate_array(y, size); // Numeros populados < 10
    printf(" \n Approach3: \n");

    findDuplicate(y, size);

    return 0;
}

void populate_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = (int)(5.0 * cos((double)(i) + 0.05) + 5.0);
        printf("%d ", arr[i]);
    }
}

void findDuplicate(int arr[], int size)
{
    int empty[10];
    for (int i = 0; i < 10; i++)
    {
        empty[i] = 0;
    }

    for (int i = 0; i < size; i++)
    {
        if (0 == empty[arr[i]])
        {
            empty[arr[i]] = 1; // marcamos ocupado
        }
        else
        {
            printf("Esta repetido el valor: %d\n", arr[i]);
        }
    }
}
