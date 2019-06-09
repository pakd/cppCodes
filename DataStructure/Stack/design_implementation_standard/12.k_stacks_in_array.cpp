#include <iostream>

class kStacks
{
public:

    int *arr; // array which which store stack elements
    int *top; // array which store top index of all stacks
    int *next; // array which will store next free slots and previous stack element
    int free; // next free slot/cell
    int n; // size of array
    int k; // no of stacks

    kStacks(int n1 , int k1) // constructor for initializing the stacks and preprocessing
    {
        n = n1;
        k = k1;
        arr = new int[n];
        top = new int[k];
        next = new int[n];

        for(int i=0; i<k; i++)
        {
            top[i] = -1;
        }

        for(int i=0; i<n-1; i++)
        {
            next[i] = i + 1;
        }
        next[n-1] = -1;

        free = 0;
    }

    void push(int stackNo, int elem)
    {
        if(free == -1)
        {
            std::cout << "stack overflow" << std::endl;
            return ;
        }

        int i = free;
        free = next[i]; // point to next free slot

        arr[i] = elem; // insert element

        next[i] = top[stackNo];  // store previous of stack in next[i]
        top[stackNo] = i; // store index of new top

    }

    int pop(int stackNo)
    {
        if(top[stackNo] == -1)
        {
            std::cout << "stack underflow" << std::endl;
            return INT_MAX;
        }

        int i  = top[stackNo];   // store index of top of stack
        top[stackNo] = next[i]; // store new top

        next[i] = free;   // one slot is free now
        free = i; // add one new slot to free

        return arr[i]; // return popped element
    }
};


int main()
{
    int k = 3;
    int n = 10;

    kStacks ks(n, k);

    // Let us put some items in stack number 2
    ks.push(2, 15);
    ks.push(2, 45);

    // Let us put some items in stack number 1
    ks.push(1, 17);
    ks.push(1, 49);
    ks.push(1, 39);

    // Let us put some items in stack number 0
    ks.push(0, 11);
    ks.push(0, 9);
    ks.push(0, 7);

    std::cout << "Popped element from stack 2 is " << ks.pop(2) << std::endl;
    std::cout << "Popped element from stack 1 is " << ks.pop(1) << std::endl;
    std::cout << "Popped element from stack 0 is " << ks.pop(0) << std::endl;

    return 0;
}
