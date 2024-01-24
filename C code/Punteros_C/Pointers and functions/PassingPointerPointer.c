#include <stdio.h>
#include <stdlib.h>

/*
When a pointer is passed to a function, it is passed by value. If we want to modify the
original pointer and not the copy of the pointer, we need to pass it as a pointer to a
pointer
*/
void allocateArray(int **arr, int size, int value)
{
    *arr = (int *)malloc(size * sizeof(int));
    if (*arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            *(*arr + i) = value;
        }
    }
}

/*
The following version of the function illustrates why passing a simple pointer will not
work:
*/
void allocateArray2(int *arr, int size, int value)
{
    arr = (int *)malloc(size * sizeof(int));
    if (arr != NULL)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = value;
        }
    }
}

int main()
{
    int *vector = NULL;
    allocateArray(&vector, 5, 45);

    // ! La segundo no va a jalara
    /*
    int *vector2 = NULL;
    allocateArray2(&vector2, 5, 10);
    printf("%p\n", vector2);
    */

    return 0;
}