/*
In this recipe, we will use recursive functions to find the greatest common divisor (GCD),
also known as the highest common factor) of two or more integers. The GCD is the largest
positive integer that divides each of the integers. For example, the GCD of 8 and 12 is 4, and
the GCD of 9 and 18 is 9.
*/
#include <stdlib.h>
#include <stdio.h>

int gcd(int p, int q);

void main(){

    int x,y,g;

    printf("Enter two numbers: ");
    scanf("%d %d",&x,&y);

    g=gcd(x,y);

    printf("Greatest Common Divisor of %d and %d is %d",x,y,g);

    system("pause");
}


int gcd(int a, int b){
    
    int m;
    
    m=a%b;
    
    if(m==0)//b no puede dividir exactamente a
        return(b);
    else//Si sí encontes hacemos recurción con m
        gcd(b,m);//obligamos al numero mayor estar en el numerador

}