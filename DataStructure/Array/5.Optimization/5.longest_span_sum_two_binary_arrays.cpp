#include <iostream>
#include <map>

/*
longest common span (i, j) where j >= i such that arr1[i] + arr1[i+1] + …. + arr1[j] = arr2[i] + arr2[i+1] + …. + arr2[j].
*/
int longestCommonSum(int *arr1, int *arr2, int n)
{
    int *diff = new int(n);

    for(int i=0;i<n;i++)
    {
        diff[i] = arr1[i] - arr2[i];
    }

    std::map<int, int> m;

    int curr_sum = 0;
    int max_len = -1;

    for(int i=0;i<n;i++)
    {
        curr_sum += diff[i];

        if(curr_sum == 0)
        {
            max_len =  i+1;
        }
        if(m.find(curr_sum) != m.end())
        {
            max_len = std::max(max_len, i - m[curr_sum]);
        }
        else
        {
            m[curr_sum] = i;
        }
    }
    return max_len;
}

int main()
{
    int  arr1[] = {0, 1, 0, 1, 1, 1, 1};
    int  arr2[] = {1, 1, 1, 1, 1, 0, 1};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    std::cout << longestCommonSum(arr1, arr2, n);
    return 0;
}
