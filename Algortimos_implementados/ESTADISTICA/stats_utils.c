#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*
Prototipado de funciones estadisticas
*/
float avrg(float *arra, uint16_t size); // Promedio
float vari(float *arra, uint16_t size); // Varianza
float std_dev(float varianza);          // Desviacion estandar

/*
Prototipado de funciones axuliares
*/

int main(int argc, char const *argv[])
{

    return 0;
}

////////////////////////////////////////////
///////////////////////////////////////////

/**
 * @brief Calcula la media aritmética de un conjunto de números.
 *
 * Esta función calcula la media aritmética de los elementos en el arreglo proporcionado.
 * La media aritmética se define como la suma de todos los elementos dividida por la cantidad
 * de elementos en el arreglo.
 *
 * @param arra Puntero al arreglo de números.
 * @param size Cantidad de elementos a procesar en el arreglo.
 * @return float Media aritmética de los números en el arreglo.
 */
float avrg(float *arra, uint16_t size)
{
    float ave = 0;

    for (int i = 0; i < size; i++)
    {
        ave += arra[i];
    }

    return ave / size;
}

/**
 * @brief Calcula la varianza de un arreglo de números.
 *
 * Esta función calcula la varianza de los elementos en el arreglo proporcionado.
 * La varianza se define como la media de los cuadrados de las diferencias entre
 * cada elemento y la media aritmética del arreglo.
 *
 * @param arra Puntero al arreglo de números.
 * @param size Tamaño del arreglo.
 * @return float Varianza del arreglo de números.
 */
float vari(float *arra, uint16_t size)
{
    float suma = 0, suma2 = 0; // Suma de los elementos y la suma de sus cuadrados

    for (int i = 0; i < size; i++)
    {
        suma += arra[i];
        suma2 += arra[i] * arra[i];
    }

    float ave = suma / size; // Calcular la media aritmética

    // Calcular la varianza
    float varianza = (suma2 - 2 * ave * suma + size * ave * ave) / (size - 1);

    return varianza;
}

/**
 * @brief Calcula la desviación estándar a partir de la varianza.
 *
 * Esta función toma la varianza de una distribución o conjunto de datos y calcula
 * la desviación estándar, que es la raíz cuadrada positiva de la varianza.
 * La desviación estándar es una medida de dispersión que indica cuánto se alejan
 * los valores de una distribución o conjunto de datos respecto a su media.
 *
 * @param varianza Varianza de la distribución o conjunto de datos.
 * @return float Desviación estándar correspondiente a la varianza proporcionada.
 */
float std_dev(float varianza)
{
    return sqrt(varianza);
}
