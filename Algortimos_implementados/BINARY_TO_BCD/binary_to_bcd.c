#include <stdio.h>
#include <stdint.h>

/*
1-
Left-shift the (n-bit) binary
number one bit.

2-
If n shifts have taken place, the
number has been fully expanded, so
exit the algorithm.

3-
If the binary value of any of the BCD
columns is greater than or equal to 5, add 3.

4-
Return to (1).
*/

/*
Prototipado de la funcion principal
*/
void BINARY_TO_BCD(uint16_t binary, uint8_t *BCD);
uint8_t BCD_TO_SEVEN_SEGMENT(uint8_t BCD);
void binary_print(uint8_t num);

int main()
{
    uint16_t binary_input; // Variable para almacenar el número binario ingresado por el usuario
    uint8_t BCD[4] = {0};  // Arreglo para el código BCD

    // Pedir al usuario que ingrese el número binario
    printf("Ingrese un numero binario de 16 bits: ");
    scanf("%hu", &binary_input);

    printf("Ingreso: ");
    binary_print(binary_input);
    printf("\n");

    BINARY_TO_BCD(binary_input, BCD); // Convertir el número binario ingresado a BCD

    // Mostrar el código BCD resultante
    printf("Codigo BCD del numero %hu:\n", binary_input);
    for (int i = 0; i < 4; i++)
    {
        printf("%x ", BCD[i]);
    }
    printf("\nCodificacion BCD\n");

    printf("\nCodificacion en 7 segmentos\n");

    // Mostrar el código BCD resultante
    printf("Codigo BCD del numero %hu:\n", binary_input);
    for (int i = 0; i < 4; i++)
    {
        printf("%x ", BCD[i]);
    }

    // Imprime el codigo de 7 segmentos
    // Imprime los mismo digitos pero en binario
    for (int i = 0; i < 4; i++)
    {
        binary_print(BCD_TO_SEVEN_SEGMENT(BCD[i]));
        printf(" ");
    }

    return 0;
}

/**
 * @brief Combierte un numero binario en sus digitos Decimale
 *        Pasa de binario a codigificacion BCD
 *
 * @param binary uint16_t numero a comberit
 * @param BCD uint8_t * arreglo de almentos 4 espacios
 */
void BINARY_TO_BCD(uint16_t binary, uint8_t *BCD)
{
    uint8_t pos_msb = 15; // Inicializamos la posicion del MSB (máximo 15 para uint16_t)

    // *Encontramos la posicion del bit más significativo (MSB)
    while (!(binary & (0x01 << pos_msb)))
    {
        pos_msb--;
    }
    // printf("Posicion del MSB del binario 0x%04x es %d\n", binary, pos_msb);

    uint32_t buffer_bin = binary << (15 - pos_msb); // Copiamos al buffer
    // printf("Buffer: %08x\n", buffer_bin);

    // Comienza algoritmo
    uint8_t shift_count = 0;
    do
    {
        buffer_bin <<= 1; // *Paso 1
        shift_count++;

        // Revisar cada dígito BCD
        for (int i = 0; i < 4; i++)
        {
            BCD[i] = (buffer_bin >> (28 - i * 4)) & 0x0F; // Extraer cada dígito BCD

            // Paso 3: Ajustar dígitos BCD usando shift-and-add-3
            if (BCD[i] >= 5 && shift_count <= pos_msb)
            {
                BCD[i] += 3; // Aplicar shift-and-add-3

                // Actualizar buffer_bin con el nuevo valor BCD
                buffer_bin &= ~(0x0F << (28 - i * 4));  // Limpiar el dígito BCD
                buffer_bin |= (BCD[i] << (28 - i * 4)); // Agregar el nuevo valor BCD
            }
        }

    } while (shift_count <= pos_msb); // Paso 2
}

/**
 * @brief Regresa el codigo de 7 segmentos desde
 *        un numero BCD
 * @param BCD
 * @return uint8_t codio de 7 segmentos
 */
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

/**
 * @brief Imprime en formato binario algun numero de 8 bits
 *
 * @param num
 * @return * void
 */
void binary_print(uint8_t num)
{

    for (int i = 0; i < 8; i++)
    {
        if ((num & (0x80 >> i)) << i)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }
}