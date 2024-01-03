/*
Analysis:
Similar iterative solution we had already seen. Now let us look into the
recursive solution of the same problem in this solution also, we are diving the
search space into half and doing the same what we had done in the iterative
solution.
*/

#include <stdio.h>

int BinarySearch(int arr[], int size, int value);
int BinarySearchrecursive(int arr[],int low, int high, int value);

int main() {
    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    int rslt = BinarySearch(arr,10,79);

    if (rslt==1){
        printf("Se encontró el elemento\n");
    } else {
        printf("Nope, no se encontró\n");
    }

    return 0;
}

int BinarySearch(int arr[], int size, int value){
    int low = 0, mid;
    int high = size - 1;

    BinarySearchrecursive(arr,low,high,value);
}

int BinarySearchrecursive(int arr[],int low, int high, int value) {

   if(low>high) return 0;//No se encontró

   int mid = low+(high-low)/2;//Evitamos overflow

   if (arr[mid]==value){
        return 1;//Se encontró
   }else if (arr[mid]<value){
        BinarySearchrecursive(arr,mid+1,high,value);
   }else{//>
        BinarySearchrecursive(arr,low,mid-1,value);
   } 
}