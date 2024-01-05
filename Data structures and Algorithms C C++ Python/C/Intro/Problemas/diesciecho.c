// 18. Write a function to compute Sum(N) = 1+2+3+…+N.

#include <stdio.h>
#define N 10

/*
Ambas funciones tienen una complejidad de tiempo relativamente eficiente, pero la
versión iterativa GaussSum2 es más eficiente en términos prácticos para sumar los
primeros n números naturales. La versión recursiva GaussSum puede ser menos
eficiente debido a la sobrecarga asociada con las llamadas recursivas y la gestión
de la pila.
*/

int GaussSum(int n);  /// Recursividad
int GaussSum2(int n); // Lineal

int main()
{

    printf("Lineal: %d, Recursiva: %d", GaussSum2(N), GaussSum(N));

    return 0;
}

int GaussSum(int n)
{ // Recursividad

    int sum = 0;

    if (n < 1)
        return 0;
    sum += n + n - 1; // n + (n-1)

    return sum + GaussSum(n - 2); // n + (n-1) + (n-2) + (n-3) + ...
}

int GaussSum2(int n)
{ // Lineal

    int sum = 0;

    for (int i = 1; i <= N; i++)
    {
        sum += i;
    }

    return sum; // n + (n-1) + (n-2) + (n-3) + ...
}