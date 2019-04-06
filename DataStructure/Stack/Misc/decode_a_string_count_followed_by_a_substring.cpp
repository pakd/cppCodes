#include <iostream>
#include <stack>
using namespace std;

string decode(string input)
{
    string ret = "";

    stack<int> intSt;
    stack<char> charSt;

    int len = input.length();

    for(int i=0; i<len; i++)
    {
        char t = input[i];

        if( t >= '0' && t <= '9')
        {
            intSt.push(t - '0');
        }

        else if(t  == '[')
        {
            charSt.push(t);
        }

        else if(t == ']')
        {
            string temp = "";
            while(charSt.top() != '[')
            {
                temp += charSt.top();
                charSt.pop();
            }

            charSt.pop();
            int count = intSt.top();
            intSt.pop();

            for(int i=0; i<count; i++)
            {
                for(int j=temp.length()-1; j>=0; j--)
                {
                    charSt.push(temp[j]);
                }
            }
        }
        else
        {
            charSt.push(t);
        }
    }



    while(!charSt.empty())
    {
        ret = charSt.top() + ret;
        charSt.pop();
    }

    return ret;

}



int main()
{
    string str = "3[b2[ca]]";
    cout << decode(str) << endl;

    string str2 = "2[a2[b]]";
    cout << decode(str2) << endl;

    return 0;
}
