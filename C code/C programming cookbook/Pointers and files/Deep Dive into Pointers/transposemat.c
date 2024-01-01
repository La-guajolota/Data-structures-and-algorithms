/*
The transpose of a matrix is a new matrix that has rows equal to the number of columns of
the original matrix and columns equal to the number of rows. 

Basically, we can say that, upon converting the rows into columns and columns into rows
of a matrix, you get its transpose.
*/

#include <stdio.h>
#include <stdlib.h>

void main(){
    int a[10][10], r, c, i, j, *ptr,m;
    
    printf("Enter rows and columns of matrix: ");
    scanf("%d %d", &r, &c);
    
    //Allocate memory locations equal to r *c quantity for keeping the matrix elements
    ptr = (int*)malloc(r*c*sizeof(int));

    printf("\nEnter elements of matrix:\n");
    for(i=0; i<r; ++i){
        for(j=0; j<c; ++j){
            scanf("%d", &m);
            //Enter elements of the matrix that will be assigned sequentially to each allocated
            //memory as follows
            *(ptr+ i*c + j)=m;//La matriz se almacen en elementos contiguos vector-like
        }
    }

    printf("\nMatrix using pointer is: \n");
    for(i=0; i<r; ++i){
        for(j=0; j<c; ++j){//elelementos por columna en N row
            printf("%d\t",*(ptr +i*c + j));
        }
        printf("\n");//nuevo row
    }

    printf("\nTranspose of Matrix:\n");
    for(i=0; i<c; ++i){
        for(j=0; j<r; ++j){
            //La formula ahora recorre los elementos pasando por filas y saltando a la siguente columnas
            printf("%d\t",*(ptr +j*c + i));
        }
        printf("\n");
    }

    system ("pause");
}