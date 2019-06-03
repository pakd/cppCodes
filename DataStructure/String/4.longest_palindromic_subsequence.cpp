#include <iostream>

int longest_palindromic_subsequence(const std::string& test)
{
    int len = test.length();

    int dp[len][len];

    // base conditions
    for(int i=0; i<len; i++)
    {
        dp[i][i] = 1; // substring with one character is always palindrome
    }

    // substring with length 2
    for(int i=0; i<len-1; i++)
    {
        dp[i][i+1] = (test[i] == test[i+1])? 2 : 1;
    }

    for(int windowSize = 3; windowSize <= len; windowSize++)
    {
        for(int i=0; i<len-windowSize+1; i++)
        {
            int j = i + windowSize - 1;
            dp[i][j] = (test[i] == test[j])? 2 + dp[i+1][j-1]:std::max(dp[i+1][j],dp[i][j-1]);
        }
    }
    return dp[0][len-1];
}

int main()
{
    std::string test = "GEEKSFORGEEKS"; // 5 = EEKEE
    std::cout << longest_palindromic_subsequence(test);
    return 0;
}
