#include <stdio.h>

void myFunc(int *puntero)
{
    *puntero = 0; // Cambiamos el dato de la direccion de memoria a 0
}

// The array expression passed to the function “decays to a pointer”.
int sum(int array[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total += array[i];
    }

    return total;
}

int main()
{
    int myVar = 8;
    printf("%d\n", myVar);
    myFunc(&myVar);
    printf("%d\n", myVar);

    int array[10] = {1, 2, 3, 4, 5};
    int rslt = sum(array, 10);
    printf("rslt: %d", rslt);

    return 0;
}