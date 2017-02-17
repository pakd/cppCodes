#include <iostream>
#include <algorithm> // for sort
#include <vector> // for vector
using namespace std;
int main()
{
    /*
    cpp sort which is part of algorithm can sort array as well as std::vector.
    */
    int myArr[]={5,-6,7,23,4};
    int arrLen = 5;
    sort(myArr,myArr+arrLen);
    for (int i=0;i<arrLen;i++)
    {
        cout << myArr[i] << " ";
    }

    cout <<endl;

    int myArrVector[]={45,2,3,-1,9};
    int myArrVectorLen = 5;
    vector<int> arrVec(myArrVector, myArrVector + myArrVectorLen);
    sort(arrVec.begin(),arrVec.end());
    for (int i=0;i<arrVec.size();i++)
    {
        cout << arrVec[i] << " ";
    }
}
