/*
Imprimimos los elementos del array de dos dimensiones
a la vez que las direcciones de memmoria de cada casilla
*/

#include <stdio.h>

//prototipado
void print2DArray(int* arr[], int row, int col);
void print2DArrayAddress(int* arr[], int row, int col);

int main(){

    int arr[4][2];
    int cont = 0;

    //Llenamos de elementos
    for (int i=0; i<4; i++){//ROW
        for (int j=0; j<3; j++){//COL
            
            arr[i][j] = cont++;
        }
    }
    
    print2DArray((int**)arr, 4, 2);
    printf("\n");
    print2DArrayAddress((int**)arr, 4, 2);

    return 0;
}


void print2DArray(int* arr[], int row, int col){

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){
                printf("[ %d ]", *(arr + i*col + j));
        }

    }
}

void print2DArrayAddress(int* arr[], int row, int col){

    for (int i = 0; i < row; i++){
        for (int j = 0; j < col; j++){

            printf("Value: %d, Address: %p\n", *(arr+i*col+j), (arr+i*col+j));
        }

    }
}