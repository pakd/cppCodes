#include <iostream>
using namespace std;

int segregate (int *arr, int n)
{
    int index=0;
    for(int j=0; j <n; j++)
    {
        if(arr[j] < 0)
        {
            swap(arr[index], arr[j]);
            index++;
        }
    }

    return index;
}

int findMissing(int *arr, int n)
{
    for(int i=0;i<n; i++)
    {
        // -1 because array should start from 1 not 0
        if( abs(arr[i]) -1 < n && arr[abs(arr[i]) -1] > 0 )
        {
            arr[abs(arr[i]) -1] = -arr[abs(arr[i])-1];
        }
    }

    for(int i = 0; i < n; i++)
    {
        if (arr[i] > 0)
        // 1 is added because indexes start from 0
        return i+1;
    }

}



int main()
{
    int arr[] = { 2, 3, -7, 6, 8, 1, -10, 15 };
    int arr_size = sizeof(arr)/sizeof(arr[0]);
    int index=segregate (arr,  arr_size);

    cout << findMissing(arr + index,  arr_size - index);
    return 0;

}
