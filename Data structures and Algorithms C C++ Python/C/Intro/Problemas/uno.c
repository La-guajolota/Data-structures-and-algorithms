// Find average of all the elements in an array.

#include <stdio.h>
#define max 10

void populate_array(int arr[], int size);//Popula el arreglo
int avrgarray(int arr[], int size);//Calcula el promedio del array

int main(){

    int array[max], rsl;

    /*
    printf("Size en bytes de array: %d y del tipo INT: %d\n",sizeof(array),sizeof(int));
    printf("Por tanto se tiene N elementos: %d\n",sizeof(array)/sizeof(int));
    */

    int size = sizeof(array)/sizeof(int);
    populate_array(array, size);
    rsl = avrgarray(array, size);
    
    printf("Promedio: %d",rsl);

    return 0;
}

//Llenamos el array con una lista de 
//numeros en orden 
void populate_array(int arr[], int size){

    for (int i=0; i<size; i++){
        arr[i] = i*i; //Poblamos con y(i)=i^2
    }
}

int avrgarray(int arr[], int size){

    int avrg = 0;

    for (int i=0; i<size; i++){
        avrg += arr[i];
    }

    return avrg/size;//Promedio redondeado a int
}