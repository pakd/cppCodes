#include <iostream>
#include <stack>

std::stack<int> sortStack(std::stack<int>& input)
{
    std::stack<int> tmpStack;

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
    std::stack<int> input;
    input.push(34);
    input.push(3);
    input.push(31);
    input.push(98);
    input.push(92);
    input.push(23);

    std::stack<int> res = sortStack(input);

    while(!res.empty())
    {
        std::cout << res.top() << " ";
        res.pop();
    }

    return 0;
}
