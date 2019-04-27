#include <iostream>
using namespace std;

MatrixChainOrder(pair<int, int> *arr, int n)
{
    int dp[n][n] = {0};

    // cost of multiplication for a single matrix
    for(int i=0; i<n; i++)
    {
        dp[i][i] = 0;
    }

    for(int blockSize = 2; blockSize <=n ; blockSize++)
    {
        // first matrix is 0,1 of array elements
        for(int i=0; i < n - blockSize + 1; i++)
        {
            int j = i + blockSize - 1;

            dp[i][j] = INT_MAX;

            for(int k=i; k<j; k++)
            {
                int temp = dp[i][k] + dp[k+1][j] + (arr[i].first * arr[k].second * arr[j].second);
                dp[i][j] = min(dp[i][j], temp);
            }
        }
    }

    for(int i = 0; i < n ; i++)
    {
        for(int j=0; j < n; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;


    return dp[0][n-1];
}

int main()
{
    pair<int, int> arr[3];
    arr[0] = {1,2};
    arr[1] = {2,3};
    arr[2] = {3,4}; // ans = 18

    /*pair<int, int> arr[4];
    arr[0] = {40,20};
    arr[1] = {20,30};
    arr[2] = {30,10};
    arr[3] = {10,30}; // ans = 26000 */



    int size = sizeof(arr)/sizeof(arr[0]);


    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, size);

    return 0;
}
