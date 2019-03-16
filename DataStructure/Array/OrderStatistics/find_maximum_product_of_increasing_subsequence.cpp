#include <iostream>
#include <set>
using namespace std;

void maxProduct(int *arr, int n)
{
    int LSL[n]; // largest smaller on left
    int LGR[n]; // largest greater on right

    LSL[0] = -1;

    // current n^2 but can be done in nlogn
    // https://www.geeksforgeeks.org/increasing-subsequence-of-length-three-with-maximum-product/
    for(int i=1;i<n;i++)
    {
        int maxE = INT_MIN;
        for(int j=i-1; j >=0; j--)
        {

            if(arr[i] > arr[j] && arr[j] > maxE)
            {
                maxE = arr[j];
            }

        }
        LSL[i] = maxE;
    }

    LGR[n-1] = -1;

    for(int i=n-2;i>=0;i--)
    {
        LGR[i] = max(arr[i+1], LGR[i+1]);
    }

    int maxProd = INT_MIN;
    int left, right, mid;

    for(int i=0;i<n;i++)
    {
        int prod = LSL[i]*arr[i]*LGR[i];
        if(prod > maxProd && LSL[i] < arr[i] && arr[i] < LGR[i])
        {
            maxProd = prod;
            left = LSL[i];
            mid = arr[i];
            right = LGR[i];
        }
    }

    cout << left << " * " << mid << " * " << right <<" = " << maxProd;

}
int main()
{
    //int arr[] = {6, 7, 8, 1, 2, 3, 9, 10};
    int arr[] = {1, 5, 10, 8, 9};
    int size = sizeof(arr)/sizeof(arr[0]);
    maxProduct(arr, size);
    return 0;
}
