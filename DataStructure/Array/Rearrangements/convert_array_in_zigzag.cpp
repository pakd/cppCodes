#include<iostream>
using namespace std;



void convert_zigzag(int *arr, int size)
{
    bool flag = true;

    for(int i = 0;i < size-1 ;i++)
    {
        if(flag)
        {
            if(arr[i] > arr[i+1])
            {
                swap(arr[i], arr[i+1]);
            }
        }
        else
        {
            if(arr[i] < arr[i+1])
            {
                swap(arr[i], arr[i+1]);
            }
        }
        flag = !flag;
    }

}


int main()
{
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int size = 7;
    convert_zigzag(arr, size);
    for(int i=0;i<size;i++)
    {
        cout << arr[i] << "\t";
    }

}

