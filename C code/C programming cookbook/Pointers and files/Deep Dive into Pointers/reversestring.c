#include <stdio.h>
#include <stdlib.h>

void main(){
    char str[255], *ptr1, *ptr2, temp;
    int n,m;

    printf("Enter a string: ");
    scanf("%s", str);

    ptr1 = str;//direccion del primer caracter al PTR1
    n=1;

    while(*ptr1 != '\0'){//Hasta toparnos con el caracter null
        ptr1++;
        n++;//Contamos la cantidad de caracteres del string
    }

    ptr1--;//Nos regresamos al penultimo caracter, evitamos apuntar en null
    ptr2=str;////Adress de primer caracter al PTR2

    /*
       ptr1 esta en el penultimo elemento del str
       ptr2 esta en el primer caracter del str

       Ambos punteros avanzan en sentidos contrarios intercambiando
       sus elementos por cada posicion que ocupan
    */
    m=1;
    while (m<=n/2){

        temp=*ptr1;//temp como buffer latch
        *ptr1=*ptr2;//Intercambio de elemntos, ptr2 transfiere a ptr1
        *ptr2=temp;//buffer transfiere a ptr2

        //Recorremos en ambos punteros posiciones
        ptr1--;
        ptr2++;

        m++;//Umentamos la canidad inalizada de intercambios
    }

    printf("Reverse string in %s\n", str);
    system("pause");
}