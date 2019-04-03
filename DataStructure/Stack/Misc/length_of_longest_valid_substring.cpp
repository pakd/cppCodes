#include <iostream>
#include <stack>
using namespace std;


int findMaxLen(string str)
{
    int n = str.length();

    int maxLen = -1;

    stack<int> st;

    // index where invalid substring ends
    st.push(-1);

    for(int i=0;i<n;i++)
    {
        char temp = str[i];

        // just insert index
        if(temp == '(')
        {
            st.push(i);
        }

        else
        {
            st.pop();

            // lenght of valid substring
            if(!st.empty())
            {
                maxLen = max(maxLen, i - st.top());
            }

            // push index where invalid substring ends
            else
            {
                st.push(i);
            }
        }
    }

    return maxLen;
}

int main()
{
    string str = "((()()";
    cout << findMaxLen(str) << endl;

    str = "()(()))))";
    cout << findMaxLen(str) << endl ;

    return 0;
}
