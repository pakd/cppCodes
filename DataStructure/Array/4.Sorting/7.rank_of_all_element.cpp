#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <map>

int retSum(int i, int j)
{
    int sum = 0;
    for(int k=i;k<=j;k++)
    {
        sum+=k;
    }
    return sum;
}
void print_array(double *arr, int n)
{
    for(int i=0;i<n;i++)
    {
        std::cout << arr[i] << " " ;
    }
    std::cout << std::endl;
}

void rank_of_all_element(int *arr,  int n, double *rank)
{
    std::map<int, int> frequency;
    std::unordered_map<int, double> rankMap;

    for(int i=0;i<n;i++)
    {
        frequency[arr[i]]++;
    }

    int i = 1;
    for(auto it = frequency.begin(); it!=frequency.end();it++)
    {
        double neum = retSum(i, i+ it->second - 1);
        rankMap[it->first] = neum / (it->second);
        i = i + it->second;
    }

    for(int i=0;i<n;i++)
    {
        rank[i] = rankMap[arr[i]];
    }
}

int main()
{
    int arr[] = {10, 12, 15, 12, 10, 25, 12};
    int size = sizeof(arr)/sizeof(arr[0]);

    double rank[size] = {0};
    rank_of_all_element(arr,  size, rank);

    print_array(rank, size);

    return 0;
}
