#include <iostream>

// using no extra space
int maxRepeatingNo(int *arr, int n, int k)
{
    for(int i=0;i<n;i++)
    {
        arr[arr[i]%k] += k;
    }

    // find index maximum repeating element
    int max = arr[0], result = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            result = i;
        }
    }

    /* Uncomment this code to get the original array back
       for (int i = 0; i< n; i++)
          arr[i] = arr[i]%k; */

    // Return index of the maximum element
    return result;
}

int main()
{
    int arr[] = {2, 3, 3, 5, 3, 4, 1, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 8;
    std::cout << "The maximum repeating number is " << maxRepeatingNo(arr, n, k) << std::endl;
    return 0;
}
