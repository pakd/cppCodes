#include <iostream>
#include <unordered_map>

void find_subarray_with_given_sum_negative_included(int *arr, int n, int sum)
{
    std::unordered_map<int, int> m;
    int curr_sum = 0;
    for(int i=0; i<n; i++)
    {
        curr_sum += arr[i];
        if(curr_sum == sum)
        {
            for(int j=0; j<=i; j++)
                std::cout << arr[j] << " ";
            return;
        }
        if(m.find(curr_sum - sum) != m.end())
        {
            for(int j = m[curr_sum - sum] + 1 ; j<=i; j++)
                std::cout << arr[j] << " ";
            return;
        }
        m[curr_sum] = i;
    }
    std::cout << "not found";
}


int main()
{
    //int arr[] = {10, 2, -2, -20, 10};  int sum = -22;
    int arr[] = {3,2,7,1,6};
    int sum = 10;
    int size = sizeof(arr)/sizeof(arr[0]);

    find_subarray_with_given_sum_negative_included(arr, size, sum);

    return 0;
}
