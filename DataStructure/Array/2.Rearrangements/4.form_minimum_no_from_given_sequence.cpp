#include <iostream>
#include <stack>

void form_minimum(std::string seq)
{
    std::stack<int> st;
    for(int i=0;i<=seq.length();i++)
    {

        st.push(i+1);
        if(i == seq.length() || seq[i] == 'I')
        {
            while(!st.empty())
            {
                std::cout << st.top() << " ";
                st.pop();
            }
        }
    }
}

int main()
{
    std::string seq = "DDIDDIID";
    form_minimum(seq);

    return 0;
}
