#include <iostream>

int main()
{
    int arr[]={10,5,2,4,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<n;i++)
    {
        int j = i;
        while(j>0   && arr[j]<arr[j-1])
        {
            std::swap(arr[j],arr[j-1]);
            j--;
        }
    }

    for(int k=0;k<n;k++)
    {
        std::cout << arr[k] << " ";
    }

    return 0;
}
