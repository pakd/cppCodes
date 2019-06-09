#include <iostream>
#include <stack>

void next_greater(int *arr, int n, int *next)
{
    std::stack<int> st;

    st.push(0);

    for(int i=1; i<n; i++)
    {
        while(!st.empty() && arr[st.top()] < arr[i])
        {
            next[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while(!st.empty())
    {
        next[st.top()] = -1;
        st.pop();
    }
}

int answer_query(int *arr, int *next, int index)
{
    if(next[index]!=-1)
    {
        return arr[next[index]];
    }
    return -1;
}

int main()
{
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6 };

    int size = sizeof(arr) / sizeof(arr[0]);

    int next[size] = {0};

    next_greater(arr, size , next);

    // query 1 answered
    std::cout << answer_query(arr, next, 3) << std::endl;

    // query 2 answered
    std::cout << answer_query(arr, next, 6) << std::endl;

    // query 3 answered
    std::cout << answer_query(arr, next, 1) << std::endl;

    return 0;
}
