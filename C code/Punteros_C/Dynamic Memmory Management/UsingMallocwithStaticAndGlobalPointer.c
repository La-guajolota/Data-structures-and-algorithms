#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*
    You cannot use a function call when initializing a static or global variable. In the fol‐
    lowing code sequence, we declare a static variable and then attempt to initialize it using
    malloc:

    From the compiler standpoint, there is a difference between using the
    initialization operator, =, and using the assignment operator, =
    */
    ////static int *pi = malloc(sizeof(int));
    static int *pi;
    pi = malloc(sizeof(int));

    return 0;
}