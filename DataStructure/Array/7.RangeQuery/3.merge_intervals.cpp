#include <iostream>
#include <stack>
#include <algorithm>

struct Interval
{
    int start;
    int end;
};

bool compare(Interval A, Interval B)
{
    return (A.start < B.start);
}
void mergeIntervals(Interval *arr, int n)
{
    std::stack<Interval> st;

    std::sort(arr, arr + n, compare);

    st.push(arr[0]);

    for(int i=1; i<n; i++)
    {
        Interval topInterval = st.top();
        if(arr[i].start <= topInterval.end)
        {
            topInterval.end = std::max(arr[i].end, topInterval.end);
            st.pop();
            st.push(topInterval);
        }
        else
        {
            st.push(arr[i]);
        }
    }

    while (!st.empty())
    {
        Interval t = st.top();
        std::cout << "[" << t.start << "," << t.end << "] ";
        st.pop();
    }
}

int main()
{
    //Interval arr[] =  { {6,8}, {1,9}, {2,4}, {4,7} }; //test 1
    Interval arr[] =  { {2,4}, {5,7}, {8,10}, {9,15} }; // test 2
    int n = sizeof(arr)/sizeof(arr[0]);
    mergeIntervals(arr, n);
    return 0;
}
