/*
C functions cannot return more than one value. But what if you want a function to return
more than one value? The solution is to store the values to be returned in an array and
make the function return the array instead.
In this recipe, we will make a function return two values, the maximum and minimum
values, and store them in another array. Thereafter, the array containing the maximum and
minimum values will be returned from the function.
*/

/* Find out the maximum and minimum values using a function returning an
array */
#include <stdlib.h>
# include <stdio.h>
#define max 100

int *maxmin(int ar[], int v);

void main(){
    int arr[max];
    int n,i, *p;

    printf("How many values? ");
    scanf("%d",&n);

    printf("Enter %d values\n", n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);


    p=maxmin(arr,n);
    
    printf("Minimum value is %d\n",*p++);
    printf("Maximum value is %d\n",*p);

    system("pause");
}

int *maxmin(int ar[], int v){
    int i;
    static int mm[2];// Static para retener el valor en la funcio

    /*********************************************
    *    Algorimo de encontrar el maz y el minimo
    **********************************************/
    //El primer elemento como Min y Max, los asuminos inialmente como tales
    mm[0]=ar[0];//Aqui ira el maximo
    mm[1]=ar[0];//Aqui ira el minimo

    for (i=1;i<v;i++){
        if(mm[0] > ar[i])
            mm[0]=ar[i];
        if(mm[1]< ar[i])
            mm[1]= ar[i];
    }

    return mm;
}