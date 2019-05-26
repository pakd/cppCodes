#include <iostream>
#include <algorithm>


void print_array(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout << arr[i] << " " ;
    }
    std::cout << std::endl;
}

void merge_two_array(int *arr1, int m, int *arr2, int n)
{
    for(int i=n-1;i>=0;i--)
    {
        int last = arr1[m-1];
        int j;
        for(j=m-2; j>=0 && arr1[j] > arr2[i]; j--)
        {
            arr1[j+1] = arr1[j];
        }

        if( j!=m-2 || last > arr2[i])
        {
            arr1[j+1] = arr2[i];
            arr2[i] = last;
        }
    }

}

int main()
{
    int arr1[] = {1, 5, 9, 10, 15, 20};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);

    int arr2[] = {2, 3, 8, 13};
    int size2= sizeof(arr2)/sizeof(arr2[0]);

    merge_two_array(arr1, size1, arr2, size2);

    print_array(arr1, size1);
    print_array(arr2, size2);

    return 0;
}
