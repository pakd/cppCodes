#include<iostream>

using namespace std;

int knapSack(int W, int *wt, int *val, int n)
{
    int dp[n+1][W+1] = {0};

    // base conditions
    for(int i=0; i<=W; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 0;
    }


    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=W; j++)
        {
            // without including the item
            if( j < wt[i-1])
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                dp[i][j] = max(dp[i-1][j], val[i-1] + dp[i-1][j - wt[i-1]] );
            }
        }
    }

    return dp[n][W];

}



int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int  W = 50;
    int n = sizeof(val)/sizeof(val[0]);
    cout << knapSack(W, wt, val, n);
    return 0;
}
