#include <iostream>

std::pair<std::string, int> longest_palindromic_string(const std::string& test)
{
    int len = test.length();
    std::string ans = "";

    bool dp[len][len];

    int maxLen = 1;

    // base conditions
    for(int i=0; i<len; i++)
    {
        dp[i][i] = true; // substring with one character is always palindrome
    }

    // substring with length 2
    for(int i=0; i<len-1; i++)
    {
        dp[i][i+1] = (test[i] == test[i+1])? true : false;
        if(dp[i][i+1])
            maxLen = 2;
    }

    for(int windowSize = 3; windowSize <= len; windowSize++)
    {
        for(int i=0; i<len-windowSize+1; i++)
        {
            int j = i + windowSize - 1;
            dp[i][j] = (test[i] == test[j])? dp[i+1][j-1]:false;
            if(dp[i][j])
            {

                maxLen = windowSize;
                ans = test.substr(i, windowSize);
            }
        }
    }
    return make_pair(ans, maxLen);
}

int main()
{
    std::string test = "banana";
    std::pair<std::string, int> ans = longest_palindromic_string(test);
    std::cout << ans.first << "\t" << ans.second;
    return 0;
}
