#include <stdio.h>

int main()
{
    int a = 0, b = 0;

    // Ejemplo_2
    int result = a || (b++);
    printf("result: %d\n", result);

    // Ejemplo_1
    result = a || (b / 1);
    printf("result: %d\n", result);

    return 0;
}