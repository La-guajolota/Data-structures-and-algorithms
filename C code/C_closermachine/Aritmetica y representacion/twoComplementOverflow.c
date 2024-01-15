#include <stdio.h>
#include <limits.h>

int main()
{
    signed char var = 127, varMas = var + 1; // negativo de complemento a dos

    /*
        Two’s-complement arithmetic overflows when addition involving two
        positive numbers gives a negative result or two negative numbers give a
        positive result. Notice that you cannot get an overflow if one of the numbers
        is positive and the other negative.
    */
    printf("var=%d  var+1=%d\n", var, varMas);

    // !UINT_MAX es el maximo vlaor que cabe en un unsigned int
    int x = INT_MAX; // Con signo
    if (x + 1 < x)
    {
        printf("OVERFLOW\n");
    }

    return 0;
}