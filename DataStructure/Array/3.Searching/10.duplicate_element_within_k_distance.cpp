#include <iostream>
#include <set>

void duplicate_element_within_k_distance(int *arr, int n, int k)
{
    std::set<int> mySet;

    for(int i=0;i<n;i++)
    {
        if(mySet.find(arr[i])!=mySet.end())
        {
            std::cout << arr[i];
            return ;
        }

        mySet.insert(arr[i]);

        if(i >= k)
            mySet.erase(arr[i-k]);

    }
    std::cout << "not found";
}

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5};
    //int arr[] = {1, 2, 3, 4, 1, 5};
    int size = sizeof(arr)/sizeof(arr[0]);

    duplicate_element_within_k_distance(arr, size, 3);

    return 0;
}
