#include <iostream>
#include <stack>
#include <vector>
using namespace std;

string identifyParenthesis(string input)
{
    stack<int> st;


    int len = input.length();

    // -1 will increase the length of the input string
    // better to keep array of string
    vector<string> dpk(len, "");

    for(int i=0; i<len; i++)
    {
        char t = input[i];

        if(t == '(')
        {
            st.push(i);
        }
        else if(t == ')')
        {
            if(!st.empty())
            {
                //input.replace(st.top(), 1, "0");
                dpk[st.top()] = "0";
                //input.replace(i, 1, "1");
                dpk[i] = "1";
                st.pop();
            }
            else
            {
                //input.replace(i, 1, "-1");
                dpk[i] = "-1";
            }
        }
        else
        {
            dpk[i] = t;
        }
    }

    while(!st.empty())
    {
        //input.replace(st.top(), 1, "-1");
        dpk[st.top()] = "-1";

        st.pop();
    }

    string ret = "";
    for(int  i=0;i<len; i++)
    {
        ret +=  dpk[i];
    }
    return ret;
}


int main()
{
    string str = "(a))";
    cout << identifyParenthesis(str) << endl;

    string str2 = "(((abc))((d)))))";
    cout << identifyParenthesis(str2) << endl;
    return 0;
}
