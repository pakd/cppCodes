#include <iostream>
using namespace std;

void three_way_partition( int *arr, int n, int m1, int m2 )
{

    int low = 0;
    int mid = 0;
    int high = n-1;

    while(mid<=high)
    {
        if(arr[mid] < m1)
        {
            swap(arr[mid], arr[low]);
            low++;
            mid++;
        }
        else if(arr[mid] > m2)
        {
            swap(arr[mid], arr[high]);
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
 int arr[] = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};
 int size = 13;
 three_way_partition(arr, size, 14, 20);
 for(int i=0;i<size;i++)
 {
     cout << arr[i] << "\t";
 }

}
