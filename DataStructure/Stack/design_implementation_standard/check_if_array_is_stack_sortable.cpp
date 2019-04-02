#include <iostream>
#include <stack>
using namespace std;


bool check(int *arr, int n)
{
    int indexOfSecondArray = 1;

    stack<int> st;

    for(int i=0;i<n;i++)
    {
        // start printing in sorted order, if array element is already sorted
        if(arr[i] == indexOfSecondArray)
        {
            cout << "sorted: " << indexOfSecondArray << endl;
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
                cout << "sorted: " << st.top() << endl;
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
        cout << "sorted: " << st.top() << endl;
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
    check(arr, N)? cout<<"YES": cout<<"NO";
    return 0;
}
