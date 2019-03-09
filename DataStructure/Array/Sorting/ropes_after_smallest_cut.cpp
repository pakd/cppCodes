#include <iostream>
#include <algorithm>
using namespace std;




void ropes_after_smallest_cut(int *arr, int n)
{
    sort(arr, arr + n);
    int cuttingLength = arr[0];

    for(int i=1;i<n;i++)
    {
        if(arr[i] - cuttingLength > 0)
        {
            cuttingLength = arr[i];
            cout << n - i << " ";
        }
    }

}


int main()
{
    int arr[] = {5, 1, 6, 9, 8, 11, 2, 2, 6, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    ropes_after_smallest_cut(arr, size);
    return 0;
}
