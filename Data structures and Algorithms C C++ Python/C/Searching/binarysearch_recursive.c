/*
Time Complexity: O(logn).
Space Complexity: O(logn) for system stack in recursion
*/

int binarysearchrecursive(int arr[], int low, int high, int value)
{
    if (low > high)
    {
        return -1; // No se encontró
    }

    int mid = low + (high - low) / 2;

    if (arr[mid] == value)
    {
        return mid;
    }
    else if (arr[mid] < value)
    {
        return binarysearchrecursive(arr, mid + 1, high, value);
    }
    else // mayor qué >
    {
        return binarysearchrecursive(arr, low, mid - 1, value);
    }
}