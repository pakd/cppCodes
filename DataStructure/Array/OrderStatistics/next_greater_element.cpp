#include <iostream>
#include <stack>
#include <unordered_map>
using namespace std;

void next_greater_element(int *arr, int n)
{
    stack<int> st;
    unordered_map<int, int> m;
    st.push(arr[0]);
    int i = 0;
    while(i<n)
    {
        int temp = arr[i];
        if(temp < st.top())
        {
            st.push(temp);
            i++;
        }
        else
        {
            while(!st.empty() && temp > st.top())
            {
                cout << st.top() << " " << temp << endl;
                m[st.top()] = temp;
                st.pop();
            }
            st.push(temp);
            i++;
        }
    }
    while(!st.empty())
    {
        cout << st.top() << " " << -1 << endl;

        m[st.top()] = -1;
        st.pop();
    }

    // if elements are distinct
    /*for(auto it=m.begin(); it!=m.end();it++)
    {
        cout  << it->first << "\t" << it->second << endl;
    }*/
}

int main()
{
    int arr[] = {5,3,2,10,6,8,1,4,12,7,4};
    int size = sizeof(arr)/sizeof(arr[0]);
    next_greater_element(arr, size);
    return 0;
}
