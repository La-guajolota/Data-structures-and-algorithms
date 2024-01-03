// 18. Write a function to compute Sum(N) = 1+2+3+…+N.

#include <stdio.h>
#define N 11

int GaussSum(int n);

int main(){

   int sum = GaussSum(N);
   printf("%d",sum);

    return 0;
}

int GaussSum(int n){

    int sum=0;

    if(n<1) return 0;
    sum += n+n-1;//n + (n-1)
   
    return sum + GaussSum(n-2);//n + (n-1) + (n-2) + (n-3) + ...
}

