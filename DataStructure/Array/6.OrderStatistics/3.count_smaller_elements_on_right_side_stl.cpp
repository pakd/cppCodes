#include <iostream>
#include <set>

// insertion using insertion sort from last index and print current index of value.
void countSmallerRight(int *arr, int n)
{
    std::set<int> s;
    int countSmaller[n];
    for(int i=n-1; i>=0; i--)
    {
        s.insert(arr[i]);
        auto it = s.lower_bound(arr[i]);
        countSmaller[i] = distance(s.begin(), it);
    }
    for (int i = 0; i < n; i++)
    {
        std::cout << countSmaller[i] << " ";
    }
}

int main()
{
    int A[] = {12, 1, 2, 3, 0, 11, 4};
    int len = sizeof(A) / sizeof(int);
    countSmallerRight(A, len);
    return 0;
}
