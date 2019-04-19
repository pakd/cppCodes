#include <iostream>
#include <vector>
using namespace std;

int minJumps(int *arr, int n)
{
    vector <int> jumps(n, INT_MAX);

    jumps[0] = 0;

    for(int i=1;i<n;i++)
    {
        for (int j=0; j<i; j++)
        {
            if( j + arr[j] >= i)
            {
                jumps[i] = min(jumps[i], 1 + jumps[j]);
            }
        }
    }
    return jumps[n-1];
}


int main()
{
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}; //{1, 3, 6, 1, 0, 9};
    int size = sizeof(arr)/sizeof(int);
    printf("Minimum number of jumps to reach end is %d ", minJumps(arr,size));
    return 0;
}
