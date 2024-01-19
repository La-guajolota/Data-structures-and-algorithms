#include <stdio.h>
#include <string.h> //! viene memcpy()

/*
For example, suppose a machine architecture demands that an int and a byte
have to be aligned on a 16-bit word – that is their addresses have to be a
multiple of 16. Now consider what happens if you use type punning to access
the second byte of an int. In this case the address of the byte would not be a
multiple of 16 and your program might crash due to an invalid address. As far
as I know no modern machine architecture is this inflexible, but it could
happen and similar problems arise with more complex data structures.
This again highlights the conflict between the programmers who regard C as
always targeting a specific architecture, in which case type punning is fine, or
as a machine-independent language, in which case type punning is not fine at
all.
Strict aliasing demands that if pointers reference the same memory then their
types are compatible. Essentially this means that the types have to be
effectively the same and so it rules out casting being used for type punning.
*/

int main()
{
    float pi = 3.1416;
    printf("sizeof(float):%d\n", sizeof(float));

    /*
        copies the bits in the first four bytes of the float into the int and achieves the
        type punning without violating strict alias rules
    */
    int tempint;
    memcpy(&tempint, &pi, sizeof(tempint));

    printf("%d\n", tempint);
    return 0;
}