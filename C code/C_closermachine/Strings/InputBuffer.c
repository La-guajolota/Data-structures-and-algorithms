#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Como te llamas?\n");
    fflush(stdout);
    fflush(stdin);

    char userString[25];
    scanf("%s", userString);

    printf("Te llamas:%s\n", userString);

    system("pause");
    return 0;
}