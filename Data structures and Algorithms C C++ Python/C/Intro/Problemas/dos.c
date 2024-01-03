//Find the sum of all the elements of a two dimensional array
#include <stdio.h>

void populate_array(int *arr,int size);//Popula el arreglo
int avrgarray(int *arr,int size);//Calcula el promedio del array

int main(){

    int ROW=2, COL=2;
    int array[ROW][COL], rsl;

    populate_array(*array,ROW*COL);
    rsl = avrgarray(*array,ROW*COL);
    
    printf("\nSuma total: %d",rsl);

    return 0;
}

//Llenamos el array con una lista de 
//numeros en orden 
void populate_array(int *arr, int size){

    //Llenamos de elementos
    for (int i=0; i<size; i++){
        *(arr+i)= i;
        printf("%d+ ",*(arr+i));
    }

}

int avrgarray(int *arr, int size){

    int avrg = 0;
    for (int i=0; i<size; i++){
            avrg += *(arr++);
    }

    return avrg;//Suma total
}