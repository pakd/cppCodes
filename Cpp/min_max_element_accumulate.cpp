#include <iostream>
#include <algorithm> // min_element, max_element
#include <numeric> // accumulate
using namespace std;
int main()
{
    int arr[] = {1, 2, 4, 8,  16, 24};
    cout << "min element: " << *min_element(arr, arr + 6) << endl; // returns pointer
    cout << "max element: " << *max_element(arr, arr + 6) << endl; // returns pointer
    cout << "accumulate: "  << accumulate(arr, arr + 6, 0) << endl;
}
