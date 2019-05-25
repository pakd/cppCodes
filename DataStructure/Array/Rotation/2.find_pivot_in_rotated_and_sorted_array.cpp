#include <iostream>

int searchPivot(int *arr, int low, int high)
{
    if(low > high)
    {
        return -1;
    }

    int mid = (low + high)/2;
    if(arr[mid] > arr[mid+1])
    {
        return mid;
    }

    // left half is sorted
    if(arr[low] <= arr[mid])
    {
        return searchPivot(arr, mid+1, high);
    }

    else // right half must be sorted
    {
        return searchPivot(arr, low, mid-1);
    }
}

int main()
{
    int arr[] = {4 , 8 , 9, 12, 15, 2}; // 4

    //int arr[] = {48, 2, 6, 9, 18, 26, 36, 40}; // 0

    // int arr[] = {2,4,5,6,8,9,10}; // 6

    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << searchPivot(arr, 0 , size-1);

    return 0;
}
