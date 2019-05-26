#include <iostream>
#include <algorithm>

int BinarySearch(int arr[],int left, int right, int key)
{
    if(left>right)
        return -1;

    int mid= (left+right)/2;
    if(arr[mid]==key)
        return mid;

    else if(arr[mid]>key)
        BinarySearch(arr,left,mid-1,key);

    else
        BinarySearch(arr,mid+1,right,key);

}

int pairs_with_diff_k(int *arr, int n, int k)
{
    int count = 0;
    std::sort(arr, arr + n);
    for(int i=0; i<n; i++)
    {
        int index = BinarySearch(arr, i+1, n-1, arr[i] + k);
        if(index!=-1)
        {
            std::cout << arr[i] << " " << arr[index] << std::endl;
            count++;
        }
    }
    return count;
}


int main()
{
    int arr[] = {8, 12, 16, 4, 0, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    int k = 4;
    std::cout << pairs_with_diff_k(arr, size, k);
    return 0;
}
