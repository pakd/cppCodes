#include <iostream>

// Query : O(1)
// update: O(n)
int sumQuery(int *arr, int n, int L, int R)
{
    int sum[n];
    sum[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        sum[i] = sum[i-1] + arr[i];
    }
    if(L == 0)
    {
        return sum[R];
    }
    return sum[R] - sum[L - 1];
}

int main()
{
    int arr[] = {4,5,8,9,6,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    std::cout << sumQuery(arr, size, 0 , 3  );
    return 0;
}
