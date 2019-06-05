#include <iostream>

int gcd(int a, int b)
{
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if(a == b)
        return a;

    if(a > b)
        gcd(a - b, b);
    else
        gcd(a, b-a);
}

int gcd2(int a, int b)
{
    if(b==0)
        return a;
    gcd2(b, a%b);
}

int lcm(int a, int b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    std::cout << lcm(8,12) << std::endl;

    std::cout << gcd2(8,12) << std::endl;

    std::cout << gcd(8,12) << std::endl;

    return 0;
}
