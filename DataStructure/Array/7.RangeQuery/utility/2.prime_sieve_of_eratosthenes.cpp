#include <iostream>
#include <vector>

void printPrime(int n)
{
    std::vector<bool> prime(1001, true);

    for(int i=2; i*i <= n; i++)
    {
        if(prime[i] == true)
        {
            for(int j=i*i; j<=n ; j+=i)
            {
                prime[j] = false;
            }
        }
    }
    for(int i=2; i<=n; i++)
    {
        std::cout << i << " " << prime[i] << std::endl;
    }
}
int main()
{
    int n = 1000;
    printPrime(n);
    return 0;
}
