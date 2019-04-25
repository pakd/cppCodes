#include <iostream>
using namespace std;


void printScore(int *arr, int n)
{
    pair<int, int> dp[n][n];

    // put base conditions
    // if one element then score of first is that element
    // second = 0
    for(int i=0; i<n; i++)
    {
        dp[i][i] = { arr[i], 0 };
    }

    for(int blockSize = 2; blockSize <= n; blockSize++)
    {
        // for all substring of length = blockSize
        for(int i=0; i< n - blockSize + 1; i++)
        {
            int j = i + blockSize - 1;

            // profit of seconds become profit of first
            // profit of first + new arr item selection
            if(arr[i] + dp[i+1][j].second > arr[j] + dp[i][j-1].second)
            {
                dp[i][j].first = arr[i] + dp[i+1][j].second;
                dp[i][j].second = dp[i+1][j].first;
            }
            else
            {
                dp[i][j].first = arr[j] + dp[i][j-1].second;
                dp[i][j].second = dp[i][j-1].first;

            }

        }
    }

    cout << dp[0][n-1].first << " " << dp[0][n-1].second <<  endl;
}

int main()
{
    int arr[] = {8, 15, 3, 7};
    int size = sizeof(arr)/sizeof(arr[0]);

    printScore(arr, size);

    return 0;

}
