#include <iostream>
#include <vector>
using namespace std;

void printPrime(int n)
{
    vector<bool> prime(1001, true);


    for(int i=2; i*i <= n; i++)
    {
        if(prime[i] == true)
        {
            for(int j=i*i; j<=n ; j+= i)
            {
                prime[j] = false;
            }
        }
    }

    for(int i=2; i<=n; i++)
    {
        cout << i << " " << prime[i] << endl;
    }
}
int main()
{
    int n = 1000;
    printPrime(n);
    return 0;
}
