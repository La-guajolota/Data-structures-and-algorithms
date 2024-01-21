#include <stdio.h>

int main()
{
    /*
    A very common application is to extract the RGB color information from a
    single int representing the color of a pixel. For example:
    */
    int RGBcolor = 0x010203;

    int B = RGBcolor & 0X0000FF;
    int G = RGBcolor & 0X00FF00;
    int R = RGBcolor & 0xFF0000;

    printf("R:%x G:%x B:%x\n", R, G, B);

    // Corregimos G y R
    G >>= 8;
    R = (unsigned)R >> 16;

    printf("R:%x G:%x B:%x\n", R, G, B);

    // Shifting
    int data = 0x0F;
    int result = data << 4;

    return 0;
}