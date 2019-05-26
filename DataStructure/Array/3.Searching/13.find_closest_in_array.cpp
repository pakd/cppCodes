#include <iostream>
#include <cmath>

int getClosest(int *arr, int key, int first, int second)
{
    if(abs( key - arr[first]) <= abs(key - arr[second]))
        return first;
    else
        return second;
}
int findClosest(int *arr, int low, int high, int key)
{
    if(key <= arr[low])
        return low;
    if(key > arr[high])
        return high;

    int mid = (low + high)/2;

    if(arr[mid] == key)
        return mid;

    else if(arr[mid] < key)
    {
        if( mid+1 <= high && key <= arr[mid+1]) // mid+1 <= high for sanity check
        {
            return getClosest(arr, key, mid, mid+1);
        }
        return findClosest(arr, mid+1, high, key);
    }
    else
    {
        if( arr[mid-1] >=low && arr[mid-1] < key)
        {
            return getClosest(arr, key, mid, mid-1);
        }
        return findClosest(arr, low, mid -1, key);
    }
}

int main()
{
    //int arr[] = {2, 5, 6, 7, 8, 8, 9};
    int arr[] = {2, 5, 8, 11, 18, 25};
    int key = 6;
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = findClosest(arr, 0, size - 1, key);
    if(index < 0)
    {
        std::cout << "not present" ;
        return 0;
    }
    std::cout << arr[index];
    return 0;
}
