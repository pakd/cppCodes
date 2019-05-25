#include <iostream>

int maximum_product_subarray(int *arr, int n)
{
    int maxVal = 1;
    int minVal = 1;
    int maxSoFar = 1;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > 0)
        {
            maxVal = maxVal * arr[i];
            minVal = minVal * arr[i];
        }
        else if(arr[i] == 0)
        {
            maxVal = 1;
            minVal = 1;
        }
        else
        {
            int temp = maxVal;
            maxVal =  minVal * arr[i];
            minVal = temp * arr[i];
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
    int arr[] = {1, -2, -3, 0, 7, -8, -2}; // 112
    // int  arr[] = {6, -3, -10, 0, 2}; // 180
    // int arr[] = {-1, -3, -10, 0, 60}; // 60
    // int arr[] = {-2, -3, 0, -2, -40}; // 80
    int size = sizeof(arr)/sizeof(arr[0]);

    int ans = maximum_product_subarray(arr, size);
    std::cout << ans;

    return 0;
}
