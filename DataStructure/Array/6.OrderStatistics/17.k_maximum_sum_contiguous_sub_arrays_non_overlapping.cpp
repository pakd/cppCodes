#include <iostream>
#include <queue>

struct Node
{
    int sum;
    int lIndex;
    int rIndex;
};

Node kadanes(int *arr, int n)
{
    int curr_max = 0;
    int max_so_far = INT_MIN;
    int bestLeftIndex = 0;
    int bestRightIndex = 0;
    int s = 0;

    for(int i=0; i<n; i++)
    {
        curr_max += arr[i];

        if(max_so_far < curr_max)
        {
            max_so_far = curr_max;
            bestLeftIndex = s;
            bestRightIndex = i;
        }

        if(curr_max < 0)
        {
            curr_max = 0;

            // point s to next index
            s = i+1;
        }
    }
    Node temp;
    temp.sum = max_so_far;
    temp.lIndex = bestLeftIndex;
    temp.rIndex = bestRightIndex;

    return temp;
}

void kMaximumSums(int *arr, int n, int k)
{

    for(int i=0;i<k;i++)
    {
        Node temp = kadanes(arr, n);

        std::cout << temp.lIndex << " -> " << temp.rIndex << " sum: " << temp.sum << std::endl;

        for(int i=temp.lIndex ; i<=temp.rIndex; i++)
        {
            arr[i] = INT_MIN;
        }
        // last iteration of this is unnecessary
    }

}


int main()
{
    int arr[] = {4, 1, 1, -1, -3, -5, 6, 2, -6, -2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    kMaximumSums(arr, n, k);

    return 0;
}
