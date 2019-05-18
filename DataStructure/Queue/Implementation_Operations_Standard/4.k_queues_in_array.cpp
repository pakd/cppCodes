#include <iostream>
using namespace std;

class kQueuesImpl
{
public:

    int *arr;        // array which which store queue elements
    int *frontIndex; // array which store front index of all queues
    int *rearIndex;  // array which store rare index of all queues
    int *next;       // array which will store next free slots and previous queue element
    int free;        // next free slot/cell
    int n;           // size of array
    int k;           // no of queues

    kQueuesImpl(int n1 , int k1) // constructor for initializing the queues and preprocessing
    {
        n = n1;
        k = k1;
        arr = new int[n];
        frontIndex = new int[k];
        rearIndex = new int[k];
        next = new int[n];

        for(int i=0; i<k; i++)
        {
            frontIndex[i] = -1;
        }

        for(int i=0; i<n-1; i++)
        {
            next[i] = i + 1;
        }
        next[n-1] = -1;

        free = 0;
    }

    void enqueue(int queueNo, int elem)
    {
        if(free == -1)
        {
            cout << "queue overflow" << endl;
            return ;
        }

        int i = free;
        free = next[i]; // point to next free slot

        // if first time
        if(frontIndex[queueNo] == -1)
        {
            frontIndex[queueNo] = i;
        }
        else
        {
            next[rearIndex[queueNo]] = i;
        }

        arr[i] = elem; // insert element

        next[i] = -1;  // points to last element in the queue

        rearIndex[queueNo] = i; // store index of new rear

    }

    int dequeue(int queueNo)
    {
        if(frontIndex[queueNo] == -1)
        {
            cout << "queue underflow" << endl;
            return INT_MAX;
        }

        int i  = frontIndex[queueNo];   // store index of top of stack
        frontIndex[queueNo] = next[i]; // store new front

        next[i] = free;   // one slot is free now
        free = i; // add one new slot to free

        return arr[i]; // return popped element
    }
};


int main()
{
    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    kQueuesImpl ks(n,k);

    // Let us put some items in queue number 2
    ks.enqueue(2, 15);
    ks.enqueue(2, 45);

    // Let us put some items in queue number 1
    ks.enqueue(1, 17);
    ks.enqueue(1, 49);
    ks.enqueue(1, 39);

    // Let us put some items in queue number 0
    ks.enqueue(0, 11);
    ks.enqueue(0, 9);
    ks.enqueue(0, 7);

    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;

    return 0;
}
