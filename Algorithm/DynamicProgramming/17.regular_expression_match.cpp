#include <iostream>

using namespace std;


bool regexMatch(string str, string pattern)
{
    int strLen = str.length();
    int patLen = pattern.length();


    bool dp[strLen + 1][patLen + 1];


    // matching two empty strings
    dp[0][0] = true;

    // matching empty string with non empty string
    for(int i=1; i <=strLen; i++)
    {
        dp[i][0] = false;
    }

    // matching empty string with non empty string
    for(int i=1; i <=patLen; i++)
    {
        dp[0][i] = false;
    }

    // take care of pattern like this a*, a*b* and so on
    /*
    for(int i=1; i <=patLen; i++)
    {
        dp[0][i] = dp[i][j-2];
    }
    */

    for(int i=1; i<=strLen; i++)
    {
        for(int j=1; j <=patLen; j++)
        {
            // removing the ith char form string and jth char from pattern
            // then check if string equals pattern or not
            if(str[i-1] == pattern[j-1] || pattern[j-1] == '.')
            {
                dp[i][j] = dp[i-1][j-1];
            }

            else if(pattern[j-1] == '*')
            {
                // sample pattern = "ba*"
                // checking 0 occurrences of a
                dp[i][j] = dp[i][j-2];

                // checking more than 0 occurrences of pattern with 'x*'
                // or '.' which can hold any char
                if( pattern[j-2] == str[i-1] || pattern[j-2] == '.')
                {
                    dp[i][j] = dp[i][j] | dp[i-1][j];
                }


            }
            else
            {
                dp[i][j] = false;
            }
        }
    }

    return dp[strLen][patLen];
}

int main()
{
    string str = "xaabyc"; // match
    //string str = "xababyc"; // do not match
    string pattern = "xa*b.c";

    regexMatch(str, pattern)? cout << "pattern and string matched": cout << "pattern and string do not match";

    return 0;
}
