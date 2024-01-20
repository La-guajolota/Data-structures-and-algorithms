#include <stdio.h>
#include <stdlib.h>

typedef int myinttpe; // Le da de alias a int myinttpe

// defines mypinttype to be a pointer to int, but as a type not a variable.
typedef int *mypinttype;

// declares myArray to be an int array with 20 elements, but as a type
typedef int myarray[20];

struct point
{
    int x;
    int y;
};
typedef struct point point_t;

typedef struct point_3d
{
    int x;
    int y;
    int z;
} point3d_t; // Nos arromaos la linea 17

typedef struct
{
    int a;
} alias_t;

// int *(pFunc)(int, int); Puede pasar a ser
/*
where now pFunc_t is a type specifying a pointer to a function that takes two
ints and returns an int.
*/
typedef int *(pFunc_t)(int, int);

int main()
{
    myinttpe variable;
    mypinttype *ptr;
    myarray arregloReal; // arregloReal es un arreglo de 20 elelemos

    point_t puntoA = {0, 0}; // Nueva instancia por medio del nuevo alias
    point3d_t A3d = {0, 0, 0};

    alias_t var = {5};

    pFunc_t pFunc;

    return 0;
}