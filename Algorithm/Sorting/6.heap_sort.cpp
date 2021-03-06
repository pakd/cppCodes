#include <iostream>

int leftChild(int index)
{
    return (2*index + 1);
}

int rightChild(int index)
{
    return (2*index + 2);
}

void max_heapify(int *arr, int n, int index)
{
    int largest = index;

    int l = leftChild(index);
    if(l<n && arr[l] > arr[largest])
    {
        largest = l;
    }

    int r = rightChild(index);
    if(r<n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if(largest !=index)
    {
        std::swap(arr[largest], arr[index]);
        max_heapify(arr, n, largest);
    }
}

void heapsort(int *arr, int n)
{
    for(int i = (n/2 - 1); i >=0 ; i--)
    {
        max_heapify(arr, n , i);
    }

    for(int i=n-1;i >= 0; i--)
    {
        std::swap(arr[0], arr[i]);
        max_heapify(arr, i, 0);
    }
}


int main()
{
    int arr[] = {12,11,13,5,6,7};
    int size = sizeof(arr)/sizeof(arr[0]);

    heapsort(arr, size);

    for(int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
