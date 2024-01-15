#include <stdio.h>

int main()
{
    char mychar = 'A';
    printf("%c -> ", mychar);
    printf("%d\n", mychar);

    float pi = 3.1416;
    printf("%1.3f\n", pi);

    char string[] = "ABCD";
    printf("%10s\n", string);  // 10 lugares, los sobrnates se llenan con tabs
    printf("%-10s\n", string); // para la derecha los rellenos

    int num = 12345;
    printf("%-10d\n", num); // Se puede con numeros tambien
    printf("%010d\n", num); // Rellena con ceros

    return 0;
}