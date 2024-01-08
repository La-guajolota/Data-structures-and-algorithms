/*
Time Complexity: O(n). As we need to traverse the complete array in worst
case. Worst case is when your desired element is at the last position of the
array. Here, ‘n’ is the size of the array.
Space Complexity: O(1). No extra memory is used to allocate the array.
*/

int linearSearchUnsorted(int arr[], int size, int value)
{
    int i = 0;
    for (i = 0; i < size; i++)
    {
        if (value == arr[i])
            return i; // Se encontró y se regresa la posicion
    }
    return -1; // No se encontro
}