#include <iostream>
#include <algorithm>
using namespace std;

//greedy approach
int getMinDiff(int *arr, int n, int k)
{

    sort(arr, arr + n);

    int small = arr[0] + k;
    int big = arr[n-1] - k;
    int minDiff = arr[n-1] - arr[0];

    if(small > big)
    {
        swap(small, big);
    }

    for(int i=1; i<n-1 ;i++)
    {
        int add = arr[i] + k;
        int sub = arr[i] - k;

        // if new heights are in range: small < (add, sub) < big
        if( sub >= small || add <= big )
        {
            continue;
        }

        else
        {
            if( add - small < big - sub) // choosing add as new big
            {
                big = add;
            }
            else // choosing sub as new small
            {
                small = sub;
            }
        }
    }

    return min(big - small, minDiff) ;
}


int main()
{
    int arr[] = {1, 5, 15, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 3;
    cout << "Maximum difference is "
        << getMinDiff(arr, n, k);
    return 0;
}
