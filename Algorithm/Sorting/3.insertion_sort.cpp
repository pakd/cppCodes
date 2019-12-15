#include <iostream>

int main()
{
    int arr[]={10,5,2,4,-1};
    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=1;i<n;i++)
    {
    	int key = arr[i];
        int j = i-1;
        
        while(j>=0   && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    for(int k=0;k<n;k++)
    {
        std::cout << arr[k] << " ";
    }

    return 0;
}
