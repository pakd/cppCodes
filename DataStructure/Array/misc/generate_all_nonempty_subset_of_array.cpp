#include <iostream>
#include <cmath>
using namespace std;


void printSubsequences(int *arr, int n)
{
    int total = pow(2,n);
    for(int counter = 1 ; counter < total ; counter++)
    {
        for(int i=0;i<n;i++)
        {
            if(counter & (1 << i))
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << "All Non-empty Subsequences\n";
    printSubsequences(arr, n);
    return 0;
}
