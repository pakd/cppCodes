#include <iostream>

using namespace std;

bool isSubsetSum(int *input, int n, int sum)
{
    bool dp[n+1][sum+1];

    for(int i=0;i<n;i++)
    {
        // by not including any element
        dp[i][0] = true;
    }

    for(int i=0;i<n;i++)
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

    return dp[n][sum];
}

int main()
{
  int arr[] = {3, 34, 4, 12, 5, 2};
  int sum = 9;
  int n = sizeof(arr)/sizeof(arr[0]);
  if (isSubsetSum(arr, n, sum) == true)
     printf("Found a subset with given sum");
  else
     printf("No subset with given sum");
  return 0;
}
