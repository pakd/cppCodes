#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26
class Trie
{
public:
    bool isLeaf;
    Trie* children[ALPHABET_SIZE];
    Trie()
    {
        isLeaf = false;
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
    }

    void insert(string key)
    {
        Trie* curr = this; // start from root node

        for(auto it : key)
        {
            int index = it - 'a';
            if(curr->children[index] == NULL )
            {
                curr->children[index] = new Trie();
            }
            curr = curr->children[index];
        }

        // mark last node as leaf
        curr->isLeaf = true;
    }

    bool search(string key)
    {
        if(this == NULL) // if trie is empty
        {
            return false;
        }

        Trie* curr = this;

        for(auto it : key)
        {
            int index = it - 'a';
            if(curr->children[index] == NULL )
            {
                return false;
            }
            curr = curr->children[index];
        }

        return curr->isLeaf; // check last node as word or not
    }
};


int main()
{
    Trie* head = new Trie(); // head node

    head->insert("hello");
    head->insert("world");
    head->insert("deepak");
    head->insert("kumar");

    cout << head->search("deepak") << endl;
    cout << head->search("pakdee") << endl;

    return 0;
}
