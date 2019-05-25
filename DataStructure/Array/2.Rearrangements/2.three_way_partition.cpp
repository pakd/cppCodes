#include <iostream>

void three_way_partition( int *arr, int n, int m1, int m2 )
{
    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high)
    {
        if(arr[mid] < m1)
        {
            std::swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] > m2)
        {
            std::swap(arr[mid], arr[high]);
            high--;
        }
        else
        {
            mid++;
        }
    }
}
int main()
{
    int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32, 15, 17, 18};
    int size = sizeof(arr)/sizeof(arr[0]);

    three_way_partition(arr, size, 14, 20);

    for(int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
