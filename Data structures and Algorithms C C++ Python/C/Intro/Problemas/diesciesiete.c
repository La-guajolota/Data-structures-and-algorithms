//Write a function to find the sum of every number in an int number.
//Example: input= 1984, output should be 22 (1+9+8+4).

#include <stdio.h>
#define N 1984

int Sumdig(int n);

int main(){

   int sum = Sumdig(N);
   printf("%d",sum);

    return 0;
}

int Sumdig(int n){

    int sum=0;
    int digit = n%10;//LSDigito

    if(digit == 0) return 0;
    sum += digit;
   
    return sum + Sumdig(n/10);//Pasamos al sig lsdigito
}