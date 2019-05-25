#include <iostream>

int modifiedBinarySearch(int *arr, int low, int high, int key)
{
    // key not present
    if(low > high)
    {
        return -1;
    }

    int mid = (low + high)/2;

    if(arr[mid] == key)
    {
        return mid;
    }

    // if left half is sorted
    if(arr[low] <= arr[mid])
    {
        // if key is present in left half
        if(arr[low] <= key && key <= arr[mid] )
            return modifiedBinarySearch(arr, low, mid-1, key);
        else // key must be present in right half
            return modifiedBinarySearch(arr, mid+1, high, key);

    }
    else // right half must be sorted
    {
        // if key is present in right half
        if(arr[mid] <= key && key <= arr[high])
            return modifiedBinarySearch(arr, mid+1, high, key);
        else // key must be present in left half
            return modifiedBinarySearch(arr, low, mid-1, key);
    }
}

int main()
{
    int arr[] = {4, 5, 6, 7, 8, 9, 1, 2, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int key = 9;
    int i = modifiedBinarySearch(arr, 0, n-1, key);

    if (i != -1)
        std::cout << "Index: " << i << std::endl;
    else
        std::cout << "Key not found";

    return 0;
}
