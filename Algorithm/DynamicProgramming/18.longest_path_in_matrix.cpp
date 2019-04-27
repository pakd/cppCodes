#include <iostream>
using namespace std;

#define n 3

// this code follows top down approach

int findLongestFromACell(int i, int j, int mat[n][n], int dp[n][n])
{
    // base conditions
    // out of matrix
    if( i<0 || i>=n || j<0 || j>=n )
    {
        return 0;
    }

    // if sub-problem is already solved and stored
    if(dp[i][j] != -1)
    {
        return dp[i][j];
    }

    // left cell
    if( j>0 && (mat[i][j] + 1) == mat[i][j-1] )
    {
        return dp[i][j] = 1 + findLongestFromACell(i, j-1, mat, dp);
    }

    // right cell
    if( j<n-1 && (mat[i][j] + 1) == mat[i][j+1] )
    {
        return dp[i][j] = 1 + findLongestFromACell(i, j+1, mat, dp);
    }

    // top cell
    if( i>0 && (mat[i][j] + 1) == mat[i-1][j] )
    {
        return dp[i][j] = 1 + findLongestFromACell(i-1, j, mat, dp);
    }


    // bottom cell
    if( i<n-1 && (mat[i][j] + 1) == mat[i+1][j] )
    {
        return dp[i][j] = 1 + findLongestFromACell(i+1, j, mat, dp);
    }

    // if no neighbor cell
    // return 1
    return dp[i][j] = 1;
}

int findLongestOverAll(int mat[n][n])
{
    int result = 1;

    int dp[n][n];

    // memset(dp, -1, sizeof dp);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            dp[i][j] = -1;
        }
    }


    // find longest length for each cell
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(dp[i][j] == -1)
            {
                dp[i][j] = findLongestFromACell(i, j, mat, dp);

                result = max(dp[i][j], result);
            }
        }
    }

    return result;

}

int main()
{
   int  mat[n][n] = {{1, 2, 9},
                    {5, 3, 8},
                    {4, 6, 7}};
   cout << "Length of the longest path is "
        << findLongestOverAll(mat);
   return 0;
}
