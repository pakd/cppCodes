#include <iostream>
#include <vector>
#include <queue>

#define MAX_COUNT 1000

using namespace std;

vector<string> v;
void generateNumbersUtil()
{
    queue<string> Q;
    Q.push("9");
    v.push_back("9");

    int i=1;
    while(!Q.empty() && i < MAX_COUNT)
    {
        string temp = Q.front();
        Q.pop();
        v.push_back(temp);
        i++;


        Q.push(temp + "0");
        Q.push(temp + "9");
    }
}

string findSmallestMultiple(int n)
{

  for (int i = 0; i < v.size(); i++)
  {
      // stoi() is used for string to int conversion
      if (stoi(v[i])%n == 0)
      {
           return v[i];
      }
  }

}
int main()
{

    generateNumbersUtil();
    int n = 7;
    cout << findSmallestMultiple(n);
    return 0;
}
