#include <stdio.h>
#include <stdint.h>

int main()
{
    int8_t just9bits;    // 8bits de resolucion
    uint16_t just2bytes; // 2 bytes de resolucion sin signo

    /*
    This all works well, but if the machine doesn't support int16_t as a native
    two-byte int the results could be very slow. There is an alternative which lets
    you specify either the minimum width that can be used:

        int_leastN_t
    or:
        uint_leastN_t
    or the fastest minimum width:
        int_fastN_t
    or:
        uint_fastN_t.
    !For example:
    */

    //! Todo depende del compilador y del hardware
    int_least8_t mybyte; // Tan pocos bits pero almenos más o igual a 8bits
    int_fast8_t mybyte2; // Igual que leat pero minimo 8bits pero sera mayor si es masr rapido usarlo así

    return 0;
}