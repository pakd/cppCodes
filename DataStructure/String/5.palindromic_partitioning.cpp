#include <iostream>

bool isPalindrome(const std::string& s)
{
    int i = 0;
    int j = s.length()-1;

    while(i<j)
    {
        if(s[i] != s[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}

int minimum_cuts_for_palindromic_substring(const std::string& test)
{
    int len = test.length();

    int dp[len][len];

    // base conditions
    for(int i=0; i<len; i++)
    {
        dp[i][i] = 0; // substring with one character is always palindrome
    }

    // substring with length 2
    for(int i=0; i<len-1; i++)
    {
        dp[i][i+1] = (test[i] == test[i+1])? 0 : 1;
    }

    for(int windowSize = 3; windowSize <= len; windowSize++)
    {
        for(int i=0; i<len-windowSize+1; i++)
        {
            int j = i + windowSize - 1;
            if(isPalindrome(test.substr(i, windowSize)))
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = INT_MAX;
                for(int k = i; k<j; k++)
                {
                    dp[i][j] = std::min(dp[i][j], 1 + dp[i][k] + dp[k+1][j]);

                }
            }
        }
    }
    return dp[0][len-1];
}

int main()
{
    std::string test = "babababz"; // 3
    std::cout << minimum_cuts_for_palindromic_substring(test);
    return 0;
}
