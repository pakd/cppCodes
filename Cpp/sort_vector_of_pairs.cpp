#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<pair <int,int>> dpk;
    dpk.push_back(make_pair(2,1));
    dpk.push_back(make_pair(6,2));
    dpk.push_back(make_pair(1,5));
    dpk.push_back(make_pair(8,9));
    sort(dpk.begin(),dpk.end());
    for(int i=0;i<dpk.size();i++)
    {

        cout << dpk[i].first << " " <<dpk[i].second << endl;
    }
}
