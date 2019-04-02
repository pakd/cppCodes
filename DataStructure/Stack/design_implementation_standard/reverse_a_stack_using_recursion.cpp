#include <iostream>
#include <stack>
using namespace std;

stack <int> st;

void reverse_stack()
{
    if(st.empty())
    {
        return;
    }
    int temp = st.top();
    st.pop();
    reverse_stack();
    st.push(temp);

}
int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    reverse_stack();

    while(!st.empty())
    {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}
