#include <iostream>
#include <stack>
#include <vector>

void next_greater_element(int *arr, int n)
{
    std::stack<int> st;
    std::vector<int> nge(n, -1);

    for(int i=0; i<n; i++)
    {
        if(st.empty())
        {
            st.push(i);
            continue;
        }

        while(!st.empty() && arr[i] > arr[st.top()])
        {
            nge[st.top()] = i;
            st.pop();
        }
        st.push(i);

    }
    while(!st.empty())
    {
        nge[st.top()] = -1;
        st.pop();
    }

    for(int i=0; i<n; i++)
    {
        if(nge[i] != -1)
        {
            std::cout << arr[i] << "\t" << arr[nge[i]] << std::endl;
        }
        else
        {
            std::cout << arr[i] << "\t" << -1 << std::endl;
        }
    }
}

int main()
{
    int arr[] = {5,3,2,10,6,8,1,4,12,7,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    next_greater_element(arr, size);
    return 0;
}
