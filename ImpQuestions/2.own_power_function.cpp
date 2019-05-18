#include<iostream>
using namespace std;

int findPower(int p, int q)
{
    if( q == 0) return 1;

    else if(q%2 == 0) // even
    {
        return findPower(p, q/2) * findPower(p, q/2);
    }
    else // odd
    {
        return p*findPower(p, q-1);
    }

}

// avoiding re calculation
int findPowerOptimized(int p, int q)
{
    if( q == 0) return 1;

    int temp = findPower(p, q/2);

    if(q%2 == 0) // even
    {
        return temp * temp;
    }
    else // odd
    {
        return p*temp*temp;
    }

}

int main()
{
    int p = 2;
    int q = 11;

    cout << findPower(p, q) << endl;
    cout << findPowerOptimized(p,q) << endl;

}
