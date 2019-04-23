#include <iostream>

using namespace std;

int findMinDiff(int *input, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        sum += input[i];
    }

    bool dp[n+1][sum+1];

    for(int i=0; i<=n; i++)
    {
        // by not including any element
        dp[i][0] = true;
    }

    for(int i=1; i<=sum; i++)
    {
        // impossible to find any given sum by not choosing any element
        dp[0][i] = false;
    }

    for(int i=1; i<=n; i++)
    {
        for(int j=1;j<=sum; j++)
        {
            // take from above cell
            if(j < input[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }

            // above cell, go input[i-1] times left
            else
            {
                dp[i][j] = dp[i-1][j] || dp[i-1][j - input[i-1]];
            }
        }
    }

    int diff = INT_MAX;

    for(int j=sum/2; j>=0; j--)
    {
        if(dp[n][j])
        {
            diff = sum-2*j;
            break;
        }
    }

    return diff;
}

int main()
{
  int arr[] = {3, 1, 4, 2, 2, 1}; // ans = 1
  // int arr[] = {11, 4, 4}; // ans = 3
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << "The minimum difference between 2 sets is " << findMinDiff(arr, n);
  return 0;
}
