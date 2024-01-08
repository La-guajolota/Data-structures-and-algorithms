#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* generar_array_aleatorio(int n, int rango_inicio, int rango_fin) {
    int* array = (int*)malloc(n * sizeof(int));

    // Semilla para la función rand() basada en el tiempo actual
    srand(time(NULL));

    for (int i = 0; i < n; i++) {
        // Genera un entero aleatorio en el rango [rango_inicio, rango_fin)
        array[i] = rand() % (rango_fin - rango_inicio) + rango_inicio;
    }

    return array;
}

/*
int main() {
    int cantidad_enteros = 10;
    int* array_aleatorio = generar_array_aleatorio(cantidad_enteros, 0, 100);

    //  Imprime el array aleatorio
    printf("Array aleatorio: ");
    for (int i = 0; i < cantidad_enteros; i++) {
        printf("%d ", array_aleatorio[i]);
    }

    // Libera la memoria asignada para el array
    free(array_aleatorio);

    return 0;
}
*/