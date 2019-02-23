#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// comp function to form the biggest number
int comp(string A, string B)
{
    string AB = A.append(B);
    string BA = B.append(A);
    return ((AB.compare(BA)) > 0? 1:0 );

}

int main()
{
    vector<string> arr;

    arr.push_back("5");
    arr.push_back("98");
    arr.push_back("9");
    arr.push_back("978");

    sort(arr.begin(), arr.end(), comp);

    for(int i=0;i<arr.size();i++)
    {
        cout << arr[i] << "\t";
    }
}
