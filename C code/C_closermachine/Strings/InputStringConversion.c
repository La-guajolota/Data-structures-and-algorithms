#include <stdio.h>
#include <string.h>

int main()
{
    char s[] = "1234.456 Some Data";
    char *prt;

    int num = strtol(s, &prt, 10); // strtol(string, end, base)
    printf("%d", num);

    char myString[25];
    printf("Escribe un int, double\n");
    fflush(stdout);
    fgets(myString, 25, stdin);

    char *p;
    int num1 = strtol(myString, &p, 10);
    printf("%d", num1);
    p++;
    double num2 = strtod(p, &p);
    printf("%f", num2);

    system("pause");
    return 0;
}