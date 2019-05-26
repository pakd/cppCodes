#include <iostream>

void min_search(int *arr, int size, int key) // total n+2 comparisons
{
    if(arr[size-1] == key)   // 1 comparison
    {
        std::cout << "element found";
        return;
    }

    int temp = arr[size-1];
    arr[size-1] = key;
    for(int i=0;;i++)
    {
        if(arr[i] == key) // n comparisons
        {
            arr[size - 1] = temp;
            if(i < size-1) // 1 comparison
            {
                std::cout << "element found";
                return;
            }
        }
    }
}
int main()
{

    int arr[] = {2, 5, 8, 11, 18, 25};
    int key = 8;
    int size = sizeof(arr)/sizeof(arr[0]);

    min_search(arr, size , key);

    return 0;
}
