#include <iostream>
#include <stack>

int findMaxLen(std::string str)
{
    int n = str.length();

    int maxLen = -1;

    std::stack<int> st;

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
                maxLen = std::max(maxLen, i - st.top());
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
    std::string str = "((()()";
    std::cout << findMaxLen(str) << std::endl;

    str = "()(()))))";
    std::cout << findMaxLen(str) << std::endl ;

    return 0;
}
