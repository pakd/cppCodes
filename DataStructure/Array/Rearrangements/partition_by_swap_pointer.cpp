#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;



void move_zero_to_end(int *arr, int n)
{
    int prev0 = 0;
    for(int i=0;i<n;i++)
    {
        if(arr[i] ==1)
        {
            swap(arr[i], arr[prev0]);
            prev0++;
        }
    }
}

int main()
{
    int arr[] = { 1 , 0, 1, 0, 1, 0, 0, 1, 1, 1};
    int size = 10;
    move_zero_to_end(arr, size);
    for(int i = 0; i < size; i++)
    {

        cout << arr[i] << "\t";
    }
}
