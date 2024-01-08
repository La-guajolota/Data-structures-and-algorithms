/*
Time Complexity: O(logn). We always take half input and throwing out the
other half. So the recurrence relation for binary search is T(n) = T(n/2) + c.
Using master theorem (divide and conquer), we get T(n) = O(logn)
Space Complexity: O(1)
*/

int binarysearch(int arr[], int size, int value)
{
    int low = 0;
    int high = size - 1;
    int mid;

    while (low <= high) // Continuamos buscando?
    {
        mid = low + (high - low) / 2;
        if (arr[mid] == value)
        {
            return mid;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else // > mayor que
        {
            high = mid - 1;
        }
    }
    return -1;
}