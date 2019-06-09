#include <iostream>
#include <stack>

std::string decode(std::string input)
{
    std::string ret = "";

    std::stack<int> intSt;
    std::stack<char> charSt;

    int len = input.length();

    for(int i=0; i<len; i++)
    {
        char t = input[i];

        if( t >= '0' && t <= '9')
        {
            intSt.push(t - '0');
        }

        else if(t  == '[')
        {
            charSt.push(t);
        }

        else if(t == ']')
        {
            std::string temp = "";
            while(charSt.top() != '[')
            {
                temp += charSt.top();
                charSt.pop();
            }

            charSt.pop();
            int count = intSt.top();
            intSt.pop();

            for(int i=0; i<count; i++)
            {
                for(int j=temp.length()-1; j>=0; j--)
                {
                    charSt.push(temp[j]);
                }
            }
        }
        else
        {
            charSt.push(t);
        }
    }

    while(!charSt.empty())
    {
        ret = charSt.top() + ret;
        charSt.pop();
    }

    return ret;

}

int main()
{
    std::string str = "3[b2[ca]]";
    std::cout << decode(str) << std::endl;

    std::string str2 = "2[a2[b]]";
    std::cout << decode(str2) << std::endl;

    return 0;
}
