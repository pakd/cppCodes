#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

std::unordered_map <int, int> indexMap;

/*
1. take 2 unordered map one for storing count countMap[]
and other for maintaining index for first occurence of distinct elements indexMap[]
2. take vector of pair<int, int> v and copy all element of map to vector using
copy(countMap.begin(), countMap.end(),back_inserter(v))
3. sort vector using compare function using both the maps
4. copy elements of vector to original arr.
note - ignore map(normal)as it is already sorted by key value.
*/

bool compare(std::pair<int,int>& a, std::pair<int,int>& b )
{
    if(a.second == b.second)
    {
        return (indexMap[a.first] < indexMap[b.first]);
    }
    return a.second > b.second;
}

void sort_by_frequency(int *arr, int n)
{
    std::unordered_map <int, int> countMap;

    for(int i=0; i<n; i++)
    {
        countMap[arr[i]]++;
        if(indexMap[arr[i]]==0)
        {
            indexMap[arr[i]] = i;
        }
    }

    std::vector< std::pair<int,int>> v;

    copy(countMap.begin(),countMap.end(),back_inserter(v)); // equivalent to below code in comments

    /*
    for(auto it : countMap)
    {
        v.push_back({it.first, it.second});
    }
    */

    sort(v.begin(), v.end(), compare);

    int k = 0;
    for(int i=0; i < v.size(); i++)
    {
        for(int j =0; j<v[i].second; j++)
        {
            arr[k++] = v[i].first;
        }
    }
}

int main()
{
    int arr[] = {3,2,3,1,1,2,3,2,3,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    sort_by_frequency(arr, size);

    for(int i=0; i<size; i++)
    {
        std::cout << arr[i] << " ";
    }

}
