#include <iostream>
#include <algorithm>
using namespace std;


void print_lcs(string a,string b, int m, int n)
{
   int L[m+1][n+1];
   for(int i=0;i<=m;i++)
   {
       for(int j=0;j<=n;j++)
       {
           if(i == 0 || j == 0)
           {
               L[i][j] = 0;
           }

           else if(a[i-1]==b[j-1])
           {

               L[i][j] = L[i-1][j-1] + 1;
           }
           else
            L[i][j] = max(L[i][j-1],L[i-1][j]);
       }
   }

   string lcs;
   int i=m,j=n;
   while(i>=0 && j>=0)
   {

       if(a[i-1] == b[j-1])
       {
           string d(1,a[i-1]);
           lcs.insert(0,d);
           i--;j--;
       }
       else if(L[i-1][j]>L[i][j-1])
       {
           i--;
       }
       else j--;
   }
    cout << lcs;
}
int main()
{
    string a = "AGGTAB";
    string b = "GXTXAYB";
    print_lcs(a,b,a.length(),b.length());

}
