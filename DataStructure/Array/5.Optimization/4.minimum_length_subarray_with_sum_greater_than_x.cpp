#include <iostream>

int smallestSubWithSum(int *arr, int n, int x)
{
    int curr_sum = 0;
    int min_length = INT_MAX;

    int start = 0, end = 0;

    while(end < n)
    {
        if(curr_sum < 0)
        {
            start  = end;
            curr_sum = 0;
        }

        else if(curr_sum <= x)
        {
            curr_sum+= arr[end];
            end++;
        }
        else
        {
            min_length = std::min(min_length, end - start);
            curr_sum -= arr[start];
            start++;
        }
    }
    return min_length;
}

int main()
{
    int arr1[] = {- 8, 1, 4, 2, -6};
    int x = 6;
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int res1 = smallestSubWithSum(arr1, n1, x);
    (res1 == n1+1)? std::cout << "Not possible\n" : std::cout << res1 << std::endl;

    int arr2[] = {1, 10, 5, 2, 7};
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    x  = 9;
    int res2 = smallestSubWithSum(arr2, n2, x);
    (res2 == n2+1)? std::cout << "Not possible\n" : std::cout << res2 << std::endl;

    int arr3[] = {1, 11, 100, 1, 0, 200, 3, 2, 1, 250};
    int n3 = sizeof(arr3)/sizeof(arr3[0]);
    x  = 280;
    int res3 = smallestSubWithSum(arr3, n3, x);
    (res3 == n3+1)? std::cout << "Not possible\n" : std::cout << res3 << std::endl;

    return 0;
}
