#include<iostream>
using namespace std;

int FindMaxSum(int *arr, int n)
{
    int incl = arr[0]; // including first element
    int excl = 0; // excluding first element

    for(int i=1; i <n; i++)
    {
        // excluding ith element
        int excl_temp = max(incl, excl);

        // including ith element
        incl = excl + arr[i];

        excl = excl_temp;
    }

    return max(incl, excl);

}


int main()
{
    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << FindMaxSum(arr, n);
    return 0;
}
