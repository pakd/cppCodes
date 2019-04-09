#include <iostream>
#include <queue>


using namespace std;

int minimumIndex(queue<int> &q, int sortedIndex)
{
    int minIndex = -1;
    int minValue = INT_MAX;

    int n = q.size();

    for(int i=0; i<n; i++)
    {
        int temp = q.front();
        q.pop();

        if( temp <= minValue && i <= sortedIndex)
        {
            minValue = temp;
            minIndex = i;
        }

        q.push(temp);
    }

    return minIndex;
}

void insertMinToRear(queue<int> &q, int min_index)
{
    int minValue;

    int n = q.size();

    for(int i=0; i<n; i++)
    {
        int temp = q.front();
        q.pop();

        if(i == min_index)
        {
            minValue = temp;
        }
        else
        {
            q.push(temp);
        }
    }

    // push value at ith index at rear of queue
    q.push(minValue);
}



void sortQueue(queue<int> &q)
{
    for (int i = 1; i <= q.size(); i++)
    {
        int min_index = minimumIndex(q, q.size() - i); // index starts from 0 in queue
        insertMinToRear(q, min_index);
    }
}

// driver code
int main()
{
  queue<int> q;

  q.push(30);
  q.push(11);
  q.push(15);
  q.push(4);

  // Sort queue
  sortQueue(q);

  // Print sorted queue
  while (!q.empty())
  {
     cout << q.front() << " ";
     q.pop();
  }
  cout << endl;
  return 0;
}
