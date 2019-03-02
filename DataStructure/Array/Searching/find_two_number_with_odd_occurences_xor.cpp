#include <iostream>
using namespace std;

void find_two_numbers_with_odd_occurences(int *arr, int n)
{
    int xor2 = arr[0];
    for(int i =1; i< n;i++)
    {
        xor2 = xor2^arr[i];
    }

    int setbit = xor2 & ~(xor2 -1);
    int x = 0;
    int y = 0;

    for(int i =0;i<n;i++)
    {
        if(arr[i] & setbit)
        {
            x = x^arr[i];
        }
        else
        {
            y = y^arr[i];
        }
    }
    cout << "x:" << x << endl << "y:" << y;

}

int main()
{
    int arr[] = {2,2,4,4,8,8,5,6,5,5};
    int size = 10;
    find_two_numbers_with_odd_occurences(arr, size);
    return 0;
}
