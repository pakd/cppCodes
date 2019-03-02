
#include <iostream>
using namespace std;

int fixed_element(int *arr, int low, int high)
{
    if(low > high)
        return -1;
    int mid = (low+ high)/2;
    if(arr[mid] == mid)
        return mid;
    else if(arr[mid] > mid)
    {
        return fixed_element(arr, low, mid - 1);
    }
    else
    {
        return fixed_element(arr, mid + 1, high);
    }
    return -1;
}

int main()
{
    int arr[] = {-12,-3,-2,3,14,20};
    //int arr[] = {5,6,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int index = fixed_element(arr, 0, size - 1);
    if(index < 0)
    {
        cout << "not present" ;
        return 0;
    }
    cout << arr[index];
    return 0;
}
