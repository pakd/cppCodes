#include <iostream>
#include <unordered_map>

void findSubArray(int *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        arr[i] = (arr[i]==0)? -1:1;
    }

    int sum[n];
    sum[0] = arr[0];
    for(int i=1; i<n; i++)
    {
        sum[i] = arr[i] + sum[i-1];
    }

    // element , index
    std::unordered_map<int, int> m;

    int maxVal = -1;
    int startIndex = -1;
    int endIndex = -1;

    // this is helpful in getting sub-arrays starting from index 0
    m[0] = -1;
    for(int i=0;i<n;i++)
    {
        if( m.find(sum[i]) != m.end() )
        {
            int index = m[sum[i]];
            int diff = i - index;
            if(diff > maxVal)
            {
                maxVal = diff;
                startIndex = index;
                endIndex = i;
            }
        }
        else
        {
            m[sum[i]] = i;
        }
    }

    std::cout << startIndex + 1 << " " << endIndex;
}
int main()
{
    int arr[] =  {1, 0, 0, 1, 0, 1, 1}; //{1, 0, 1, 1, 1, 0, 0};
    int size = sizeof(arr)/sizeof(arr[0]);

    findSubArray(arr, size);
    return 0;
}
