#include <bits/stdc++.h>
using namespace std;

int lscs(int arr[],int n)
{
    int curr_max = arr[0];
    int max_so_far = arr[0];

    for(int i=1;i<n;i++)
    {
        curr_max = max(curr_max + arr[i], arr[i]);
        max_so_far = max(curr_max, max_so_far);
    }
    return max_so_far;
}
int main()
{

    int arr[]={-2, -3, 4, -1, -2, 1, 5, -3};
    cout << lscs(arr,8);
}
