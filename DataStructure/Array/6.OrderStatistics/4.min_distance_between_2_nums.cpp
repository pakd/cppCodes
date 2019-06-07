#include <iostream>

int minDist(int *arr, int n, int x, int y)
{
    int i = 0;
    int min_dist = INT_MAX;
    int prev;

    for (i = 0; i < n; i++)
    {
        if (arr[i] == x || arr[i] == y)
        {
            prev = i;
            break;
        }
    }

    for ( ; i < n; i++)
    {
        if (arr[i] == x || arr[i] == y)
        {
            // if current element is not same as previous element
            if ( arr[prev] != arr[i] && (i - prev) < min_dist )
            {
                min_dist = i - prev;
            }
            prev = i;
        }
    }
    return min_dist;
}

int main()
{
    int arr[] = {3, 5, 4, 2, 6, 3, 0, 0, 5, 4, 8, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 3;
    int y = 6;

    std::cout << "Minimum distance between " << x <<
              " and " << y << " is "<<
              minDist(arr, n, x, y);
    return 0;
}
