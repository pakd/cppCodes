#include <iostream>

using namespace std;

/* A utility function to check whether a word is present in dictionary or not.
  An array of strings is used for dictionary.  Using array of strings for
  dictionary is definitely not a good idea. We have used for simplicity of
  the program*/
int dictionaryContains(string word)
{
    string dictionary[] = {"mobile","samsung","sam","sung","man","mango",
                           "icecream","and","go","i","like","ice","cream"};
    int size = sizeof(dictionary)/sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
           return true;
    return false;
}


bool wordBreak(string str)
{
    int len = str.length();

    // in case of empty string
    if(len == 0)
        return true;

    // dp[i][j] contains substring(i to j)
    // true if in dictionary
    // else false
    bool dp[len][len];
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<len;j++)
        {
            dp[i][j] = false;
        }
    }

    // block size from 1 to len
    for(int blockSize = 1; blockSize <= len; blockSize++)
    {
        // for all substring of length = blockSize
        for(int i=0; i<len - blockSize + 1; i++)
        {
            int subStringEnd = i + blockSize - 1;

            string subString = str.substr(i, blockSize);

            if(dictionaryContains(subString))
            {
                dp[i][subStringEnd] = true;
            }
            else
            {

                // break word
                for(int k = i+1; k<=subStringEnd; k++)
                {
                    if(dp[i][k-1] && dp[k][subStringEnd])
                    {
                        dp[i][subStringEnd] = true;
                        break;
                    }
                }
            }
        }
    }

    return dp[0][len-1];
}


int main()
{
    wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n";
    wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n";
    wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilikeicecreamiiii")? cout <<"Yes\n": cout << "No\n";
    wordBreak("ilokeicecreamiiii")? cout <<"Yes\n": cout << "No\n";

    return 0;
}
