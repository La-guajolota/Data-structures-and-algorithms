#include <stdio.h>
#include <stdlib.h>

int sumHash(char bytes[4]);

int main()
{
    /*
        For example, suppose you want to use the block of memory to store either
        chars or ints, then all you have to do is create two appropriate pointers

        !Now you have two pointers that point to the same block of memory, but one
        !treats it as an array of char and the other an array of int.
    */
    char *ptrCHAR = (char *)malloc(100);
    int *ptrINT = (int *)ptrCHAR;

    /*
    For example, suppose a device, stream or other source of data sends you an
    integer value as four separate bytes. Then you could put the data together
    using something like:
    */
    char *taskchar = (char *)malloc(100);
    taskchar[0] = 1;
    taskchar[1] = 2;
    taskchar[2] = 3;
    taskchar[3] = 4;

    int *taskint = (int *)taskchar;
    printf("int: %d/%p  char: %d/%p\n", taskint[0], taskint, taskchar[0], taskchar);
    printf("sizeof(int)= %d sizeof(char)= %d\n", sizeof(int), sizeof(char));

    int var;                   // 4 bytes
    char *ptr2 = (char *)&var; // ptr2 apunta a esos 4 bytes como chars (segmenta en un lugar por bytes)
    ptr2[0] = 1;
    ptr2[1] = 2;
    ptr2[2] = 3;
    ptr2[3] = 4;

    printf("%d \n", var);

    // !De la funcion
    int seed = 67305985;
    int rslt = sumHash((char *)&seed);
    printf("result del hash: %d\n", rslt);

    return 0;
}

// ! GUACALA
int sumHash(char bytes[4])
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += bytes[i];
    }
    return sum;
}