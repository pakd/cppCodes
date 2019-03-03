#include<iostream>
using namespace std;

int trapRainingWater(int *arr, int n)
{
    int leftMax[n],rightMax[n];

    // left max array
    leftMax[0] = arr[0];
    for(int i=1;i<n;i++)
        leftMax[i] = max(arr[i], leftMax[i-1]);


    // right max array
    rightMax[n-1] = arr[n-1];
    for(int i=n-2;i>=0;i--)
        rightMax[i] = max(arr[i], rightMax[i+1]);

    // one one array can be used e.g. rightMax array and just one variable to store max left value in it.
    int waterCap = 0;
    for(int i=0;i<n;i++)
    {
        waterCap += (min(leftMax[i], rightMax[i]) - arr[i]);
    }
    return waterCap;
}


int main()
{
    int arr[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout << trapRainingWater(arr, size);
    return 0;

}
