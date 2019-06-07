#include <iostream>

struct Node
{
    int minE;
    int maxE;
};

Node minmax(int *arr, int low, int high)
{
    Node ans;
    if(low == high)
    {
        ans.minE = arr[low];
        ans.maxE = arr[high];
        return ans;
    }
    if(low + 1 == high)
    {
        if(arr[low] > arr[high])
        {
            ans.minE = arr[high];
            ans.maxE = arr[low];
        }
        else
        {
            ans.minE = arr[low];
            ans.maxE = arr[high];
        }
        return ans;
    }

    int mid = (low + high)/2;
    Node left = minmax(arr, low, mid);
    Node right = minmax(arr, mid+1, high);

    ans.minE = std::min(left.minE, right.minE);
    ans.maxE = std::max(left.maxE, right.maxE);

    return ans;
}

int main()
{
    int arr[] = {1000, 11, 445, 1, 330, 3000, 451, 265};
    int size = sizeof(arr)/sizeof(arr[0]);
    Node ans = minmax(arr, 0, size-1);
    std::cout << "min element" << "\t" << ans.minE << std::endl;
    std::cout << "max element" << "\t" << ans.maxE << std::endl;
    return 0;
}
