#include <stdio.h>

/*
Structs have one final feature – bit fields. A bit field is a way of breaking
down the storage into even smaller units than bytes. You can define a bit field
within a struct by following the field definition by a colon and the number
of bits.
*/
/*
In general no padding is used in a bit field but if you allocate more bits than
an int can represent, a second int is used. If you want to force a new
allocation so that a bit field is aligned to an address boundary you can
include an unnamed bit field of size zero
*/
struct Bits
{
    unsigned char byte : 8;
    int : 0;
    int bit1 : 1; // 1 bits
    int bit2 : 1;
} bits;

/*
!Notice that you cannot have a pointer to a bit field, but you can have a
!pointer to the struct that has bit fields. This is often useful when you want to
!map a bit field to a hardware port or register.

For example, suppose there is a hardware register at 0x01000 and its first four
bits control the brightness of LED1 and the next four control LED2. You could
interface with it using a bit field:
*/
struct Port
{
    int led1 : 4;
    int led2 : 4;
} portt;

int main()
{
    bits.bit1 = 1;
    bits.bit2 = 1;
    bits.byte = 255;
    printf("bits: %d\n", bits);
    printf("bits.bytes: %d\n", bits.byte);

    // Port *port=(port*) 0x01000;
    struct Port *port = &portt;
    port->led1 = 3;
    port->led2 = 15;

    return 0;
}