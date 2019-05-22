#include<iostream>
int BinarySearch(int arr[],int left, int right, int key)
{
    if(left > right) return -1;

    int mid = (left + right)/2;

    if(arr[mid] == key)
    {
        return mid;
    }

    else if(arr[mid] > key)
    {
        return BinarySearch(arr, left, mid-1, key);
    }

    else
    {
        return BinarySearch(arr, mid+1, right, key);
    }
}
int main()
{
    int arr[]={3,6,9,10,23,45,56,67,89};
    std::cout << BinarySearch(arr,0,8,10);
    return 0;
}
