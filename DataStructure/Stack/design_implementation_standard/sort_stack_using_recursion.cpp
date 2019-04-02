#include <iostream>
#include <stack>
using namespace std;


stack <int> st;

// recursive function for putting elem in sorted order
void sortedInsert(int elem)
{
    if(st.empty() || st.top() < elem)
    {
        st.push(elem);
        return;
    }
    int temp = st.top();
    st.pop();

    sortedInsert(elem);

    st.push(temp);

}

// recursive function for putting all elements in call stack
void sortStack()
{
    if(st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    sortStack();

    sortedInsert(temp);

}

int main()
{
    st.push(30);
    st.push(-5);
    st.push(18);
    st.push(14);
    st.push(-3);

    sortStack();

    while(!st.empty())
    {
        cout << st.top() << "\t";
        st.pop();
    }

    return 0;
}
