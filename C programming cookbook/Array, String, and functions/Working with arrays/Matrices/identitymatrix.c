/*
A matrix is said to be an
identity matrix if it is a square matrix and all the elements of 
the principal diagonal are ones and all other elements are zeros.

1) Checks that if the index location of the row and column is the same, in other
words, if the row number is 0 and the column number, too, is 0, then at that
index location, [0][0], the matrix element must be 1. Similarly, if the row number
is 1 and the column number, too, is 1, that is, at the [1][1] index location, the
matrix element must be 1.

2) Verify that the matrix element is 0 at all the other index locations.

If both the preceding conditions are met, then the matrix is an identity matrix, or else it is
not.
*/
#include <stdint.h>
#include <stdlib.h> //Para pasuse terminal
#include <stdio.h>
#define max 100 

int DefMatriz(int r, int c, int arr[][max]){//Rellena lso elementos de la matriz

    for(int i=0;i<r;i++){//row
        for(int j=0;j<c;j++){//column

            scanf("%d",&arr[i][j]);

        }
    }

}

int PrintMatriz(int r, int c, int arr[][max]){//Imprime matriz

    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d\t",arr[i][j]);
        }
        printf("\n");
    }

}

int Identidad(int r, int c, int arr[][max]){//Checamos si es que identidad la matriz

    int i,j, flag = 1;

    if(r != c){//Checamos que la matriz sea cuadrada
        printf("Est no es una matriz identidad. No es una cuadrada\n");
        flag = 0;//No es identidad la matriz
    }else{


        for(i=0;i<r;i++){//row
            for(j=0;j<c;j++){//column

                if (i==j && (arr[i][j] != 1)) {
                    flag = 0;
                } else if (i != j && (arr[i][j] != 0)) {
                    flag = 0;
                }
    
            }
        }

    }

    return flag;//Si es identidad
}

int main(){

    int arr[max][max];
    int r,c, bool;

    printf("Cuantas filas y columnas hay en la matriz?\n");
    scanf("%d %d", &r, &c);

    printf("Ingresar los elementos de la matriz \n");
    DefMatriz(r,c,arr);

    printf("La matriz es: \n");
    PrintMatriz(r,c,arr);

    bool = Identidad(r,c,arr);
    if(bool == 1){

        printf("Es una matriz identidad\n");
    }else{

        printf("No es una matriz identidad\n");
    }

    system("pause");
    return 0;
}