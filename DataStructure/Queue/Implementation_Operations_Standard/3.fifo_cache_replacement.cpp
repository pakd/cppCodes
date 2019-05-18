#include <iostream>

#include <unordered_set>
#include <queue>
using namespace std;

/*
Belady’s anomaly –
Belady’s anomaly proves that it is possible to have more page faults when increasing the number of page frames
while using the First in First Out (FIFO) page replacement algorithm. For example, if we consider reference
string 3, 2, 1, 0, 3, 2, 4, 3, 2, 1, 0, 4 and 3 slots, we get 9 total page faults,
but if we increase slots to 4, we get 10 page faults.
*/
class FiFoCacheImp
{
public:

    queue<int> Q;
    unordered_set<int> inMemory;
    int cacheSize;

    int pageFault = 0;

    FiFoCacheImp(int size)
    {
        cacheSize = size;
    }

    void refer(int page)
    {
        // if cache is not full
        if(inMemory.size() < cacheSize)
        {
            // page not found in memory
            if(inMemory.find(page)==inMemory.end())
            {
                // insert new page
                inMemory.insert(page);
                Q.push(page);

                pageFault++;
            }
        }

        // if cache is full
        else
        {
            // page not found in memory
            if(inMemory.find(page)==inMemory.end())
            {
                int front = Q.front();
                Q.pop();

                inMemory.erase(front);

                // insert new page
                inMemory.insert(page);
                Q.push(page);

                pageFault++;
            }
        }
    }

    void displayPages()
    {
        // display list
        while(!Q.empty())
        {
            cout << Q.front() << " ";
            Q.pop();
        }
        cout << endl;
    }

    int getPageFault()
    {
        return pageFault;
    }
};


int main()
{
    int pages[] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};
    int n = sizeof(pages)/sizeof(pages[0]);
    int capacity = 4;


    FiFoCacheImp cache(capacity);

    for(int i=0; i<n; i++)
    {
        cache.refer(pages[i]);
    }

    cache.displayPages();

    cout << cache.getPageFault() << endl;

    return 0;

}
