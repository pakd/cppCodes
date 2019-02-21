#include <iostream>
using namespace std;

void searchPivot(int *arr, int l, int r)
{
    if(l == r)
    {
        cout << l;
        return;

    }
    int m = (l+r)/2;
    if(arr[m] > arr[m+1])
    {
        cout << m;
        return;
    }
    if(arr[m] < arr[l])
    {
        searchPivot(arr, l, m-1);
    }
    else
    {
        searchPivot(arr, m+1, r);
    }
}

int main()
{
    int arr[] = {4 , 8 , 9, 12 , 15, 2};
    searchPivot(arr, 0 , 5);
}
