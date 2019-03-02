#include <iostream>
#include <set>
using namespace std;

void duplicate_element_within_k_distance(int *arr, int n, int k)
{
    set<int> mySet;

    for(int i=0;i<n;i++)
    {
        if(mySet.find(arr[i])!=mySet.end())
        {
            cout << arr[i];
            return ;
        }

        mySet.insert(arr[i]);

        if(i >= k)
            mySet.erase(arr[i-k]);

    }
    cout << "not found";
}

int main()
{
    int arr[] = {1, 2, 3, 1, 4, 5};
    //int arr[] = {1, 2, 3, 4, 1, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    duplicate_element_within_k_distance(arr, size, 3);
    return 0;
}
