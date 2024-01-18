#include <stdio.h>
#include <string.h>

int main()
{
    char strToShow[10];

    sprintf(strToShow, "%010d", 12345);

    printf("%s", strToShow);

    return 0;
}