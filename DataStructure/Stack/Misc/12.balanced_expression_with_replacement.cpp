#include <iostream>
#include <stack>

int isMatching(char a, char b)
{
    if ((a == '{' && b == '}') ||
        (a == '[' && b == ']') ||
        (a == '(' && b == ')') ||
         a == 'X')
        return 1;
    return 0;
}

// recursive function for checking balanced expression
bool isBalanced(std::string input, std::stack<char> st, int index )
{
    if(index == input.length())
    {
        return (st.empty());
    }
    char t = input[index];

    // case 1 : just push in st and move to next index
    if (t == '{' || t == '(' || t == '[')
    {
        st.push(t);
        return isBalanced(input, st, index + 1);
    }

    // case 2 : pop case, if st.top() == 'X' or matching bracket
    // assume 'X' as opening bracket and move to next index
    else if(t== '}' || t == ')' || t == ']')
    {
        if(st.empty())
        {
            return false;
        }
        else
        {
            char top = st.top();
            st.pop();

            if(!isMatching(top, t))
            {
                return false;
            }

            return isBalanced(input, st, index + 1);

        }
    }

    // case 3: 'X' can be opening bracket or closing bracket
    else if(t == 'X')
    {
        // treat 'X' as opening bracket, push to st and call recursion
        // copy stack
        std::stack<char> tmp = st;
        tmp.push(t);
        bool res = isBalanced(input, tmp, index + 1);

        // if 'X' is opening bracket and expression is balanced
        // no need to check other possibility
        if(res)
        {
            return true;
        }

        // if 'X' is opening bracket and expression is not balanced
        // now try 'X' as closing bracket
        if(st.empty())
        {
            return false;
        }

        // matching to st.top()
        st.pop();

        return isBalanced(input, st, index + 1);

    }
}

int main()
{

    std::string s = "{(X}[]"; // balanced

    // string s = "[{X}(X)]"; // not balanced

    std::stack<char> ele;
    if (isBalanced(s, ele, 0))
        std::cout << "Balanced";
    else
        std::cout << "Not Balanced";

    return 0;
}
