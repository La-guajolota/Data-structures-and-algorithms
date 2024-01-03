//. Find the second largest number in the array.
#include <stdio.h>
#include <math.h>
#define max 9

void populate_array(int arr[], int size);//Popula el arreglo
int maxelement(int arr[], int size);//Calcula el elemento mas grande
int max2element(int arr[], int size);//Calcula el 2do elemento mas grande
int minelement(int arr[], int size);//Calcula el promedio del array

int main(){

    int array[max], rsl;

    int size = sizeof(array)/sizeof(int);
    populate_array(array, size);
    
    rsl = maxelement(array, size);
    printf("\nElemento mas grade: %d\n",rsl);

    rsl = max2element(array, size);
    printf("Elemento 2do mas grade: %d\n",rsl);

    rsl = minelement(array, size);
    printf("Elemento mas chico: %d",rsl);

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

int max2element(int arr[], int size){

    int max1 = maxelement(arr,size);

    int m = arr[0];//Asumimos al primero como el mas grande

    for (int i=1; i<size; i++){//Iteramos
        if(m<arr[i] && max!=m) m=arr[i];
    }

    return m;//El elemento más grnade
}

int minelement(int arr[], int size){

    int m = arr[0];//Asumimos al primero como el mas chiquito

    for (int i=1; i<size; i++){//Iteramos
        if(m>arr[i]) m=arr[i];
    }

    return m;
}