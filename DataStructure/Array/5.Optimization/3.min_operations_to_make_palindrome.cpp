#include <iostream>

int findMinOps(int *arr, int n, int start, int end)
{
    if(start >= end)
    {
        return 0;
    }
    if(arr[start] == arr[end])
    {
        return findMinOps(arr, n , start + 1, end - 1);
    }
    if(arr[start] > arr[end])
    {
        end--;
        arr[end] = arr[end] + arr[end+1];
        return 1 + findMinOps(arr, n, start, end);
    }

    if(arr[start] < arr[end])
    {
        start++;
        arr[start] = arr[start] + arr[start-1];
        return 1 + findMinOps(arr, n, start, end);
    }
}

int main()
{
    int arr[] = {1, 4, 5, 1}; //   {15, 4, 15}; //   {11, 14, 15, 99};   // {1, 4, 5, 9, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Count of minimum operations is " <<  findMinOps(arr, n, 0, n-1);
    return 0;
}
