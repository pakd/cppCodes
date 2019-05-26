#include <iostream>

double findMedianSortedArrays(int *arr1, int n, int *arr2, int m)
{
    if(n>m)
    {
        return findMedianSortedArrays(arr2, m, arr1, n);
    }

    int low = 0, high = n;
    int i, j;

    while(low<=high)
    {
        i = (low+high)/2;
        j = (n + m + 1)/2 - i; // + 1 for make it work for both odd and even

        int maxLeftX = (i == 0)? INT_MIN : arr1[i-1];
        int minRightX = (i == n)? INT_MAX : arr1[i];

        int maxLeftY = (j == 0)? INT_MIN : arr2[j-1];
        int minRightY = (j == m)? INT_MAX : arr2[j];

        if(maxLeftX <= minRightY && maxLeftY <= minRightX)
        {

            // odd length
            if((m+n)%2 ==0)
            {
                return (double)(std::max(maxLeftX, maxLeftY) + std::min(minRightX,minRightY))/2;
            }

            // even length
            else
                return std::max(maxLeftX, maxLeftY);
        }
        else if(maxLeftX > minRightY)
            high = i - 1;
        else
            low = i + 1;
    }

}


int main()
{

    int arr1[] = {1,3,8,9,15};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {7,11,18,19,21,25};
    int size2 = sizeof(arr2)/sizeof(arr2[0]);

    std::cout << findMedianSortedArrays(arr1, size1, arr2, size2);
}
