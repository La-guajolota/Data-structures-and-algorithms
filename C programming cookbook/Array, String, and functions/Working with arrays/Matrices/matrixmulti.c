#include <stdio.h>
#include <stdlib.h> //Para pasuse terminal

int main(){

    int matA[2][3], matB[3][4], matR[2][4];//Matrices
    int i,j,k;// i-columna j-fila k-auxiliarMultiplicacion

    printf("Ingresar los elementos de la matri matA[2][3] \n");
    for(i=0;i<2;i++){//matA[2][.] columna
        
        for(j=0;j<3;j++){//matA[.][3] fila
        
            scanf("%d",&matA[i][j]);

        }
    }
    
    printf("Ingresar los elementos de la matri matA[3][4] \n");
    for(i=0;i<3;i++){//matA[3][.] columna
        
        for(j=0;j<4;j++){//matA[.][4] fila
        
            scanf("%d",&matB[i][j]);

        }
    }

    //Ejecutamos la multiplicacion de matrices
    for(i=0;i<2;i++){//matR[2][.] columna
        
        for(j=0;j<4;j++){//matR[.][4] fila
        
            matR[i][j] = 0; //inicalizamos de 0 a la matriz resultado

            for (k=0;k<3;k++)
            {
                matR[i][j] = matR[i][j] + matA[i][k]*matB[k][j];
            }
            
        }
    }

    printf("\nMatrizA \n");
    for(i=0;i<2;i++){
        for(j=0;j<3;j++){
            printf("%d\t",matA[i][j]);
    }
        printf("\n");
    }

    printf("\nMatrizB \n");
    for(i=0;i<3;i++){
        for(j=0;j<4;j++){
            printf("%d\t",matB[i][j]);
    }
        printf("\n");
    }

    printf("\nMatrizR \n");
    for(i=0;i<2;i++){
        for(j=0;j<4;j++){
            printf("%d\t",matR[i][j]);
    }
        printf("\n");
    }

    system("pause");
    return 0;
}