#include <iostream>
using namespace std;
#define d 256 // char range
#define PRIME 101

void search(string text, string pat)
{
    int textLen = text.length();
    int patLen = pat.length();

    int  p = 0; // hash value of pattern
    int t = 0 ; // hash value of text

    // Calculate the hash value of pattern and first
    // window of text

    // The value of h would be "pow(d, M-1)%q"
    int h = 1;
    for (int i = 0; i < patLen - 1; i++)
    {
        h = (h * d) % PRIME;
    }

    for (int i=0; i < patLen; i++)
    {
        p = (d*p + pat[i])%PRIME;
        t = (d*t + text[i])%PRIME;
    }

    for(int i=0; i <= textLen - patLen; i++)
    {
        if(p == t)
        {
            int j = 0;
            for (j = 0; j < patLen; j++)
            {
                if (text[i+j] != pat[j])
                    break;
            }

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1]
            if (j == patLen)
            {
                cout << "Pattern found at index : " << i << endl;
            }

        }

        // Calculate hash value for next window of text: Remove
        // leading digit, add trailing digit
        if(i < textLen - patLen)
        {
            // hash( txt[s+1 .. s+m] ) = ( d ( hash( txt[s .. s+m-1]) – txt[s]*h ) + txt[s + m] ) mod q
            // lets assume t = 123;
            // 123 - (1)*(10^2) = 23 // (t - text[i]*h)
            // 23*10 = 230 // d*(t - text[i]*h)
            t = ( d*(t - text[i]*h) + text[i+patLen] )%PRIME;

            // We might get negative value of t, converting it
            // to positive
            if (t < 0)
            {
                t = t + PRIME;
            }
        }
    }

}

int main()
{
    string text = "GEEKS FOR GEEKS";
    string pat = "GEEK";

    search(text, pat);

    return 0;
}
