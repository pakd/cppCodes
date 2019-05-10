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
        //cout << key << endl;
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


    void insertAll(string key)
    {
        for(int i=0; i<key.length(); i++)
        {
            insert(key.substr(i));
        }
    }

    void insertAllSuffixes(string key)
    {
        for(int i=0; i<key.length(); i++)
        {
            insertAll(key.substr(i));
        }
    }



    int noOfNodes = 0;

    int size(Trie* node)
    {

        if(!node)
        {
            return 0;
        }

        noOfNodes++;

        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            size(node->children[i]);
        }
    }

    int getSize()
    {
        // check if this pointer is null, then return 0
        Trie* head = this;
        size(head);
        return noOfNodes;
    }
};


int main()
{
    Trie* head = new Trie(); // head node

    head->insertAllSuffixes("ababa");

    cout << head->getSize() << endl; // 10 , including empty node

    return 0;
}
