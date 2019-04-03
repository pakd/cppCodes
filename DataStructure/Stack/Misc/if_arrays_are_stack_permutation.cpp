#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool checkStackPermutation(int *input, int *output, int n)
{
    // input queue
    queue <int> in;
    for(int i=0; i<n; i++)
    {
        in.push(input[i]);
    }

    // output queue
    queue <int> out;
    for(int i=0; i<n; i++)
    {
        out.push(output[i]);
    }

    stack<int> tmpStack;

    while(!in.empty())
    {
        int temp = in.front();
        in.pop();


        if( temp == out.front())
        {
            out.pop();

            while(!tmpStack.empty())
            {
                if(tmpStack.top() == out.front())
                {
                    tmpStack.pop();
                    out.pop();
                }
                else
                {
                    break;
                }
            }

        }
        else
        {
            tmpStack.push(temp);
        }
    }

    return (in.empty() && tmpStack.empty());
}

int main()
{
    // Input Queue
    int input[] = {1, 2, 3};

    // Output Queue
    //int output[] = {3,1,2}; // not possible
    int output[] = {2, 1, 3}; // yes

    int n = 3;

    if (checkStackPermutation(input, output, n))
        cout << "Yes";
    else
        cout << "Not Possible";
    return 0;
}
