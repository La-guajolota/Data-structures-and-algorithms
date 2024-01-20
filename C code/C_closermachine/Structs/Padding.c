#include <stdio.h>
#include <string.h>

struct test // Padding al final
{
    int i;
    char c;
} test;

struct test2 // Padding al principio
{
    char c;
    int i;
} test2;

int main()
{
    /*
        will print 4, 1 and 8 on a 64-bit Intel processor based machine. So although
        the struct should have taken just five bytes it actually takes eight to pad it
        out to a full 64 bit word.
    */
    printf("sizeof(int) %d \n", sizeof(int));
    printf("sizeof(char) %d \n", sizeof(char));
    printf("sizeof(struct test) %d \n\n", sizeof(struct test));

    /*
        Notice that the padding is added at the end or in between fields. The C
        standard ensures that no padding is added to the start of a struct and this
        means you can rely on the fact that the address of the struct is the address of
        the first field.
    */
    printf("Address de test: %x \n", &test);
    printf("Address de i: %x \n", &test.i);
    printf("Adress de c: %x \n\n", &test.c);
    /*
        to the end of the previous example you will see that &test and &test.i are at
        the same address and &test.c is likely to be sizeof(int) further on. This
        means that the
        !padding is at the end of the struct.
    */

    printf("Address de test: %x \n", &test2);
    printf("Adress de c: %x \n", &test2.c);
    printf("Address de i: %x \n", &test2.i);

    /*
        give you a strut with the same size but the addresses are now such that
        test.c is at the start of the struct but test.i is likely to be four bytes from the
        start of the struct. That is, there are three bytes of padding between test.c
        and test.i. It is as if the struct was declared as:

        struct test {
            char c;
            char padding[3];
            int i;
        } test;
    */

    /*
         Notice that what padding actually occurs depends on the machine
         architecture and the compiler options.

         !If you want to pack a struct to take the smallest amount of memory then a
         !rule of thumb is to allocate fields in the order of size starting with the largest.

         In general optimizing the packing of a struct isn’t necessary unless you are
         using a great many of them – then it can be essential. Notice that such
         optimizations are always machine dependent.
    */
    return 0;
}