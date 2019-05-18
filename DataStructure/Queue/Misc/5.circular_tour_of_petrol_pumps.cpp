#include <iostream>
#include <queue>

using namespace std;


struct petrolPump
{
  int petrol;
  int distance;
};


int printTour(petrolPump *arr, int n)
{
    int start = 0;
    int end = 1; // not included end, if start == end then possible

    // start with 0th petrol pump
    int curr_petrol = arr[start].petrol - arr[start].distance;

    // end == start that means all petrol pump traversed

    int total_pump = 1;
    while(total_pump < n)
    {
        while(curr_petrol < 0 && total_pump < n)
        {
            // Remove starting petrol pump. Change start
            curr_petrol -= (arr[start].petrol - arr[start].distance);
            start = (start + 1)%n;

            total_pump--;
            // if start == 0 again then there is no solution
            if(start == 0)
                return -1;
        }

        // Add a petrol pump to current tour
        curr_petrol += arr[end].petrol - arr[end].distance;
        end = (end + 1)%n;
        total_pump++;
    }

    return start;
}

int main()
{

    petrolPump arr[] =  {{4, 6}, {6, 5}, {7, 3}, {4, 5}}; // start = 11
    // petrolPump arr[] =  {{3,6}, {7,8}, {9,10}}; // no solution
    // petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}}; // start = 2

    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);

    (start == -1)? printf("No solution"): printf("Start = %d", start);

    return 0;
}
