#include <iostream>
#include <algorithm>

int min_swaps(int *arr,  int n)
{
    std::pair<int, int> pos[n];

    for(int i=0;i<n;i++)
    {
        pos[i].first = arr[i];
        pos[i].second = i;
    }

    std::sort(pos, pos + n);

    bool vis[n] = {0};

    int res = 0;
    for(int i=0 ; i<n; i++)
    {

        if(vis[i] || pos[i].second == i)
            continue;

        int cycle_size = 0;
        int j = i;

        while(!vis[j])
        {
            vis[j] = 1;
            j = pos[j].second;
            cycle_size++;
        }

        if(cycle_size > 0)
        {
            res += (cycle_size-1);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1,5,4,3,2};
    int size = sizeof(arr)/sizeof(arr[0]);

    std::cout << min_swaps(arr, size);

    return 0;
}
