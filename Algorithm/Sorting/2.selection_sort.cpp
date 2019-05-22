#include <iostream>

int main()
{
    int arr[]= {7,45,-2,4,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int position;

    for(int i=0; i<n-1; i++)
    {
        position = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j]<arr[position])
            {
                position = j;
            }
        }
        std::swap(arr[position],arr[i]);
    }

    for(int k=0; k<n; k++)
    {
        std::cout << arr[k] << " ";
    }

    return 0;
}
