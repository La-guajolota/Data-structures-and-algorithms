#include <stdio.h>

int *allocateArray(int *arr, int size, int value)
{
    /*
    todo: When a pointer is passed to a function, it
    todo: is always good practice to verify it is not
    todo: null before using it
    */
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = value;
        }
    }
    return arr;
}

int main()
{
    int *vector = (int *)malloc(5 * sizeof(int));
    allocateArray(vector, 5, 45);
    /*
    If the pointer is NULL, then no action is performed and the program will execute
    without terminating abnormally.
    */
    return 0;
}