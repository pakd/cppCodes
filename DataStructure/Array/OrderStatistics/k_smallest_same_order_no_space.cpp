#include <iostream>
using namespace std;

// https://www.geeksforgeeks.org/k-smallest-elements-order-using-o1-extra-space/
void printSmall(int *arr, int n, int k)
{
    for(int i=k; i < n ; i++)
    {
        // maximum in 0 to k
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

        // left shift all elements in 0 to k
        // arr[k-1] = arr[i]
        if(arr[i] < maxInK)
        {
            for(int it=pos; it < k-1; it++)
            {
                arr[it] = arr[it+1];
            }
            arr[k-1] = arr[i];
        }

    }

    // print result
    for (int i=0; i<k; i++)
    {
        cout << arr[i] <<" ";
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
