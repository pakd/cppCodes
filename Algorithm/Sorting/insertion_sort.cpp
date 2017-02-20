#include <iostream>
using namespace std;
int main()
{
    int arr[]={10,5,2,4,-1};
    int n=5,j;
    for(int i=1;i<n;i++)
    {
        j =i;
        while(j>0   && arr[j]<arr[j-1])
        {
            swap(arr[j],arr[j-1]);
            j--;
        }
    }
    for(int k=0;k<n;k++)
    {
        cout << arr[k] << " ";
    }
}
