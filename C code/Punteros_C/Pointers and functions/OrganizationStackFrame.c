#include <stdio.h>
#include <stdlib.h>

/*
A stack frame consists of several elements, including:

!Return address
    The address in the program where the function is to return upon completion
!Storage for local data
    Memory allocated for local variables
!Storage for parameters
    Memory allocated for the function’s parameters
!Stack and base pointers
    Pointers used by the runtime system to manage the stack
*/

float average(int *arr, int size)
{
    int sum = 0;
    printf("arr: %p\n", &arr);
    printf("size: %p\n", &size);
    printf("sum: %p\n", &sum);

    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    return (sum * 1.0f) / size;
}

int main()
{
    int numeros[] = {1, 13, 44, 21, 13, 15};
    float avrg = average(numeros, 6);

    printf("aveg: %f", avrg);

    return 0;
}