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

#include <stdio.h>
#include <stdint.h>

/*
MODIFICABLES
!Solo regresa unidades, decenas, y centenas
*/
uint16_t binary = 255; // Numero en binario (ejemplo: 1111 1111)

/*
Prototipado de la funcion principal
*/
void BINARY_TO_BCD(uint16_t binary, uint8_t *BCD);

int main()
{

    uint8_t BCD[4] = {0}; // Arreglo para el codigo BCD

    BINARY_TO_BCD(binary, BCD); // HACEMOS LA CONVERSION

    // Mostrar el codigo BCD resultante
    printf("Codigo BCD del numero %d:\n", binary);
    for (int i = 0; i < 4; i++)
    {
        printf("%x ", BCD[i]);
    }
    printf("\n");

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