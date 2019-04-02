#include <iostream>
#include <stack>
using namespace std;

void next_greater(int *arr, int n, int *next)
{
    stack<int> st;

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

int countNGEs(int *arr, int *next, int *dp, int n)
{
    dp[n-1] = 0; // this won't trigger anytime as next[n-1] is always -1.
    for(int i= n - 2; i >=0 ; i--)
    {
        if(next[i] == -1)
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = 1 + dp[next[i]];
        }
    }
}

int main()
{
    int arr[] = {3, 4, 2, 7, 5, 8, 10, 6 };

    int size = sizeof(arr) / sizeof(arr[0]);

    int next[size] = {0};

    next_greater(arr, size , next);

    int *dp = new int[size];

    countNGEs(arr, next, dp, size);

    // query 1 answered
    cout << dp[3] << endl;

    // query 2 answered
    cout << dp[6] << endl;

    // query 3 answered
    cout << dp[1] << endl;

    return 0;
}
