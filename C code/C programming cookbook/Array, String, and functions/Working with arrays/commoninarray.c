#include <stdio.h>
#include <stdlib.h> //Para pasuse terminal
#define max 100

int ifexists(int z[], int u, int v){

    int i;
    if(u==0) return 0;// u-longitud del array no cero
    for(i=0;i<=u;i++)
        if(z[i]==v) return (1);//Recorremos el arreglo comparando cada uno de sus elementos
    return 0;
}

int main(){

    int p[max],q[max],r[max];
    int m,n;//Longitudes de cada arreglo
    int i,j,k = 0;// i-columna j-fila k-contador de elementos en comun

    //Pirmer arreglo
    printf("Ingresa la longitud del primer array: ");
    scanf("%d",&m);
    
    printf("Ingrese %d elementos del primer arreglo\n",m);
    for(i=0;i<m;i++){
        scanf("%d",&p[i]);
    }

    //Segundo arreglo
    printf("Ingresa la longitud del segundo array: ");
    scanf("%d",&n);
    
    printf("Ingrese %d elementos del segundo arreglo\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&q[i]);
    }


    for (i=0;i<m;i++){//Elementos P[]
        for (j=0;j<n;j++){//Elelementos Q[]
            
            if (p[i]==q[j]){//Si concide? 
                
                if(!ifexists(r,k,p[i])){//Hay mas repetidos??
                    r[k]=p[i];//Agregamos elementos en comun a matriz resultado
                    k++;//Crecemos la cantidad cardnalr de elementos en comun
                }
            }
        }
    }

    if(k>0){
        printf("\nThe common elements in the two arrays are:\n");
        for(i = 0;i<k;i++){
            printf("%d\n",r[i]);
        }
    }else{
        printf("There are no common elements in the two arrays\n");
    }

    system("pause");
    return 0;
}