#include <stdio.h>
#include <stdlib.h>

/*
To summarize:
 create a mask that has 1 at the position of each bit you want to
change.
 OR the mask with the flag to set just those bits.
 AND the NOT of the mask to unset just those bits.
 XOR the mask to flip just those bits.
Bits in the mask that are 0 are unaffected by any of the operations.
*/

int main()
{
    char *prt;
    int mask = strtol("11", &prt, 2);

    int flag = 0xfff0;
    int result = flag | mask; // Seteamos unos
    printf("%x\n", result);

    flag = 0xffff;
    result = flag & ~mask; // Seteamos ceros
    printf("%x\n", result);

    flag = 0xffff;
    result = flag ^ mask; // Flipeo
    printf("%x\n", result);

    return 0;
}