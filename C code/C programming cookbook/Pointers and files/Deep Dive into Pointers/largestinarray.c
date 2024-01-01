#include <stdio.h>
#include <stdlib.h>

#define max 100

void main(){
    int p[max], i, n, *ptr, *mx;

    printf("How many elements are there? ");
    scanf("%d", &n);

    printf("Enter %d elements \n", n);//Capturamos los elementos
    for(i=0;i<n;i++)
        scanf("%d",&p[i]);
    
    //Amboos punteros almancena la primera direccion del arreglo
    mx=p;//Almacenara la direccion de memoria del elementor mas grnade del array
    ptr=p;//Puntero auxiliar para recorrer por todas las direcciones de memroia del arreglo
    
    for(i=1;i<n;i++){
        if (*mx < *ptr)//Comparamos valores contenidos
            mx=ptr;//cambiamos de dreccion de memoria al que apunta mx
        ptr++;//Avanzamos apuntando al siguiente valor
    }

    printf("Largest value is %d\n", *mx);

    system("pause");
}