#include <iostream>
#include <stack>
 using namespace std;


 string removeBrackets(string str)
 {

     string ret = "";
     int len = str.length();

     stack<int> st;

     st.push(0);

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
     string s1 = "a-(b+c)";
     cout << removeBrackets(s1) << endl;


     string s2 = "a-(b-c-(d+e))-f";
     cout << removeBrackets(s2) << endl;

     return 0;
 }
