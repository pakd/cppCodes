#include <iostream>
using namespace std;
// template definition cannot appear in a block.
template <typename T>
T AddTwoNums(T first, T second)
{
    return first+second;
}
int main()
{
    cout << AddTwoNums(2.5,3.4) << endl;
    cout << AddTwoNums(12,38);
}
