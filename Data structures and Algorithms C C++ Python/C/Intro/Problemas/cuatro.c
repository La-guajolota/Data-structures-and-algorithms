//Find the smallest element in the array
#include <stdio.h>
#include <math.h>
#define max 10

void populate_array(int arr[], int size);//Popula el arreglo
int minelement(int arr[], int size);//Calcula el promedio del array

int main(){

    int array[max], rsl;

    int size = sizeof(array)/sizeof(int);
    populate_array(array, size);
    rsl = minelement(array, size);
    
    printf("\nElemento mas chico: %d",rsl);

    return 0;
}

//Llenamos el array con una lista de 
//numeros en orden 
void populate_array(int arr[], int size){

    for (int i=0; i<size; i++){
        arr[i] = (int)(pow(i-1,3)+pow(i-2,2)-2); //Poblamos con y(i)=(i-2)^3+(i-3)^2-2
            printf("%d ",arr[i]);
    }
}

int minelement(int arr[], int size){

    int m = arr[0];//Asumimos al primero como el mas chiquito

    for (int i=1; i<size; i++){//Iteramos
        if(m>arr[i]) m=arr[i];
    }

    return m;
}