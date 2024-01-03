#include <stdio.h>

//Imprime numeros enteros de base 16
void printInt(unsigned int n, const int base);

int main(){

    //printf("size en bytes de char: %d\n funcionInt:",sizeof(char));
    
    for (int i=1; i<3*16+1; i++){
        
        printf("N: %d --> b16: ",i);
        printInt(i,16);
        printf("\n");
    }
    

    return 0;
}

void printInt(unsigned int n, const int base){

    //Array de los caracteres para representar en base 16
    char* digitos = "0123456789ABCDEF";
    char digit = n%base;//Encontramos el resuido

    if(n/=base) printInt(n,base);//Si hay enteros entra cuerpo recursivo

    printf("%c",digitos[digit]);//Imprime el caracter segun el valor posicional
}