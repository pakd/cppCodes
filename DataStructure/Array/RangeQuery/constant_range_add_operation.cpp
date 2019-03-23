#include <iostream>
using namespace std;

void add(int *arr, int n, int L, int R, int diff)
{
    arr[L] += diff;
    if(R != n-1)
    {
        arr[R + 1] -= diff;
    }
}

void update(int *arr, int n)
{
    for(int i=1; i<n; i++)
    {
        arr[i] += arr[i-1];
    }
}

void printArr(int *arr, int n)
{
    update(arr, n);
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int N = 6;

    int arr[N] = {0};

    //  Range add Queries
    add(arr, N, 0, 2, 100);
    add(arr, N, 1, 5, 100);
    add(arr, N, 2, 3, 100);

    printArr(arr, N);
    return 0;
}
