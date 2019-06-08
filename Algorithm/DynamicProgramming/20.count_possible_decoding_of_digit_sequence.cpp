#include <iostream>

int countDecoding(std::string input)
{
    int len = input.length();

    int *countArr = new int[len+1];

    countArr[0] = 1;
    countArr[1] = 1;

    for(int i=2; i<=len; i++)
    {
        countArr[i] = 0;

        if(input[i-1] > '0')
        {
            countArr[i] += countArr[i-1];
        }

        if(input[i-2] == '1' || (input[i-2]=='2' && input[i-1]<'6') )
        {
            countArr[i] += countArr[i-2];
        }
    }

    return countArr[len];

}

int main()
{
    std::string digits = "1234";
    std::cout << "Count is " << countDecoding(digits);
    return 0;
}
