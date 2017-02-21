#include <iostream>
using namespace std;
int partition(int arr[],int l,int r);
void quicksort(int arr[],int l, int r)
{
    if(l>=r){
        return;
    }
    int pivot=partition(arr,l,r);
    quicksort(arr,l,pivot-1);
    quicksort(arr,pivot+1,r);
}
int partition(int arr[],int l, int r)
{
    int key=arr[r];
    int i=l,j=r;
    while(i<j)
    {
        while(arr[i]<key) i++;
        while(arr[j]>key) j--;
        if(i<j) swap(arr[i],arr[j]);
    }
    return j;
}
int main()
{
    int arr[]= {9,100,7,6,-1,4,3,2,234};
    int n=9;
    quicksort(arr,0,8);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
