#include <iostream>
using namespace std;

int cutRod(int *profit, int n, int rodLength)
{
    int dp[n+1][rodLength+1] = {0};

    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }

    for(int i=0; i<=rodLength; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=rodLength; j++)
        {
            if(i > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                // if not including current piece :- dp[i-1][j]
                // if including the current piece :- dp[i - j][j]
                dp[i][j] = max(dp[i-1][j], profit[i -1] + dp[i][j-i] );
            }
        }

    }
    return dp[n][rodLength];
}




int main()
{
    int arr[] = {1, 5, 8, 9, 10, 17, 17, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << cutRod(arr, size, 8);
    return 0;
}
