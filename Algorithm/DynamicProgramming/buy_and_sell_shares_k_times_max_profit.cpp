#include <iostream>
using namespace std;


int maxProfit(int *price, int n, int k)
{
    // table to store results of subproblems
    // profit[t][i] stores maximum profit using
    // atmost t transactions up to day i (including
    // day i)
    int profit[k + 1][n];

    // For day 0, you can't earn money
    // irrespective of how many times you trade
    for (int i = 0; i <= k; i++)
        profit[i][0] = 0;

    // profit is 0 if we don't do any transation
    // (i.e. k =0)
    for (int j = 0; j < n; j++)
        profit[0][j] = 0;


    for(int i=1;i<=k; i++)
    {
        for(int j=1;j<n;j++)
        {
            int max_so_far = INT_MIN;

            for(int m=0;m<j;m++)
            {

                if(price[m] < price[j])
                {
                    // profit[i][j-1] : doing no transaction on jth day, so profit of previous day
                    // dp[i-1][m] + price[j] - price[m]: bought on mth day with one less transaction : take max
                    max_so_far = max(max_so_far, profit[i-1][m] + price[j] - price[m]);
                }
            }

            profit[i][j] = max(max_so_far, profit[i][j-1]);
        }
    }

    return profit[k][n-1];
}


int main()
{
    int k = 2;
    int price[] = { 10, 22, 5, 75, 65, 80 };
    int n = sizeof(price) / sizeof(price[0]);

    cout << "Maximum profit is: " << maxProfit(price, n, k);

    return 0;
}
