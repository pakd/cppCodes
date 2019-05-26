#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


void median_of_stream(double *arr,  int n)
{
   std::priority_queue<double> maxHeap;
   std::priority_queue<double, std::vector<double>, std::greater<double>> minHeap;

   double median = arr[0];
   maxHeap.push(arr[0]);

   std::cout << median << std::endl;

   for(int i=1; i<n; i++)
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
       std::cout << median << std::endl;
   }
}

int main()
{
    double arr[] = {5, 15, 10, 20, 3};
    int size = sizeof(arr)/sizeof(arr[0]);

    median_of_stream(arr, size);

    return 0;
}
