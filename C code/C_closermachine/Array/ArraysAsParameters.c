#include <stdio.h>

int sum(int myArray[], int n)
{
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        total += myArray[i];
    }
    return total;
}

int main()
{

    int array[1000] = {1, 2, 3};
    int total = sum(array, 1000);

    printf("%d", total);

    return 0;
}