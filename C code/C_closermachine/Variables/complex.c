#include <complex.h>
#include <stdio.h>

int main()
{

    double complex z1 = 1 + 1 * I, z2;
    float real, img, ang;

    // Componentes del nmero complejo
    real = creal(z1);
    img = cimag(z1);
    ang = carg(z1) * ((360) / (2 * 3.1416)); // rad->> grados

    printf("Componentes real: %f imga: %f\n de argumento: %f\n", real, img, ang);

    z2 = conj(z1); // conjugado de z1
    real = creal(z2);
    img = cimag(z2);

    printf("Conjugado de z1-> real: %f img: %f\n", real, img);

    return 0;
}