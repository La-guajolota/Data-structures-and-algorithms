/*
We can define a pointer array similar to an array of integer. 
The array element will store a pointer inside it.
*/

#include <stdio.h>

void printArray(int* arr[], int count);
void printArrayAddress(int* arr[], int count);

int main(){
    int one = 1, two = 2, three = 3;
    int* arr[3];//Cada elemento de este array es un puntero a un entero

    arr[0] = &one;
    arr[1] = &two;
    arr[2] = &three;

    printArray(arr,3);
    printf("\n");
    printArrayAddress(arr,3);

    return 0;
}

void printArray(int* arr[], int count){

    int *ptr;
    for (int i=0; i<count; i++){

        ptr = arr[i];//Apunta al iTH elemento
        printf("[ %d ]",*ptr);//Imprime el valor al que apunta ptr
    }
    
}


void printArrayAddress(int* arr[], int count){

    int *ptr;
    for (int i=0; i<count; i++){

        ptr = arr[i];//Apunta al iTH elemento
        printf("Valor es: %d, Direccion es: %p \n",*ptr, ptr);//Imprime el valor al que apunta ptr
    }
}