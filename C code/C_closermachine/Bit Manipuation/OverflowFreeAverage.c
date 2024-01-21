#include <stdio.h>

int main()
{
    int a = 0b101, b = 0b011;
    int avg = (a + b) / 2;
    printf("avrg: %d\n", avg);

    /*
    This has one problem – a+b can overflow even if the answer is representable
    in the number of bits available. At first it looks as if nothing can be done but
    if a result can be represented then there is usually a bit-manipulation way of
    computing it without the threat of overflow.
    */

    a = 0b101;
    b = 0b011;
    // todo: half adder
    int sum = a ^ b;
    int carry = a & b;
    printf("sum:%d cary:%d\n", sum, carry);

    sum = sum + (carry << 1);
    printf("sum:%d\n", sum);

    // todo: De manera sintética
    avg = ((a ^ b) >> 1) + (a & b); // !which can be computed with no risk of overflow.
    printf("%d\n", avg);

    return 0;
}