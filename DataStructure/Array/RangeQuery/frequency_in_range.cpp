#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;


unordered_map<int, vector<int>> m;

int frequency( int L, int R , int elem)
{
    int a = lower_bound(m[elem].begin(), m[elem].end(), L) - m[elem].begin();

    int b = upper_bound(m[elem].begin(), m[elem].end(), R) - m[elem].begin();

    return b - a;
}

int main()
{

    int arr[] = {2, 8, 6, 9, 8, 6, 8, 2, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    for(int i=0;i<n;i++)
    {
        m[arr[i]].push_back(i);
    }

    cout << frequency(1 ,6, 8);


    return 0;
}
