#include <iostream>
#include <deque>

int printKMax(int *arr, int n, int k)
{
    std::deque<int> dq;
    int i=0;
    for(i=0;i<k;i++)
    {
        // remove all smaller elements
        while( !dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }


    for( ; i<n ; i++)
    {
        std::cout  << arr[dq.front()] << "\t";

        // remove all elements from older windows
        while(!dq.empty() && dq.front() <= i-k)
        {
            dq.pop_front();
        }

        // remove all smaller elements
        while( !dq.empty() && arr[i] >= arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    std::cout << arr[dq.front()] << "\t";
}

int main()
{
    int arr[] = {12, 1, 78, 90, 57, 89, 56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    printKMax(arr, n, k);
    return 0;
}
