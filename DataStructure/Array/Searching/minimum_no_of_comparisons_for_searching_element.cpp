#include <iostream>
#include <cmath>
using namespace std;


string min_search(int *arr, int size, int key) // total n+2 comparisons
{
    if(arr[size-1] == key)   // 1 comparison
        return "element found";
    int temp = arr[size-1];
    arr[size-1] = key;
    for(int i=0;;i++)
    {
        if(arr[i] == key) // n comparisons
        {
            arr[size - 1] = temp;
            if(i < size-1) // 1 comparison
            {
                return "element found";
            }
        }
    }
}
int main()
{

    int arr[] = {2, 5, 8, 11, 18, 25};
    int key = 8;
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << min_search(arr, size , key);

    return 0;
}
