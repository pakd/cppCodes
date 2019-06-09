#include <iostream>
#include <stack>

std::stack <int> st;
void insertAtBottom(int temp);

void reverse_stack()
{
    if(st.empty())
    {
        return;
    }

    int temp = st.top();
    st.pop();

    reverse_stack();

    insertAtBottom(temp);

}


void insertAtBottom(int temp)
{
    if(st.empty())
    {
        st.push(temp);
        return;
    }
    int top = st.top();
    st.pop();

    insertAtBottom(temp);

    st.push(top);
}

int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // 1 2 3 4 <-top

    reverse_stack();

    while(!st.empty())
    {
        std::cout << st.top() << " "; // 4 3 2 1 <-top
        st.pop();
    }
    return 0;
}
