#include <iostream>
using namespace std;

int partition(int *arr, int l, int r)
{
    int key = arr[r];
    int i = l-1;
    for(int j=l; j<r; j++)
    {
        if(arr[j]<=key)
        {
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1], arr[r]);
    return i+1;
}

// randomized partition for avoiding worst case
int randomPartition(int arr[], int l, int r)
{
    int n = r-l+1;
    int pivot = rand() % n;
    swap(arr[l + pivot], arr[r]);
    return partition(arr, l, r);
}

int quickSelect(int *arr, int L, int R, int k)
{
    // r - l + 1 = total no of elements
    if(k >0 && k <= R - L + 1)
    {
        // int pos = partition(arr, L, R); // using rightmost element for partition
        int pos = randomPartition( arr,  L,  R); //using randomized partition

        // if position is same as k
        if(  pos - L == k - 1)
            return arr[pos];
        else if(pos - L > k-1)
            return quickSelect(arr, L, pos-1, k);
        else
            return quickSelect(arr, pos+1, R, (k - 1) - (pos - L));
    }
    return INT_MAX;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 4, 19, 26};
    int n = sizeof(arr)/sizeof(arr[0]), k = 3;
    cout << "K'th smallest element is " << quickSelect(arr, 0, n-1, k);
    return 0;
}
