#include <iostream>
using namespace std;

// if A < 0 there is one max
// if A > 0 there is one min
// only considering A < 0 i.e. one max only
int sort_parabolic_equation (int *arr,int n, int A, int B, int C)
{
    // apply equation
    for(int i=0;i<n;i++)
    {
        int x = arr[i];
        arr[i] = A*x*x + B*x + C;
    }

    //find maximum element index
    int index;
    int maximum = INT_MIN;

    for(int i=0;i<n;i++)
    {
        if(arr[i] > maximum)
        {
            maximum = arr[i];
            index = i;
        }
    }

    // using merge procedure as array has two sub-arrays in sorted in decreasing and increasing order both.
    int i=0, j = n - 1;
    int newArr[n], k = 0;
    while(i < index && j > index )
    {
        if(arr[i] < arr[j])
        {
            newArr[k++] = arr[i++];
        }
        else
        {
            newArr[k++] = arr[j--];
        }
    }

    // remaining element
    while (i < index)
        newArr[k++] = arr[i++];
    while (j > index)
        newArr[k++] = arr[j--];

    newArr[n-1] = maximum;

    // Modify original array
    for (int i = 0; i < n ; i++)
        arr[i] = newArr[i];

}
int main()
{

    int arr[] = {-21 ,-15, 12, 13, 14 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int A = -6, B =-7, C = 2;

    sort_parabolic_equation(arr, n, A, B, C);

    for(int i=0;i<n;i++)
    {
        cout << arr[i] << " ";
    }
}
