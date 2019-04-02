#include <iostream>
#include <stack>
using namespace std;

stack<int> st;

void deleteMiddleElem(int sizeofStack, int n)
{
    if(st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    deleteMiddleElem(sizeofStack, n-1);

    if((sizeofStack/2) + 1 != n)
    {
        st.push(temp);
    }
}

int main()
{
    int i=1;
    st.push(i++);
    st.push(i++);
    st.push(i++);
    st.push(i++);
    st.push(i++);
    st.push(i++);
    st.push(i++);

    deleteMiddleElem( st.size(),  st.size());

    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;

}
