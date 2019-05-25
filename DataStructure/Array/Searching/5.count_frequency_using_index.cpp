#include <iostream>

void calculate_frequency(int *arr, int n)
{
    int i = 0;
    while(i<n)
    {
        if (arr[i] == i && i != 0)
        {
            arr[i] = -1;
            i++;
        }
        else if(arr[i] > 0)
        {
            if(arr[arr[i]] > 0)
            {
                int temp = arr[arr[i]];
                arr[arr[i]] = -1;
                arr[i] = temp;
            }
            else
            {
                arr[arr[i]]--;
                arr[i] = 0;
            }
        }
        else
        {
            i++;
        }
    }
}


int main()
{
    int arr[] = {1,2,3,3,4,5,6,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    calculate_frequency(arr, size);
    for(int i=0;i<size;i++)
    {
        std::cout << i << " " << -1*arr[i] << std::endl;
    }

    return 0;
}
