#include <stdio.h>
#include <string.h>

int main()
{
    char ABC_init = 'A';   // 65 en ASCCI es la A
    char B = ABC_init + 1; // 66 ES LA b

    int var = 'Z'; // Z=90

    printf("%d es %c\n", ABC_init, ABC_init);
    printf("%d es %c\n", B, B);

    // Extended ASCII Codes del 128-255
    unsigned char c = 0;
    for (int i = 0; i <= 255; i++)
    {
        printf("%d es en ASCII %c\n", c, c);
        c++;
    }

    return 0;
}