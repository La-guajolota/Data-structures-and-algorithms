#include <stdio.h>
#include <stdint.h>

/*
? A CRC – Cyclic Redundancy Checksum –
is a common implementation
requirement. Many devices send data protected by a CRC, which is sent as
the last few bytes. The idea is that you read in the data, compute the CRC and
compare it to the CRC that has been sent with the data. If they are the same
then you can be relatively secure in the belief that the data has been received
without an error. For example, the simplest CRC is the sum of all the bits. If
the computed sum of bits doesn’t match the transmitted sum of bits you know
a bit has gone missing. However, you don’t know there is an error if two or
more bits have simply swapped their positions.

Typically a CRC is defined by specifying a polynomial. The idea is that each
term in the polynomial corresponds to a bit position in a shift register.
*/
int main()
{
    /*
    todo:       For example the polynomial used by 1-wire devices is:
                ! X**8 + X**5 + X**4 + 1

    The first question to answer is what is the connection between binary values
    and polynomials?

    The answer is that you can treat a binary number as the coefficients of a
    polynomial, for example 101 is 1*X2+0*X+1. Each bit position corresponds
    to a power of X. Using this notation creates a very simple relationship
    between multiplying by X and a left shift. For example:
                ! (1*X^2 + 0*X+ 1)*X = 1*X^3 + 0*X^2 + 1X + 0
    */

    uint16_t a = 0b101; // (1*X^2 + 0*X+ 1)*X
    a <<= 1;            // 1*X^3 + 0*X^2 + 1X + 0

    /*
        todo:       You can see that this extends to multiplying one polynomial by another and
        todo:       even polynomial division, all accomplished by shifting and XORing.

        The CRC is the remainder when you divide the polynomial that represents
        the data by the generator polynomial. The computation of the remainder is
        what the shift register does.
        The fact that the division can be implemented so simply in hardware is what
        makes this sort of CRC computation so common. All the hardware has to do is
        zero the shift register and feed the data into it. When all the data has been
        shifted in, what is left in the shift register is the CRC, i.e. the remainder.

        To check the data you have received all you have to do is run it through the
        shift register again and compare the computed CRC with the one received. A
        better trick is also to run the received CRC though the shift register. If there
        have been no errors this will result in 0.

        We now know everything we need to if we want to implement this CRC. All
        we have to do is implement the shift register in software.

        !From the diagram,
        what we have to do is take each bit of the input data and XOR it with the least
        significant bit of the current shift register.

        *   If the input bit is 0 then the XORs in the shift register don't have any
        *   effect and the CRC just has to be moved one bit to the right.

        *   If the input bit is 1, you have to XOR bits at positions 3
        *   and 4 with 1 and we have to put a 1 in at position 7 to simulate shifting a 1
        *   into the register,

        todo:       i.e. XOR the shift register with 10001100 or 0x8C.
        todo:       So the algorithm for a single byte contained in databyte is:
    */

    uint8_t temp, crc, databyte;

    databyte = 0b10111011; // Info recibida
    crc = 0xb10001100;

    for (int i = 0; i < 8; i++)
    {
        temp = (crc ^ databyte) & 0x01;
        crc >>= 1;
        if (temp)
        {
            crc ^= 0x8c;
            databyte >>= 1;
        }
    }

    printf("temp: %x\n", temp);
    printf("crc: %x\n", crc);
    printf("databyte: %x\n", databyte);

    return 0;
}