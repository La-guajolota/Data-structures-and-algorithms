#include <stdio.h>
#include <stdlib.h> //Para pasuse terminal

#define max 100 

//Testeamos codigo
int main(){
    int n,k,p[max]; 

    printf("Ingresa la longitud del arreglo: ");
    scanf("%d",&n);

    printf("\nIngresa los elementos de tu arreglo:\n");
    for(int i=0; i<=n-1;i++){//AGRGAMOS LOS ELEMENTOS AL ARRAY
        scanf("%d",&p[i]);
    }

    printf("\nIngresa la posicion en donde insertar el nuevo elemento:");
    scanf("%d",&k); 
    k--;// Los arreglos incian en un 0 cardinal


    ///
    ///Algoritmo de recorrimiento de elementos
    ///
    /*
        j=n-1 es el cardinal del ultimo elemento
        j>=k hasta que se llegue a la posicion en donde insertar el nuevo elemento
    */
    for(int j=n-1;j>=k;j--){ //Shifteamos todos los elementos una posicion para hacer espacio al nuvo elemento
        p[j+1]=p[j];// El ultimo lemento se recorre a la derecha
    }

    printf("\nIngresar nuevo elemento:");
    scanf("%d",&p[k]);

    printf("\nNuevo arreglo: \n");
    for(int i=0;i<=n;i++){
        printf("%d\n",p[i]);
    }

    system("pause");
    return 0;
}