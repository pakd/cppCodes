#include <iostream>
#include <stack>

void findRightSmaller(int *arr, int n, int *rightSmaller)
{
    std::stack<int> st;
    for(int i=0; i<n; i++)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
        {
            int top = st.top();

            rightSmaller[top] = arr[i];
            st.pop();

        }
        st.push(i);
    }

    while(!st.empty())
    {
        rightSmaller[st.top()] = 0;
        st.pop();
    }
}

void findLeftSmaller(int *arr, int n, int *leftSmaller)
{
    std::stack<int> st;
    for(int i=n-1; i>=0; i--)
    {
        while(!st.empty() && arr[st.top()] > arr[i])
        {
            int top = st.top();

            leftSmaller[top] = arr[i];
            st.pop();

        }
        st.push(i);
    }

    while(!st.empty())
    {
        leftSmaller[st.top()] = 0;
        st.pop();
    }
}



int findMaxDiff(int *arr, int n)
{
    int *rightSmaller = new int[n];

    findRightSmaller(arr, n, rightSmaller);

    for(int i=0; i<n; i++)
    {
        std::cout << rightSmaller[i] << " ";
    }
    std::cout << std::endl;

    int *leftSmaller = new int[n];

    findLeftSmaller(arr, n, leftSmaller);

    for(int i=0; i<n; i++)
    {
        std::cout << leftSmaller[i] << " ";
    }
    std::cout << std::endl;


    int maxDiff  = 0;

    for(int i=0; i<n; i++)
    {
        maxDiff = std::max(maxDiff, abs(leftSmaller[i] - rightSmaller[i]));
    }

    return maxDiff;
}


int main()
{
    int arr[] = {2, 4, 8, 7, 7, 9, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Maximum diff :  "
              << findMaxDiff(arr, n) << std::endl;
    return 0;
}
