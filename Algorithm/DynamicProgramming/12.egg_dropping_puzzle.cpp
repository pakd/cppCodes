#include <iostream>
using namespace std;

int minWays(int n, int k)
{
    int dp[n+1][k+1] = {0};

    // filling first two rows
    for(int i=0; i<=k; i++)
    {
        // if 0 eggs, i floors , ways = 0
        dp[0][i] = 0;

        // if 1 egg, i floors, ways = i, start from bottom and go to top, brute force
        dp[1][i] = i;
    }

    // filling first two columns
    for(int i=2; i<=n; i++)
    {
        // if 0 floor, i eggs, ways = 0

        dp[i][0] = 0;

        // if 1 floor i eggs , ways = 1
        dp[i][1] = 1;
    }

    for(int i=2; i<=n; i++)
    {
        for(int j=2; j<=k; j++)
        {
            dp[i][j] = INT_MAX;
            for(int x = 1; x<=j; x++)
            {
                // if egg breaks at xth floor, we are left with n-1 eggs and x -1 floors = dp[i-1][j-1]
                // if egg doesnt break at xth floor, we are left with n eggs and k-x floors = dp[i][k-x]
                int ways = 1 + max(dp[i-1][x-1], dp[i][j-x]);
                dp[i][j] = min(ways, dp[i][j]);
            }
        }
    }

    // printing dp matrix
    /*for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=k; j++)
        {
            cout  << dp[i][j] << " ";
        }
        cout << endl;
    }*/

    return dp[n][k];
}


int main()
{
    int n_eggs = 2;
    int k_floors = 36; // ans = 8
    //int k_floors = 100; // ans = 14

    cout << minWays(n_eggs, k_floors);

    return 0;
}
