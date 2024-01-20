#include <stdio.h>
#include <string.h>
#include <stdint.h>

/*
A union is declared in the same way as a struct but memory is only allocated
for the largest of the union fields.That is, all of the fields of a union share the
same memory. This sounds like a crazy thing to do until you notice that it
gives you a way of working with the same bit pattern with different
interpretations.
*/
union
{
    int a;
    float b;
} test;

/*
For a more realistic example consider the way most graphics hardware stores
a ARGB – Alpha, Red, Green and Blue value in an unsigned 32 bit int. If you
want to access each of these bytes and also treat all four bytes as a single
value then the best way is to define a union:
*/
union pixel
{
    struct
    {
        unsigned char b, g, r, a;
    };
    uint32_t value;
};

/*
For example, we can write the example given in
Chapter 10 concerning reading in four bytes and treating these as a single int
as:
*/
union dualbuffer
{
    char Cbuffer[100];
    int Ibuffer[25];
} buffer;

/*
For example, suppose you have a name record which sometimes has a
telephone number as a string and sometimes as an integer. You could store
this as:
*/
struct
{
    int type;
    union
    {
        char numstring[10];
        int numint;
    } phone;
} person;

int main()
{
    test.b = 3.1416;
    printf("%d\n", test.a);

    /*
        The union declares a four byte int and an eight byte float both sharing the
        same memory locations. The union is eight bytes in total and both the int and
        the float start at the beginning of the memory allocated – there is no padding
        at the start of a struct or a union. When we refer to test.a or test.b we are
        accessing the same area of memory and so test.a accesses the first four bytes
        of the float which we print in the last line
    */

    float pi = 3.1416;
    printf("%d\n", *(int *)&pi);

    // Creamos un pixel
    union pixel pix;
    pix.r = 1;
    pix.g = 255;
    pix.b = 128;
    pix.a = 255;
    printf("pixel.value = %d\n", pix.value);

    // TERCER ejemplo:
    buffer.Cbuffer[0] = 1;
    buffer.Cbuffer[1] = 2;
    buffer.Cbuffer[2] = 3;
    buffer.Cbuffer[3] = 4;
    printf("Ibuffer: %d\n", buffer.Ibuffer[0]);

    // Cuarto ejemplo:
    person.type = 1;
    strcpy(person.phone.numstring, "1234");
    person.type = 0;
    person.phone.numint = 1234;

    return 0;
}