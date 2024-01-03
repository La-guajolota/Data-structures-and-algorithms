
#include <stdio.h>

//Imprime numeros enteros en strings
char *intToStr(char *p,unsigned int number);

int main(){
    
    char *p;//Character buffer
 
    intToStr(p,1234567890);

    for (int i=0; i<10; i++){//Imprimimos
        printf("%c",*(p++));
    }
    
    
    return 0;
}

char *intToStr(char *p,unsigned int number){

    // '0' => 0x30 Ascci!!!
    char digit=number%10+'0';//LSDigit --> caracter correspondiente
    if(number/=10) p = intToStr(p,number);

    //The character is stored in the buffer p higher order first, then the lower order digits.
    *p++=digit;
    return(p);
}