#include <stdio.h>

//Imprime numeros enteros de base 10
void printInt(unsigned int n);

int main(){

    //printf("size en bytes de char: %d\n funcionInt:",sizeof(char));
    
    for (int i=1; i<1000; i+=100){
        
        printf("N: %d --> base 10: ",i);
        printInt(i+1);
        printf("\n");
    }
    

    return 0;
}

void printInt(unsigned int n){

    char digit = n%10 + '0';//Todo string lleva un '0'

    if(n/=10) printInt(n/10);

    printf("%c",digit);
}