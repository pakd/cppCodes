#include <iostream>
#include <exception>
using namespace std;
class MyException:public exception
{
    // virtual function implemented
    virtual const char* what() const throw()
    {
        return "This is customized exception.";
    }
} myEx;
int main()
{
    try
    {
        string throwErr="this is error";
        throw myEx;
    }
    catch (exception& e)
    {
        cout <<e.what();
    }
}
