/* Binary Search Algorithm in a sortert array – Iterative Way */

/*
Analysis:
· Since we have data sorted in increasing / decreasing order, we can apply
more efficient binary search. At each step, we reduce our search space by
half.
· At each step, we compare the middle value with the value we are
searching. If mid value is equal to the value we are searching for then we
return the middle index.
· If the value is smaller than the middle value, we search the left half of
the array.
· If the value is greater than the middle value then we search the right half
of the array.
· If we find the value we are looking for then its index is returned or -1 is
returned otherwise.
*/
#include <stdio.h>

int BinarySearch(int arr[], int size, int value);

int main() {
    int arr[10];

    for (int i = 0; i < 10; i++) {
        arr[i] = i;
    }

    int rslt = BinarySearch(arr, 10, 99);

    if (rslt==1){
        printf("Se encontró el elemento\n");
    } else {
        printf("Nope, no se encontró\n");
    }

    return 0;
}

int BinarySearch(int arr[], int size, int value) {
    int low = 0, mid;
    int high = size - 1;

    while (low <= high) {
        mid = low + (high - low) / 2;

        if (arr[mid] == value){
            return 1; // Se encontró el elemento
        }
        else if (arr[mid] < value){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }

    }

    return 0; // No se encontró el elemento
}