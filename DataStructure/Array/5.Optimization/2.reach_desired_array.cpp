#include <iostream>

int oddCount(int *arr, int n)
{
    int count = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i]&1)
        {
            count++;
            arr[i]--;
        }
    }
    return count;
}

void halfArray(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        arr[i] = arr[i]/2;
    }
}

bool ifAllZero(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i]!=0)
        {
            return false;
        }
    }
    return true;
}


int countMinOperations(int *arr, int n)
{
    int minCount = 0;
    while(1)
    {
        if(ifAllZero(arr, n))
        {
            return minCount;
        }
        int odd = oddCount(arr, n);
        if(odd > 0)
        {
            minCount+=odd;
        }
        else
        {
            minCount++;
            halfArray(arr, n);
        }
    }
}

int main()
{
    int arr[] = {2, 1};//{2, 3};//{16, 16, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << "Minimum number of steps required to get the given target array is : "
              << countMinOperations(arr, n);
    return 0;
}
