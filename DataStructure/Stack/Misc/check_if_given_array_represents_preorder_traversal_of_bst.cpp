#include <iostream>
#include <stack>
using namespace std;

bool canRepresentBST(int *pre, int n)
{
    stack<int> st;
    int root = INT_MIN;

    for(int i=0;i<n;i++)
    {
        int temp = pre[i];

        if(temp < root)
            return false;

        while(!st.empty() && st.top() < temp)
        {
            root = st.top();
            st.pop();
        }
        st.push(temp);
    }
}

int main()
{

    int pre1[] = {40, 30, 35, 80, 100};
    int n = sizeof(pre1)/sizeof(pre1[0]);
    canRepresentBST(pre1, n)? cout << "true" << endl:
                              cout << "false" << endl;

    int pre2[] = {40, 30, 35, 20, 80, 100};
    n = sizeof(pre2)/sizeof(pre2[0]);
    canRepresentBST(pre2, n)? cout << "true" << endl:
                              cout << "false" << endl;

    return 0;
}
