#include <iostream>
#include <algorithm>
using namespace std;


int BinarySearch(int arr[],int left, int right, int key)
{
    if(right<left) return -1;
    else
    {
        int mid= (left+right)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) BinarySearch(arr,left,mid-1,key);
        else BinarySearch(arr,mid+1,right,key);
     }
}

int pairs_with_diff_k(int *arr, int n, int k)
{
    int count = 0;
    sort(arr, arr + n);
    for(int i=0;i<n;i++)
    {
        int temp = arr[i];
        int index = BinarySearch(arr, 0, n-1, temp + k);
        if(index!=-1)
        {
            cout << arr[i] << " " << arr[index] << endl;
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
    cout << pairs_with_diff_k(arr, size, k);

}
