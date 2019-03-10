#include <iostream>
using namespace std;
int merge (int arr[],int l, int m,int r);
int mergesort(int arr[],int l, int r)
{
    int invCount = 0;
    if(l>=r)
    {
        return 0;
    }
    int m = (l+r)/2;
    invCount = mergesort(arr,l,m);
    invCount += mergesort(arr,m+1,r);
    invCount += merge(arr,l,m,r);
    return invCount;
}

int merge (int arr[],int l, int m,int r)
{
    int n1= m + 1 - l;
    int n2 = r - m;
    int invCount = 0;
    int l_arr[n1];
    int r_arr[n2];


    for(int i=0;i<n1;i++) {
        l_arr[i]=arr[l+i];
    }

    for(int j=0;j<n2;j++) {
        r_arr[j]=arr[j + m + 1];

    }

    int i = 0,j=0,k=l;

    while(i<n1 && j<n2)
    {
        if(l_arr[i]<r_arr[j])
        {
            arr[k++]=l_arr[i++];
        }
        else
        {
           arr[k++]=r_arr[j++];
           //cout << l_arr[i] << " " << r_arr[j-1] << endl;
           //cout << "count:" << n1 - i << endl;
           invCount += (n1 - i);
        }
    }
    while(i<n1)
    {
        arr[k++]=l_arr[i++];
    }
    while(j<n2)
    {
        arr[k++]=r_arr[j++];
    }

    return invCount;
}
int main()
{
    // int arr[]={ 6,4,3,2,1}; // ans =10
     int arr[] = { 1, 20, 6, 4, 5 }; // ans = 5
    //int arr[] = {2, 4, 1, 3, 5}; // ans = 3
    int n=5;
    cout << mergesort(arr,0,n-1) << endl ;
    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}
