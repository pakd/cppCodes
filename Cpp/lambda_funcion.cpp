#include <iostream>
using namespace std;
int main()
{
    int i=10;
    // & means all references above code
    auto AddFunc =[&](int a,int b) -> int {
        return a + b + i;
    };

    cout <<AddFunc(5,5);
}
