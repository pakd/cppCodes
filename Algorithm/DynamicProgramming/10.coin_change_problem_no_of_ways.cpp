#include <iostream>
using namespace std;

int count(int *coin, int n, int amount)
{
    int dp[n+1][amount+1] = {0};


    for(int i=0; i<=amount; i++)
    {
        dp[0][i] = 0;
    }

    for(int i=0; i<=n; i++)
    {
        dp[i][0] = 1;
    }


    for(int i=1;i<=n;i++)
    {
        for(int j=1; j<=amount; j++)
        {
            if(coin[i-1] > j)
            {
                dp[i][j] = dp[i-1][j];
            }
            else
            {
                // no of ways by including current coin = dp[i][j-coin[i-1]] +
                // no of ways by not including current coin = dp[i-1][j];
                dp[i][j] =  dp[i][j-coin[i-1]] + dp[i-1][j];
            }
        }
    }
    return dp[n][amount];
}




int main()
{
    int arr[] = {1, 2, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int amount = 4;
    cout << count(arr, size, amount) << endl; // 4

    int arr2[] = {2,3,5,6};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);
    int amount2 = 10;
    cout << count(arr2, size2, amount2); // 5

    return 0;
}
