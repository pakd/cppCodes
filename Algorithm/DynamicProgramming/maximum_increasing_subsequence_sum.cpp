#include <iostream>
#include <vector>
using namespace std;

int maxIncreasingSubsequenceSum(int *arr, int n)
{
    vector <int> maxSum(arr, arr + n);

    for(int i=1; i<n; i++)
    {
        for (int j=0; j<i; j++)
        {
            if(arr[i] > arr[j])
            {
                maxSum[i] = max(maxSum[i], maxSum[j] + arr[i]);
            }
        }
    }
    //return maxSum[n-1];

    int maxElem = INT_MIN;
    for ( int i = 0; i < n; i++ )
    {
        if(maxSum[i] > maxElem)
        {
            maxElem =  maxSum[i];
        }

    }

    return maxElem;
}


int main()
{
    int arr[] = {1, 101, 2, 3, 100, 4, 5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << maxIncreasingSubsequenceSum(arr, n);
    return 0;
}
