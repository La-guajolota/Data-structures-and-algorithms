#include <stdio.h>
#include <stdlib.h>

//! Funciones a punteros prototipado
int (*f1)(double);       // Passed a double and
                         // returns an int
void (*f2)(char *);      // Passed a pointer to char and
                         // return void
double *(*f3)(int, int); // Passed two integers and
                         //  returns a pointer to a double
int (*f4)(int);

// TODO: funcines
int square(int num);

int main()
{
    int n = 5;
    f4 = &square; // Pasamos funcion square al puntero f4
    printf("%d squared is %d\n", n, f4(n));

    return (EXIT_SUCCESS);
}

// TODO: Funciones especificación
int square(int num)
{
    return num * num;
}