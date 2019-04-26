#include <iostream>
#include <algorithm>
using namespace std;



struct Box
{
    int height;
    int width;
    int length;
};

// compare function of decreasing order of base area
bool compare(Box a, Box b)
{
    return (a.width * a.length > b.width * b.length);
}

int maxStackHeight( Box *arr, int n)
{
    Box boxComb[3*n];

    int index = 0;

    // generating all combination of boxes
    // lets have length > width always
    for(int i=0; i<=n ; i++)
    {

        // Copy the original box
        boxComb[index].height = arr[i].height;
        boxComb[index].length = max(arr[i].length, arr[i].width);
        boxComb[index].width = min(arr[i].length, arr[i].width);
        index++;

        // first rotation
        boxComb[index].height = arr[i].length;
        boxComb[index].length = max(arr[i].height, arr[i].width);
        boxComb[index].width = min(arr[i].height, arr[i].width);
        index++;

        // second rotation
        boxComb[index].height = arr[i].width;
        boxComb[index].length = max(arr[i].height, arr[i].length);
        boxComb[index].width = min(arr[i].height, arr[i].length);
        index++;

    }

    int len = n*3;

    // sort in decreasing order of base area of box
    sort(boxComb, boxComb + 3*n, compare);

    for(int i=0; i< 3*n; i++)
    {
        cout << boxComb[i].height << " " << boxComb[i].width << " " << boxComb[i].length
        << " " << boxComb[i].width * boxComb[i].length <<  endl;
    }


    // maximum stack height array
    int msh[len];

    for(int i = 0; i < len; i++)
    {
        msh[i] = boxComb[i].height;
    }

    for(int i=1; i<len; i++)
    {
        for(int j=0; j<i; j++)
        {
            if( boxComb[i].width < boxComb[j].width &&
                boxComb[i].length < boxComb[j].length &&
                msh[i] < msh[j] + boxComb[i].height)
            {
                msh[i] = msh[j] + boxComb[i].height;
            }
        }
    }

    int maxHeight = INT_MIN;

    for(int i=0; i< len; i++)
    {
        if(maxHeight < msh[i])
        {
            maxHeight = msh[i];
        }
    }

    return maxHeight;

}




int main()
{
  Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} };
  int size = sizeof(arr)/sizeof(arr[0]);

  cout << "The maximum possible height of stack is " << maxStackHeight (arr, size);

  return 0;
}
