#include <stdio.h>
#include <stdint.h>

/*
A problem that often arises in bit manipulation is endianism. When you
design a computer there is a choice to be made. If parts of a word, say each
byte, has a separate address do you store the low-order bits at low addresses,
little endian, or at high addresses, big endian?

For example, consider a 2-byte int and alias it to a 2-byte array.

The union aliases myint and mychar. We then set myint so that all its loworder first 8 bits are 1. If the machine is little endian, as in the case of x86 and
ARM, then the low-order bits are stored in mychar[0]. If the machine is big
endian, e.g. Atmel AVR32, the low-order bits are stored in mychar[1].
*/
union endian
{
    short unsigned int myint;
    unsigned char mychar[2];
} test;

/*
For example, creating a union to access the separate ARGB – Alpha, Red,
Green and Blue values in an unsigned 32 bit int given in Chapter 10 is an
example of something that changes according to endianism. As A is the high
order byte and B the low order you might expect the union to be:

todos: Ver la union de Pixel

However the x86 and ARM are little endian. So the ARGB bytes are stored in
the opposite order with a at the lowest address in the union:

union Pixel{
     struct {unsigned char b,g,r,a;};
     uint32_t value;
};
*/
union Pixel
{
    struct
    {
        unsigned char a, r, g, b;
    };
    uint32_t value;
};

int main()
{
    printf("sizeof short int: %x | sizeof char: %x\n", sizeof(short int), sizeof(char));

    test.myint = 0x00ff;
    printf("%x\n", test.mychar[0]);
    printf("%x\n", test.mychar[1]);

    return 0;
}