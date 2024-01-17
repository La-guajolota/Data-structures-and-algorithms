#include <stdio.h>

int main()
{
    int x[10] = {70, 71, 82, 31, 84, 65, 67, 71, 87, 19};
    int *y = x; // Puntero *y a primer elemento de x[]

    for (int i = 0; i < 10; i++)
    {
        printf("Dire: %x  Cont; %d\n", y + i, *(y + i));
    }

    return 0;
}