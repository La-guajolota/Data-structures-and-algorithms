#include <stdio.h>

int myglobal = 123;

int c = 0; // Variable global
int counter()
{
    c++;
    return c;
}

int main()
{

    printf("%d \n", counter());
    printf("%d \n", counter());

    return 0;
}