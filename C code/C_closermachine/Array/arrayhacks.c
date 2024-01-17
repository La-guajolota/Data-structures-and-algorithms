#include <stdio.h>
#define max 10

int main()
{
    int i;

    int myarray1[max] = {0}; // inicializa a todos con 0
    for (i = 0; i < max; i++)
    {
        printf("myarray1[%d]= %d\n", i, myarray1[i]);
    }

    printf("-------------------------------------\n");

    int myarray2[600] = {[0] = 0, 1, 2, [10] = 10, 11, 12, 13, [500] = 500, 501};
    for (i = 0; i < 600; i++)
    {
        printf("myarray2[%d]= %d\n", i, myarray2[i]);
    }

    return 0;
}