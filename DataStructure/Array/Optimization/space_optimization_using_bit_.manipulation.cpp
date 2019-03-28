#include <iostream>
#include <cmath>
using namespace std;


// how to find index in array: divide by 32
// as one int = 4 byte
// 4 byte = 32 bit
// 32 indexes can be represented by single int
// arr[index >> 5] : divide by 32

// how to choose the bit
// take modulo by 32
// which is index & 31
// left shift by that no
// 1 << index & 31
bool checkbit(int *arr, int index)
{
    return arr[index >> 5] & (1 << (index & 31));
}


void setbit(int *arr, int index)
{
    arr[index >> 5] |= (1 << (index & 31));
}

int main()
{
    int a = 2, b = 10;
    int size = abs(b - a);

    // Size that will be used is actual_size/32
    // ceil is used to initialize the array with
    // positive number
    size = ceil(size / 32);

    // Array is dynamically initialized as
    // we are calculating size at run time
    int* array = new int[size];

    // Iterate through every index from a to b and
    // call setbit() if it is a multiple of 2 or 5
    for (int i = a; i <= b; i++)
        if (i % 2 == 0 || i % 5 == 0)
            setbit(array, i - a);

    cout << "MULTIPLES of 2 and 5:\n";
    for (int i = a; i <= b; i++)
        if (checkbit(array, i - a))
            cout << i << " ";

    return 0;
}
