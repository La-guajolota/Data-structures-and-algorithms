#include <stdio.h>
#include <stdlib.h>

// Pototipado
int sum(int a, int b)
{
    return a + b;
}

int (*psum)(int, int); // Creamos puntero a funcion

int main()
{
    psum = &sum; // Inicializamos el puntero a funcion int con dos paramentros int

    int r = (*psum)(1, 2); // La lllamamos de esta manera
    printf("resulta: %d\n", r);

    return 0;
}