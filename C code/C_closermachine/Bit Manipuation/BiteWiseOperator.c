#include <stdio.h>

int main()
{
    int a = 0xf0;
    int b = 0xff;
    int c = ~a & b;

    printf("c=%x\n", c);

    return 0;
}