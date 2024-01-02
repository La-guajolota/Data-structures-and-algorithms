/*
For example, an array [10,20,30,40,50,60] rotate by 2 
positions to
                [30,40,50,60,10,20]
*/

#include <stdio.h>

//Primer elemento de array de n elementos k rotations
void rotateArray(int *a,int n,int k);
void reverseArray(int *a,int n);

int main(){
    int array[] = {10,20,30,40,50,60};

    rotateArray(array,6,2);

    for (int i=0; i<6; i++){
        printf("[ %d ]",array[i]);
    }
    
    return 0;
}

/*
Rotating list is done in two parts trick:

1_ In the first part, we first reverse elements of 
list first half and then second half.

2_ Then we reverse the whole list there by 
completing the whole rotation.
*/
void rotateArray(int *a,int n,int k){
    
    //Primer paso
    reverseArray(a,k);
    reverseArray(&a[k],n-k);
    //Segundo paso
    reverseArray(a,n);

}

//propiedad de cancelación y la propiedad de inversión del XOR
void reverseArray(int *a,int n){

    /*
        i--> primer elemento
        j--> ultimo

        EL INTERCAMBIO
        es equivalente:
            a[i] = a[i] ^ a[j];
            a[j] = a[i] ^ a[j];
            a[i] = a[i] ^ a[j];
    */

    for(int i=0,j=n-1; i<j; i++,j--){
        a[i]^=a[j]^=a[i]^=a[j];//intercambiamos los elementos de lugar
    }
}
