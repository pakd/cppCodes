#include <iostream>

void merge (int arr[],int l, int m,int r);

void mergesort(int arr[],int l, int r)
{
    if(l>=r)
    {
        return;
    }
    int m = (l+r)/2;
    mergesort(arr,l,m);
    mergesort(arr,m+1,r);
    merge(arr,l,m,r);
}

void merge (int arr[],int l, int m,int r)
{
    int n1 = m + 1 - l;
    int n2 = r - m;
    int l_arr[n1];
    int r_arr[n2];

    for(int i=0;i<n1;i++) {
        l_arr[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++) {
        r_arr[j]=arr[j + m + 1];
    }

    int i = 0, j = 0, k = l;

    while(i<n1 && j<n2)
    {
        if(l_arr[i]<r_arr[j])
        {
            arr[k++]=l_arr[i++];
        }
        else
        {
           arr[k++]=r_arr[j++];
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
}

int main()
{
    int arr[]={-34,23,123,7,1, 0};
    int n = sizeof(arr)/sizeof(arr[0]);

    mergesort(arr,0,n-1);

    for(int i=0;i<n;i++)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}
