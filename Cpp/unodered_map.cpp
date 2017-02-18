#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    unordered_map<string,int> dpk;
    int t;
    cin>>t;
    int n=t;
    while(n--)
    {
        string name;
        int number;
        cin >> name;
        cin >> number;
        dpk.insert({name,number});
    }

    unordered_map<string,int>::iterator it;

     while(t--)
     {
         string input;
         cin>>input;
         it=dpk.find(input);
         if(it!=dpk.end())
         {
             cout<<it->first <<"=" << it->second<<endl;
         }
         else
         {
             cout <<"Not found"<<endl;
         }
     }

}
