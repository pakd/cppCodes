#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
stack<int> minSt;

void pushStack(int elem)
{
    st.push(elem);
    if(elem < minSt.top())
    {
        minSt.push(elem);
    }
}

int popStack()
{
    int temp = st.top();
    if(temp == minSt.top())
    {
        st.pop();
        minSt.pop();
    }
    else
    {
        st.pop();
    }
    return temp;
}

int getMin()
{
    if(!minSt.empty())
    {
        return minSt.top();
    }
    return -1;
}
int main()
{
    //int arr[] = {10, 20, 30, 5, 50};

    //pushStack(10);
    st.push(10);
    minSt.push(10);

    pushStack(20);
    pushStack(30);

    cout  << getMin() << endl; // 10

    pushStack(5);
    pushStack(50);

    cout  << getMin() << endl; // 5

    popStack();
    popStack();

    cout  << getMin() << endl; // 10

    popStack();
    popStack();
    popStack();

    cout  << getMin() << endl; // -1

    return 0;
}
