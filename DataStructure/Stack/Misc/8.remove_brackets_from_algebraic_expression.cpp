#include <iostream>
#include <stack>

std::string removeBrackets(std::string str)
 {

     std::string ret = "";
     int len = str.length();

     std::stack<int> st;

     st.push(0); // means +

     for(int i=0; i<len; i++)
     {
         char temp = str[i];


         if(temp == '+')
         {
             if(st.top() == 0)
             {
                 ret += "+";
             }
             else
             {
                 ret+= "-";
             }
         }

         else if(temp == '-')
         {
            if(st.top() == 0)
             {
                 ret += "-";
             }
             else
             {
                 ret+= "+";
             }
         }

         else if(temp == '(')
         {
             if( i > 0 && str[i-1] == '-')
             {
                 int x = ( (st.top()) == 1)? 0:1;
                 st.push(x);
             }
             else if(str[i-1] == '+')
             {
                 st.push(st.top());
             }
         }

         else if(temp == ')')
         {
             st.pop();
         }

         else
         {
             ret += temp;
         }
     }

     return ret;
 }
 int main()
 {
     std::string s1 = "a-(b+c)";
     std::cout << removeBrackets(s1) << std::endl;


     std::string s2 = "a-(b-c-(d+e))-f";
     std::cout << removeBrackets(s2) << std::endl;

     return 0;
 }
