#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    // These put  and get a single char from the standard I/O streams
    printf("Ingresa un caracter\n");
    fflush(stdout);
    int c = getchar();

    // printf("%c\n", c);
    // putchar(c);

    printf("Ingresa un caracter por segunda vez\n");
    fflush(stdout);
    char s[25];
    gets(s);
    puts(s);

    return 0;
}