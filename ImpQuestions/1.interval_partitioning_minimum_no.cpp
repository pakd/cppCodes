#include <iostream>
#include <map>
using namespace std;

int findPlatform(int *arr, int *dep, int n)
{
    multimap<int, char> orderMap;

    for(int i=0; i<n; i++)
    {
        orderMap.insert({arr[i], 'a'});
        orderMap.insert({dep[i], 'd'});
    }

    int count = 0;
    int maxPlatform = 0;
    for (auto it=orderMap.begin(); it!=orderMap.end(); it++)
    {
        if(it->second == 'a')
        {
            count++;
        }
        else
        {
            count--;
        }
        maxPlatform = max(count, maxPlatform);
    }

    return maxPlatform;
}


int main()
{
    int arr[] = { 900, 940, 950, 1100, 1500, 1800 };
    int dep[] = { 910, 1200, 1120, 1130, 1900, 2000 }; // ans = 3

    //int arr[] = { 930, 930, 930, 1130, 1100, 1330, 1330, 1430, 1530 };
    //int dep[] = { 1100, 1300, 1100, 1300, 1400, 1500, 1500, 1700, 1700 }; // ans = 3

    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum Number of Platforms Required = "
         << findPlatform(arr, dep, n);
    return 0;
}
