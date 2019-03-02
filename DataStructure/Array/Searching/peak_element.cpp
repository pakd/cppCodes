#include <iostream>
using namespace std;

int peak_element(int *arr, int low, int high, int n)
{
    int mid = (low + high)/2;

    // check if mid element is peak element or not
    if((arr[mid] >= arr[mid+1] || mid == n-1 ) && (arr[mid] >= arr[mid-1] || mid == 0) )
        return mid;

    // if arr[mid-1] > arr[mid] that means there will be atleast one peak element on left side
    // if it is sorted then last element if not then there is peak element
    else if( mid > 0 && arr[mid -1] > arr[mid] )
        return peak_element(arr, low, mid - 1, n);

    // there will be atleast one peak element on right side;
    else
        return peak_element(arr, mid+1, high, n);
    return -1;
}

int main()
{
    int arr[] = {10, 20, 15, 2, 23, 90, 67};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = peak_element(arr, 0, size - 1, size);
    if(index < 0)
    {
        cout << "not found";
        return 0;
    }
    cout << arr[index];
    return 0;

}
