#include <iostream>
using namespace std;



int maximum_product_subarray(int *arr, int n)
{
    int maxVal = 1;
    int minVal = 1;
    int maxSoFar = 1;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > 0)
        {
            maxVal = max(maxVal * arr[i], 1);
            minVal = min(minVal * arr[i], 1);
        }
        else if(arr[i] == 0)
        {
            maxVal = 1;
            minVal = 1;
        }
        else
        {
            swap(maxVal,minVal);
            minVal = min(1, minVal * arr[i]);
            maxVal = max(1, maxVal * arr[i]);
        }
        if(maxSoFar < maxVal)
        {
            maxSoFar = maxVal;
        }
    }

    return maxSoFar;
}

int main()
{
    int arr[] = {1, -2, -3, 0, 7, -8, -2};
    int size = 7;
    int ans = maximum_product_subarray(arr, size);
    cout << ans << endl;
}
