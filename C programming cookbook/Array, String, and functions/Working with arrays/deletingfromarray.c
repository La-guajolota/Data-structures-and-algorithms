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

    printf("\nIngresa la posicion del elemento a eleminar:");
    scanf("%d",&k); 
    k--;// Los arreglos incian en un 0 cardinal


    ///
    ///Algoritmo de popping out
    ///
    /*
        All values from the bottom of the array are shifted up till
        the location of the element to be deleted
    */
    for(int j=k;j<=n-2;j++){ 
        p[j]=p[j+1];// El ultimo lemento se recorre a la derecha
    }
    p[n-1] = 0;//The vacant position created at the bottom of the array is set to 0

    printf("\nNuevo arreglo: \n");
    for(int i=0;i<=n-2;i++){
        printf("%d\n",p[i]);
    }

    system("pause");
    return 0;
}