#include <iostream>
#include <set>
using namespace std;


// find m zeroes
void findZeroes(int *arr, int n, int m)
{
    // indexes of sliding window
    int wL = 0, wR = 0;

    // index and size of best window
    int bestL = 0, bestWindowSize = 0;

    // no of zeros in current window
    int zeroCount = 0;

    while(wR < n)
    {
        if(zeroCount <= m)
        {
            if(arr[wR] ==0)
            {
                zeroCount++;
            }
            wR++;
        }

        if(zeroCount > m)
        {
            if(arr[wL] ==0)
            {
                zeroCount--;
            }
            wL++;
        }

        if(wR - wL > bestWindowSize && zeroCount <=m)
        {
            bestWindowSize = wR - wL;
            bestL = wL;
        }
    }

    for(int i=0; i<bestWindowSize; i++)
    {
        if(arr[bestL + i] == 0)
        {
            cout << bestL + i << "\t";
        }
    }



}
int main()
{
    int arr[] = {1, 0, 0, 1, 1, 0, 1, 0, 1, 1};
    int m = 2;
    int n =  sizeof(arr)/sizeof(arr[0]);
    cout << "Indexes of zeroes to be flipped are ";
    findZeroes(arr, n, m);
    return 0;
}
