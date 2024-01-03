// Find the largest element in the array.
#include <stdio.h>
#include <math.h>
#define max 9

void populate_array(int arr[], int size);//Popula el arreglo
int maxelement(int arr[], int size);//Calcula el promedio del array

int main(){

    int array[max], rsl;

    int size = sizeof(array)/sizeof(int);
    populate_array(array, size);
    rsl = maxelement(array, size);
    
    printf("\nElemento mas grade: %d",rsl);

    return 0;
}

//Llenamos el array con una lista de 
//numeros en orden 
void populate_array(int arr[], int size){

    for (int i=0; i<size; i++){
        arr[i] = (int)-pow(i-5,2)+10; //Poblamos con y(i)=-((i-5)^2)+10
        printf("%d ",arr[i]);
    }
}

int maxelement(int arr[], int size){

    int m = arr[0];//Asumimos al primero como el mas grande

    for (int i=1; i<size; i++){//Iteramos
        if(m<arr[i]) m=arr[i];
    }

    return m;//El elemento más grnade
}