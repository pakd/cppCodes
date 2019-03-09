#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

void median_of_stream(double *arr,  int n)
{
   priority_queue<double> maxHeap;
   priority_queue<double, vector<double>, greater<double>> minHeap;

   double median = arr[0];
   maxHeap.push(arr[0]);

   cout << median << endl;

   for(int i=1;i<n;i++)
   {
       double x = arr[i];
       if(maxHeap.size() > minHeap.size())
       {
           if(x < median)
           {
               minHeap.push(maxHeap.top());
               maxHeap.pop();
               maxHeap.push(x);
           }
           else
           {
               minHeap.push(x);
           }

           median = (maxHeap.top() + minHeap.top())/2;
       }

       else if(maxHeap.size() == minHeap.size())
       {
           if(x < median)
           {
               maxHeap.push(x);
               median = maxHeap.top();
           }
           else
           {
               minHeap.push(x);
               median = minHeap.top();
           }
       }

       else
       {
           if(x < median)
           {
               maxHeap.push(x);

           }
           else
           {
               maxHeap.push(minHeap.top());
               minHeap.pop();
               minHeap.push(x);
           }

           median = (maxHeap.top() + minHeap.top())/2;
       }
       cout << median << endl;
   }
}

int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    median_of_stream(arr, size);

    return 0;
}
