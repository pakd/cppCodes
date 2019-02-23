#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;



void form_minimum(string seq)
{
    stack<int> st;
    for(int i=0;i<=seq.length();i++)
    {

        st.push(i+1);
        if(i == seq.length() || seq[i] == 'I')
        {
            while(!st.empty())
            {
                cout << st.top() << "\t";
                st.pop();
            }
        }
    }
}

int main()
{
    string seq = "DDIDDIID";
    form_minimum(seq);
    return 0;
}
