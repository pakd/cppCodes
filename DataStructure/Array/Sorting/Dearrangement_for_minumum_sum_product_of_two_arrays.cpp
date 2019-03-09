#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int no_of_dearrangements(int *arr1, int *arr2,  int n)
{
    vector<int> copyArr1(arr1, arr1 + n);
    vector<int> copyArr2(arr2, arr2 + n);

    sort(copyArr1.begin(), copyArr1.end());
    sort(copyArr2.begin(), copyArr2.end(), greater<int>());

    map<int, int> m;
    int count = 0;

    for(int i=0;i<n;i++)
    {
        m[copyArr1[i]]=copyArr2[i];
    }

    for(int i=0;i<n;i++)
    {

        if(arr2[i] != m[arr1[i]])
        {
            count++;
        }

    }
    return count;
}

int main()
{
    int A[] = {1, 2, 3, 4};
    int B[] = {6, 3, 4, 5};
    int size = sizeof(A)/sizeof(A[0]);
    cout << no_of_dearrangements(A, B, size);

    return 0;
}
