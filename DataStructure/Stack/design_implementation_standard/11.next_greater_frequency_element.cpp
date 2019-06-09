#include <iostream>
#include <stack>
#include <unordered_map>


void next_greater(int *arr, int n, int *next)
{
    std::stack<int> st;
    std::unordered_map<int, int> m;

    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }

    st.push(0);

    for(int i=1; i<n; i++)
    {
        // no need to check if exist in map or not
        // as we have already pushed all elem in map
        while(!st.empty() && m[arr[st.top()]] < m[arr[i]])
        {
            next[st.top()] = arr[i];
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

int printNextArray( int *next, int n)
{
    for(int i=0; i < n; i++)
    {
        std::cout << next[i] << " ";
    }
}

int main()
{
    int arr[] = {1, 1, 2, 3, 4, 2, 1};

    int size = sizeof(arr) / sizeof(arr[0]);

    int next[size] = {0};

    next_greater(arr, size , next);

    printNextArray(next, size);

    return 0;
}
