#include <stdio.h>

// Factorial Calculation. N! = N* (N-1)…. 2*1.
//Complexity is O(N)
int factorial(unsigned int i);

int main(){

    int fact_n, n=5;
    
    fact_n = factorial(n);

    printf("!%d = %d",n,fact_n);

    return 0;
}

int factorial(unsigned int i){

    if(i<=1){//Condicion finalizadora
        return 1;
    }

    return i*factorial(i-1);//Expancion recursiva
}