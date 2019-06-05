#include <iostream>

int smallestSum(int *arr, int n)
{
   int res = 1;

   for(int i = 0; i< n && arr[i] <= res; i++)
   {
       res+=arr[i];
   }
   return res;
}

int main()
{
    int arr[] = {1, 3, 6, 10, 11, 15};
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout << smallestSum(arr, n); // sum = 2 is missing
    return 0;
}
