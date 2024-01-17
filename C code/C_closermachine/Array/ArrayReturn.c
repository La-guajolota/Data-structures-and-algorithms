#include <stdio.h>

int *zero()
{
    static int myArray[10]; // This ensures that the array exists after the function has completed and forces it to be non-local:
    for (int i = 0; i < 10; i++)
    {
        myArray[i] = 0;
    }
    return myArray;
}

int main()
{
    int *rslt = zero();

    for (int i = 0; i < 10; i++)
    {
        printf("array[%d]=%d\n", i, *(rslt + 1));
    }

    /*
    With this change the function works. However, it doesn’t matter how many
    times you call the function, it will return the same myArray. That is, it doesn’t
    manufacture a new array each time it is called, there is just the one instance –
    but at least it doesn’t crash
    */

    return 0;
}