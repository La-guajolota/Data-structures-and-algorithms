#include <stdio.h>

int main()
{
    unsigned int n = 0x0a0b0c0d;
    unsigned char c, d, *p;

    c = (unsigned char)n;
    p = (unsigned char *)&n;
    d = *p; // si 0x0d significa que es un procesador de little-endian

    printf("n=%x\nc=%x\nd=%x\np=%x\n", n, c, d, p);

    return 0;
}