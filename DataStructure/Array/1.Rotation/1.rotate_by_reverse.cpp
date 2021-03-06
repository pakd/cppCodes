#include <iostream>

void ReverseArray(int *arr, int l, int r)
{
    while(l<r)
    {
        std::swap(arr[l],arr[r]);
        l++; r--;
    }
}

void LeftRotateArray(int *arr, int d, int size)
{
    ReverseArray(arr, 0 , d - 1);
    ReverseArray(arr, d, size - 1);
    ReverseArray(arr, 0, size - 1);
}

void RightRotateArray(int *arr, int d, int size)
{
    ReverseArray(arr, 0 , size - 1);
    ReverseArray(arr, 0, d-1);
    ReverseArray(arr, d, size - 1);
}


int main()
{
    int larr[] = {1,2,3,4,5,6};
    int size = 6;
    int d = 2;
    LeftRotateArray(larr, d, size);

    for(int i =0; i < size ; i++)
    {
        std::cout << larr[i] << "\t";
    }

    std::cout << std::endl;

    int rarr[] = {1,2,3,4,5,6};
    RightRotateArray(rarr, d, size);

    for(int i =0; i < size ; i++)
    {
        std::cout << rarr[i] << "\t";
    }

    return 0;
}
