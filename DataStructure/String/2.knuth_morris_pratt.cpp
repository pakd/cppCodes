#include <iostream>
using namespace std;


void computeLPS(string pat, int *lps, int patLen);


void KMPSearch(string text, string pat)
{
    int patLen = pat.length();
    int textLen = text.length();

    int *lps = new int[patLen];
    computeLPS(pat, lps, patLen);

    for(int i=0;i<patLen; i++)
    {
        cout << lps[i] << " ";
    }
    cout << endl;

    int i = 0; // for text
    int j = 0; // for pattern

    while(i < textLen)
    {
        if(text[i] == pat[j])
        {
            i++;
            j++;
        }

        if( j == patLen)
        {
            cout << "pattern found at " << i - patLen;
            j = lps[j-1]; // skip the longest prefix till now
        }

        else if( i < textLen && text[i] != pat[j])
        {
            if(j != 0)
            {
                j = lps[j-1]; // pattern found or not always skip the longest prefix till this index
            }
            else
            {
                i++;
            }
        }
    }
}

// longest prefix which is also a suffix for e.g aaa = 2(aa), aba = 1(a)
void computeLPS(string pat, int *lps, int patLen)
{
    lps[0] = 0;

    int i = 1;
    int j = 0;

    while(i < patLen)
    {
        if(pat[i] == pat[j])
        {
            lps[i] = j + 1;
            i++;
            j++;
        }
        else // pat[i] != pat[j]
        {
            // if not matching, you check with the previous char
            // or learn it
            if(j != 0)
            {
                j = lps[j-1]; // skip the prefix
            }
            else // j == 0
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


int main()
{
    string text = "ABABDABACDABABCABAB";
    string pat = "ABABCABAB";
    KMPSearch(text, pat);
    return 0;
}
