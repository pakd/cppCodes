#include <iostream>
using namespace std;
/*
The major difference between inline functions and macros is the way they are handled.
Inline functions are parsed by the compiler, whereas macros are expanded by the C++ preprocessor.
This difference creates other differences, as best illustrated by examples.
*/
inline int square(int n)
{
    return n*n;
}

int main()
{
    cout << square(5);
}
