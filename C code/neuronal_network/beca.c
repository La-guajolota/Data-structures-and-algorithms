#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// Capa
struct capa_base
{
    float inputs[3][7];
    float weights[3];
    uint8_t outs;
};

int main()
{
    struct capa_base Base;

    return 0;
}