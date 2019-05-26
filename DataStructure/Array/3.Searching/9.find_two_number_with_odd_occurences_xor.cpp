#include <iostream>

void find_two_numbers_with_odd_occurences(int *arr, int n)
{
    int xor2 = arr[0];
    for(int i =1; i< n;i++)
    {
        xor2 = xor2^arr[i];
    }

    /* Get one set bit in the xor2. We get rightmost set bit
        in the following line as it is easy to get */
    int setbit = xor2 & ~(xor2 -1);
    int x = 0;
    int y = 0;

    /* Now divide elements in two sets:
        1) The elements having the corresponding bit as 1.
        2) The elements having the corresponding bit as 0. */
    for(int i=0; i<n; i++)
    {
        /* XOR of first set is finally going to hold one odd
        occurring number x */
        if(arr[i] & setbit)
        {
            x = x^arr[i];
        }

        /* XOR of second set is finally going to hold the other
        odd occurring number y */
        else
        {
            y = y^arr[i];
        }
    }
    std::cout << "x:" << x << std::endl << "y:" << y;

}

int main()
{
    int arr[] = {2,2,4,4,8,8,5,6,5,5};
    int size = sizeof(arr)/sizeof(arr[0]);

    find_two_numbers_with_odd_occurences(arr, size);

    return 0;
}
