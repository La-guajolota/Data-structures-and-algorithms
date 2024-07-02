#include <stdio.h>
#include <stdint.h>

void BINARY_TO_BCD(uint16_t binary, uint8_t *BCD)
{
    uint8_t pos_msb = 15;

    while (!(binary & (0x01 << pos_msb)))
    {
        pos_msb--;
    }

    uint32_t buffer_bin = binary << (15 - pos_msb);

    uint8_t shift_count = 0;
    do
    {
        buffer_bin <<= 1;
        shift_count++;

        for (int i = 0; i < 4; i++)
        {
            BCD[i] = (buffer_bin >> (28 - i * 4)) & 0x0F;

            if (BCD[i] >= 5 && shift_count <= pos_msb)
            {
                BCD[i] += 3;
                buffer_bin &= ~(0x0F << (28 - i * 4));
                buffer_bin |= (BCD[i] << (28 - i * 4));
            }
        }
    } while (shift_count <= pos_msb);
}

uint8_t BCD_TO_SEVEN_SEGMENT(uint8_t BCD)
{
    uint8_t lookup[] = {
        0b1111110, // 0
        0b0110000, // 1
        0b1101101, // 2
        0b1111001, // 3
        0b0110011, // 4
        0b1011011, // 5
        0b1011111, // 6
        0b1110000, // 7
        0b1111111, // 8
        0b1111011  // 9
    };

    return lookup[BCD];
}
