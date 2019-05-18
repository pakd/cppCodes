#include <iostream>

#include <deque>
#include <unordered_map>
using namespace std;


class LRUCacheImp
{
public:

    deque<int> dq;
    // list<int>::iterator :: pointer to page with value v in list Q
    unordered_map<int, deque<int>::iterator> inMemory;
    int cacheSize;

    LRUCacheImp(int size)
    {
        cacheSize = size;
    }

    void refer(int page)
    {
        // if page is not in memory
        if(inMemory.find(page)==inMemory.end())
        {
            // size is cache is also full
            if(dq.size() == cacheSize)
            {
                // delete last element from queue
                int last = dq.back();
                dq.pop_back();
                inMemory.erase(last);
            }
        }

        // if page is in memory, delete it from the middle and add it to the beginning
        else
        {
            // inMemory[page] pointer to page, which we have to delete
            dq.erase(inMemory[page]);
        }

        dq.push_front(page);
        inMemory[page] = dq.begin();
    }

    void displayPages()
    {
        // display list
        for(auto i = dq.begin(); i!=dq.end(); i++)
        {
            cout << *i << " ";
        }
        cout << endl;
    }
};


int main()
{
    LRUCacheImp cache(4);

    cache.refer(1);
    cache.refer(2);
    cache.refer(3);
    cache.refer(1);
    cache.refer(4);
    cache.refer(5);
    cache.displayPages();

    return 0;

}
