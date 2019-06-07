#include <iostream>


// https://www.geeksforgeeks.org/k-smallest-elements-order-using-o1-extra-space/
void printSmall(int *arr, int n, int k)
{
    // For each arr[i] find whether
    // it is a part of n-smallest
    // with insertion sort concept
    for(int i=k; i < n ; i++)
    {
        // find largest from first k-elements
        int maxInK = arr[0];
        int pos = 0;
        for(int j=1; j<k;j++)
        {
            if(arr[j] > maxInK)
            {
                maxInK = arr[j];
                pos = j;
            }
        }

        // if largest is greater than arr[i]
        // shift all element one place left
        if(arr[i] < maxInK)
        {
            for(int it=pos; it < k-1; it++)
            {
                arr[it] = arr[it+1];
            }
            // make arr[k-1] = arr[i]
            arr[k-1] = arr[i];
        }
    }

    // print result
    for (int i=0; i<k; i++)
    {
        std::cout << arr[i] <<" ";
    }

}


int main()
{
    int arr[] = { 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 5;
    printSmall(arr, n, k);
    return 0;
}
