#include <stdio.h>
#include <stdbool.h> //Crea el tipo de dato booleano

int main()
{

    int var;
    var = (1 > 3); // Es falso, entonces asigna 0

    printf("%d\n", var);

    var = (3 > -4); // Es cierto, entonces asigna 1

    printf("%d\n", var);

    bool var2;
    var2 = true;

    printf("%d\n", var2);

    return 0;
}