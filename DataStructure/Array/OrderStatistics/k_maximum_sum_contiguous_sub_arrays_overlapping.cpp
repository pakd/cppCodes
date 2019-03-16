#include <iostream>
#include <queue>
using namespace std;


// https://www.geeksforgeeks.org/k-maximum-sum-overlapping-contiguous-sub-arrays/
// https://www.geeksforgeeks.org/k-th-largest-sum-contiguous-subarray/
void kMaximumSums(int *arr, int n, int k)
{
    int prefixSum[n+1];
    prefixSum[0] = 0;
    prefixSum[1] = arr[0];
    for(int i=2;i<=n;i++)
    {
        prefixSum[i] = prefixSum[i-1] + arr[i-1];
    }

    // take min heap if we have to find k maximum - current case
    // take max heap if we have to find k minimum

    priority_queue<int, vector<int>, greater<int> > pq;

    for(int i=1; i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int x = prefixSum[j] - prefixSum[i-1];

            if(pq.size() < k)
            {
                pq.push(x);
            }
            else
            {
                if(pq.top() < x)
                {
                    pq.pop();
                    pq.push(x);
                }
            }
        }
    }

    int printArr[k];
    int i = k-1;
    while(!pq.empty())
    {
        printArr[i] = pq.top();
        i--;
        pq.pop();
    }

    for(int i=0;i<k;i++)
    {
        cout << i+1 << " " << printArr[i] << endl;
    }

}


int main()
{
    int arr[] = {4, -8, 9, -4, 1, -8, -1, 6}; int k = 4;
    //int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3}; int k = 3;
    int n = sizeof(arr) / sizeof(arr[0]);
    kMaximumSums(arr, n, k);
    return 0;
}
