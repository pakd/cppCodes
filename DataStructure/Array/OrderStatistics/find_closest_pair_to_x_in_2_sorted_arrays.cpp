#include <iostream>
using namespace std;

// using no extra space
void printClosest(int *arr1, int m, int *arr2, int n, int x)
{
    int diff = INT_MAX;
    int lIndex, rIndex;

    int i=0;
    int j=n-1;

    while( i < m && j >= 0)
    {
        if(abs ( arr1[i] + arr2[j] - x)  < diff )
        {
            diff = abs ( arr1[i] + arr2[j] - x);
            lIndex = i;
            rIndex = j;
        }
        if( (arr1[i] + arr2[j]) > x )
        {
            j--;
        }
        else
            i++;
    }

    cout << arr1[lIndex] << "\t" << arr2[rIndex];
}

int main()
{
    int ar1[] = {1, 4, 5, 7};
    int ar2[] = {10, 20, 30, 40};
    int m = sizeof(ar1)/sizeof(ar1[0]);
    int n = sizeof(ar2)/sizeof(ar2[0]);
    int x = 38;
    printClosest(ar1, m, ar2, n, x);
    return 0;
}
