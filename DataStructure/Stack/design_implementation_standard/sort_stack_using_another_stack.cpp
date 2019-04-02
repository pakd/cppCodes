#include <iostream>
#include <stack>
using namespace std;

stack<int> sortStack(stack<int>& input)
{
    stack<int> tmpStack;

    while(!input.empty())
    {
        int temp = input.top();
        input.pop();

        while(!tmpStack.empty() && tmpStack.top() > temp)
        {
            input.push(tmpStack.top());
            tmpStack.pop();
        }
        tmpStack.push(temp);
    }

    return tmpStack;
}


int main()
{
    stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);

    stack<int> res = sortStack(input);

    while(!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
    }

    return 0;
}
