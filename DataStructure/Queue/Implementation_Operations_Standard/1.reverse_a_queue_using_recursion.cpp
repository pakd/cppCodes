#include <iostream>
#include <queue>
using namespace std;

queue <int> Queue;

void reverseQueue()
{
    if(Queue.empty())
    {
        return;
    }

    int item = Queue.front();
    Queue.pop();

    reverseQueue();

    Queue.push(item);


}
void printQueue()
{
    while(!Queue.empty())
    {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

int main()
{
    Queue.push(1);
    Queue.push(2);
    Queue.push(3);
    Queue.push(4);
    Queue.push(5);
    Queue.push(6);
    Queue.push(7);
    Queue.push(8);
    Queue.push(9);
    Queue.push(10);

    reverseQueue();

    printQueue();

    return 0;
}
