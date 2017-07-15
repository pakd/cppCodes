#include <iostream>
using namespace std;
int partition(int arr[],int l,int r);
void quicksort(int arr[],int l, int r)
{
    if(l>=r){
        return;
    }
    int pivot=partition(arr,l,r);
    quicksort(arr,l,pivot);
    quicksort(arr,pivot+1,r);
}
int partition(int arr[],int l, int r)
{
    int key=arr[l];
    int i=l-1,j=r+1;
    while(1)
    {
         do
        {
            i++;
        } while (arr[i] < key);
  
        do
        {
            j--;
        } while (arr[j] > key);
        
         if(i>=j)
    		return j;
         swap(arr[i],arr[j]);
    }
   
}
int main()
{
    int arr[]= {9,100,7,6,-1,4,3,2,4};
    int n=9;
    quicksort(arr,0,8);
    for(int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}
