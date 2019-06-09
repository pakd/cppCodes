#include <iostream>
#include <stack>
#include <vector>

std::string identifyParenthesis(std::string input)
{
    std::stack<int> st;


    int len = input.length();

    // -1 will increase the length of the input string
    // better to keep array of string
    std::vector<std::string> dpk(len, "");

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

    std::string ret = "";
    for(int  i=0;i<len; i++)
    {
        ret +=  dpk[i];
    }
    return ret;
}


int main()
{
    std::string str = "(a))";
    std::cout << identifyParenthesis(str) << std::endl;

    std::string str2 = "(((abc))((d)))))";
    std::cout << identifyParenthesis(str2) << std::endl;
    return 0;
}
