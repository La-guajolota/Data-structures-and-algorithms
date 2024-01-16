#include <stdio.h>
#include <limits.h>

int main()
{
    // Primer ejemplo
    char myChar, myChar2;
    int myVar = 1024;
    int myVar2 = -1024;

    myChar = (char)myVar;
    myChar2 = (char)myVar2;

    printf("%x   (-)%x\n", myVar, myVar2);
    printf("%d   ", myChar);
    printf("%d \n", myChar2);

    // Segundo ejemplo
    signed char M = 1;
    int m = (int)M;

    printf("%x ", M);
    printf("%x \n", m);

    // Tercer ejemplo
    int myInt;
    float pi = 3.1416;
    myInt = (int)pi;

    printf("my int = %d \n", myInt);

    // Cuarto ejemplo
    unsigned int myUnsigned = UINT_MAX;
    int INTIGER = 1;
    long long mylong = (long long)INTIGER + (long long)myUnsigned;
    printf("%lld \n", mylong);

    // Quinto ejemplo
    int A = -1;
    unsigned int myVar3 = (unsigned int)myVar3;
    printf("int %d ->>> unsigned int %d\n", A, myVar3);

    return 0;
}