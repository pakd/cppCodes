#include <iostream>
#include <stack>
using namespace std;


int getMaxArea(int *hist, int n)
{
    stack<int> st;

    int max_area = 0;
    int curr_area = 0;

    int i=0;

    while(i < n)
    {
        // keep pushing if increasing.
        if(st.empty() || hist[st.top()] <= hist[i])
        {
            st.push(i++);
        }

        // calculate area while popping elem from stack
        else
        {
            int top = st.top();
            st.pop();

            curr_area = hist[top] * ( (st.empty())? i: i - st.top() - 1);

            max_area = max(max_area, curr_area);
        }
    }

    // calculate area for remaining elements in stack
    while(!st.empty())
    {
        int top = st.top();
        st.pop();

        curr_area = hist[top] * ((st.empty())? i: i - st.top() - 1);

        max_area = max(max_area, curr_area);
    }

    return max_area;
}

int main()
{
    int hist[] = {6, 2, 5, 4, 5, 1, 6};
    int n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
