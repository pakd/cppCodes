
#include <iostream>
using namespace std;

int ceiling_search(int *arr, int low, int high, int key)
{
    if(key <= arr[low])
        return low;
    if(key > arr[high])
        return -1;

    int mid = (low + high)/2;

    if(arr[mid] == key)
        return mid;

    else if(arr[mid] < key)
    {
        if( mid+1 <=high && key <= arr[mid+1]) // mid+1 <= high for sanity check
            return mid+1;
        return ceiling_search(arr, mid+1, high, key);

    }
    else
    {
        if( arr[mid-1] >=low && arr[mid-1] < key)
            return mid;
        return ceiling_search(arr, low, mid -1, key);

    }

}

int main()
{
    int arr[] = {1, 2, 8, 10, 10, 12, 19};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = ceiling_search(arr, 0, size - 1, 11);
    if(index < 0)
    {
        cout << "not present" ;
        return 0;
    }
    cout << arr[index];
    return 0;
}
