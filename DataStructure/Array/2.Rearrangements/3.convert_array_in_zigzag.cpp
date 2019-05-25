#include<iostream>

void convert_zigzag(int *arr, int size)
{
    bool flag = true;

    for(int i = 0; i<size-1; i++)
    {
        if(flag)
        {
            if(arr[i] > arr[i+1])
            {
                std::swap(arr[i], arr[i+1]);
            }
        }
        else
        {
            if(arr[i] < arr[i+1])
            {
                std::swap(arr[i], arr[i+1]);
            }
        }
        flag = !flag;
    }

}


int main()
{
    int arr[] = {4, 3, 7, 8, 6, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    convert_zigzag(arr, size);
    for(int i=0;i<size;i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;

}

