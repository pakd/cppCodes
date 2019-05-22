#include <iostream>

int main()
{
    int arr[]={10,5,2,4,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }

    for(int k=0;k<n;k++)
    {
        std::cout << arr[k] << " ";
    }

    return 0;
}
