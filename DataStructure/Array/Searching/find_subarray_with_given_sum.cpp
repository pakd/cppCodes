#include <iostream>
using namespace std;

void find_subarray_with_given_sum(int *arr, int n, int sum)
{
    int i=0, j =0;
    int curr_sum = 0;
    while(j < n)
    {
        if(curr_sum ==sum)
        {
            cout << "i: " << i << endl << "j: " << j -1 << endl;
            for(int k = i;k <j;k++)
            {
                cout << arr[k]<< "\t";
            }
            return;
        }
        else if(curr_sum < sum)
        {
            curr_sum += arr[j];
            j++;
        }
        else
        {
            curr_sum -= arr[i];
            i++;
        }
    }

}

int main()
{
    int arr[] = {1,4,20,3,10,5};
    int size = 6;
    int sum = 33;
    find_subarray_with_given_sum(arr, size, sum);
    return 0;
}
