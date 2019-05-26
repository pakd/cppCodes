#include <iostream>
#include <unordered_map>

void find_4_elements(int *arr, int n, int sum)
{
    std::unordered_map<int, std::pair<int, int>> m;
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1; j<n; j++)
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
                std::pair <int, int> p = m[sum - curr_sum];
                if(p.first !=  i && p.second!= i && p.first !=j && p.second!=j )
                {
                    std::cout << arr[i] << " " << arr[j] << " " << arr[p.first] << " " << arr[p.second] << std::endl;
                    return; //remove it for multiple solution
                }
            }
        }
    }
}

int main()
{
    int arr[] =  {10, 20, 30, 40, 1, 2};
    int size = sizeof(arr)/sizeof(arr[0]);

    int sum = 91;
    find_4_elements(arr, size, sum);

    return 0;
}
