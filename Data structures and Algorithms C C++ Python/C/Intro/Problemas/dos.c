//Find the sum of all the elements of a two dimensional array

#include <stdio.h>
#define row 10
#define col 10

void populate_array(int arr[],int row,int col);//Popula el arreglo
int avrgarray(int arr[],int row,int col);//Calcula el promedio del array

int main(){

    int array[row][col], rsl;

    populate_array(array, row, col);
    rsl = avrgarray(array, row, col);
    
    printf("Suma total: %d",rsl);

    return 0;
}

//Llenamos el array con una lista de 
//numeros en orden 
void populate_array(int arr[], int row, int col){

    int cont = 0;
    //Llenamos de elementos
    for (int i=0; i<row; i++){//ROW
        for (int j=0; j<col; j++){//COL
            
            arr[i][j] = cont++;
        }
    }

}

int avrgarray(int arr[], int row, int col){

    int avrg = 0;

    for (int i=0; i<row; i++){//ROW
        for (int j=0; j<col; j++){//COL
            
            avrg +arr[i][j];
        }
    }

    return avrg;//Suma total
}