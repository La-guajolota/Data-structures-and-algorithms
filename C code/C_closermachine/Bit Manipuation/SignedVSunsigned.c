#include "stdio.h"

/*
Now we come to a subtle and troublesome point. Bitwise operators are only
uniquely defined for unsigned values. The reason is that unsigned values
have an unambiguous representation in binary and hence the operations are
well-defined in terms of the values the bit patterns represent.
*/

int main()
{
    unsigned int values = 5;
    values | 0x2;

    printf("%x\n", values);

    signed int value2 = -5;
    value2 |= 0x4;

    printf("%x\n", value2);

    return 0;
}