#include <iostream>
#include <stack>

bool check(int *arr, int n)
{
    int indexOfSecondArray = 1;

    std::stack<int> st;

    for(int i=0;i<n;i++)
    {
        // start printing in sorted order, if array element is already sorted
        if(arr[i] == indexOfSecondArray)
        {
            std::cout << "sorted: " << indexOfSecondArray << std::endl;
            indexOfSecondArray++;
        }
        else
        {
            if(st.empty())
            {
                st.push(arr[i]);
                continue;
            }

            // stack can be popped to maintain sorted order
            // pop and print
            while(!st.empty() && st.top() == indexOfSecondArray)
            {
                std::cout << "sorted: " << st.top() << std::endl;
                indexOfSecondArray++;
                st.pop();
            }
            // if we can maintain the reverse sorted order in stack
            if(!st.empty() && st.top() == arr[i] + 1)
            {
                st.push(arr[i]);
            }

            // if not return false
            else
            {
                return false;
            }
        }
    }

    while(!st.empty())
    {
        std::cout << "sorted: " << st.top() << std::endl;
        st.pop();
    }

    return true;
}


int main()
{
    int arr[] = { 4, 1, 2, 3 };  // yes
    // int arr[] = {2, 3, 1}; // no
    // int arr[] = {4, 5 , 2, 3, 6, 1}; // no
    int N = sizeof(arr) / sizeof(arr[0]);
    check(arr, N)? std::cout << "YES" : std::cout << "NO";
    return 0;
}
