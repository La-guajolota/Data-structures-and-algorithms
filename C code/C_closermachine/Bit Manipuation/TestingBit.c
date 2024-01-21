#include <stdio.h>

int main()
{
    int value = 0x1f;
    int mask = 0x10;
    int result = ~value & mask;
    printf("%x\n", result);

    result = !(~value & mask);
    printf("%x\n", result);

    result = !(value & mask);
    printf("%x\n", result);

    return 0;
}