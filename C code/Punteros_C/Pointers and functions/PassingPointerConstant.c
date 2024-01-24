#include <stdio.h>

void passingAdreesOfConstants(const int *num1, int *num2)
{
    *num2 = *num1;
}

void passingAdreesOfConstants2(const int *num1, int *num2)
{
    // /// *num1 = 100;
    *num2 = 200;
}

int main()
{
    const int limit = 100;
    int result = 5;

    printf("limit:%d   |   result:%d\n", limit, result);
    passingAdreesOfConstants(&limit, &result);
    printf("limit:%d   |   result:%d\n", limit, result);

    passingAdreesOfConstants2(&limit, &result);
    printf("limit:%d   |   result:%d\n", limit, result);

    return 0;
}