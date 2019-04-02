#include <iostream>
#include <stack>
using namespace std;

stack<int> st;
int minElem = INT_MAX;

void pushStack(int x)
{
    if(x < minElem)
    {
        st.push(2*x - minElem);
        minElem = x;
    }
    else
    {
        st.push(x);
    }
}

int popStack()
{
    int temp = st.top();

    int oldMinElem = minElem;
    if(temp < minElem)
    {
        minElem = 2*minElem - temp;
        st.pop();
    }
    else
    {
        st.pop();
    }
    return oldMinElem;
}

int getMin()
{
    if(!st.empty())
    {
        return minElem;
    }
    return INT_MAX;

}
int main()
{
    //int arr[] = {10, 20, 30, 5, 50};

    //pushStack(10);
    st.push(10);
    minElem = 10;

    pushStack(20);
    pushStack(30);

    cout  << getMin() << endl; // 10

    pushStack(5);
    pushStack(50);

    cout  << getMin() << endl; // 5

    popStack();

    // cout << st.top(); // 2*x - minElem;
    popStack();
    //cout << "popstack value:" << popStack() << endl;

    cout  << getMin() << endl; // 10

    popStack();
    popStack();
    popStack();

    cout  << getMin() << endl; // INT_MAX

    return 0;
}
