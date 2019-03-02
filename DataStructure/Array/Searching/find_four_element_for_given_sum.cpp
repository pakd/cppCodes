#include <iostream>
#include <unordered_map>
using namespace std;

void find_4_elements(int *arr, int n, int sum)
{
    unordered_map<int, pair<int, int>> m;
    for(int i=0;i<n-1;i++)
    {
        for(int j = i+1; j<n;j++)
        {
            m[arr[i] + arr[j]] = {i,j};
        }
    }

    for(int i=0;i<n-1;i++)
    {
        for(int j = i+1; j<n ;j++)
        {
            int curr_sum = arr[i] + arr[j];
            if(m.find(sum - curr_sum) != m.end())
            {
                pair <int, int> p = m[sum - curr_sum];
                if(p.first !=  i && p.second!= i && p.first !=j && p.second!=j )
                {
                    cout << arr[i] << "\t " << arr[j] << "\t" << arr[p.first] << "\t" << arr[p.second] << endl;
                    return; //remove it for multiple solution
                }
            }
        }
    }
}

int main()
{
    int arr[] =  {10, 20, 30, 40, 1, 2};  ;
    int size = sizeof(arr)/sizeof(arr[0]);
    int sum = 91;
    find_4_elements(arr, size, sum);
    return 0;
}
