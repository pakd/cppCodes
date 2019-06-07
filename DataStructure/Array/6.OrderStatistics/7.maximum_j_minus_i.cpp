#include <iostream>

// maximum j - i such that arr[j] > arr[i]
int maxIndexDiff(int *arr, int n)
{
    int leftMin[n], rightMax[n];

    leftMin[0] = arr[0];
    for(int i=1;i<n;i++)
    {
        leftMin[i] = std::min(arr[i], leftMin[i-1]);
    }

    rightMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
    {
        rightMax[i] = std::max(arr[i], rightMax[i+1]);
    }

    int i = 0, j = 0, maxDiff = -1;
    while (i < n && j < n)
    {
        if (leftMin[i] < rightMax[j])
        {
            maxDiff = std::max(maxDiff, j-i);
            j++;
        }
        else
            i++;
    }
    return maxDiff;

}

int main()
{
    int arr[] = {9, 2, 3, 4, 5, 6, 7, 8, 18, 0};
    int n = sizeof(arr)/sizeof(arr[0]);
    int maxDiff = maxIndexDiff(arr, n);
    std::cout << maxDiff;
    return 0;
}
