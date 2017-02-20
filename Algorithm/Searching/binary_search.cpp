#include<iostream>
using namespace std;
int BinarySearch(int arr[],int left, int right, int key)
{
    if(right<left) return -1;
    else
    {
        int mid= (left+right)/2;
        if(arr[mid]==key) return mid;
        else if(arr[mid]>key) BinarySearch(arr,left,mid-1,key);
        else BinarySearch(arr,mid+1,right,key);
     }
}
int main()
{
    int arr[]={3,6,9,10,23,45,56,67,89};
    cout<<BinarySearch(arr,0,8,89);


}
