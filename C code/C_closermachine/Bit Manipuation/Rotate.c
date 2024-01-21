#include <stdio.h>

/*
You can see the general principle. If you want a right rotate of n bits of a 32-
bit int then use:

!data= data>>n | data<<32-n;

todo: Similarly, if you want a left rotate of n bits of a 32-bit value then use:

!data= data<<n | data>>32-n;

Notice that n cannot be negative or equal to 32, which would trigger
undefined behavior. Also notice that data has to be unsigned so as to use
logical shifts.
*/

int main()
{
    // Right rotate
    unsigned int data = 0xf;
    printf("%x\n", data);

    data = data >> 1 | data << 31;
    printf("%x\n", data);

    data = data >> (unsigned)1 | data << (unsigned)31;
    printf("%x\n", data);

    return 0;
}