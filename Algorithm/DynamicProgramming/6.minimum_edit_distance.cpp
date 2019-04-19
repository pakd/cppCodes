#include <iostream>
using namespace std;


int editDistDP(string in, string out, int inLen, int outLen)
{
    int dp[inLen+1][outLen+1] = {0};

    for(int i=0;i<=inLen;i++)
    {
        for(int j=0;j<=outLen;j++)
        {
            // insert operation
            if(i == 0)
            {
                dp[i][j] = j;
            }

            // remove operation
            else if(j == 0)
            {
                dp[i][j] = i;
            }

            // same char, then no operation required
            else if(in[i-1] == out[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }

            // if not same char, then minimum of (top, left, left_top) + 1
            else
            {
                dp[i][j] = 1 + min(dp[i-1][j-1], // replace
                                    min(dp[i][j-1], // insert
                                         dp[i-1][j])); // remove
            }
        }
    }
    return dp[inLen][outLen];
}

int main()
{
    string str1 = "sunday";
    string str2 = "saturday";

    cout << editDistDP(str1, str2, str1.length(), str2.length());

    return 0;
}
