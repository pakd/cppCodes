#include <iostream>
#include <set>
using namespace std;

#define ALPHABET_SIZE 26
class Trie
{
public:
    bool isLeaf;
    set<int> indexes;
    Trie* children[ALPHABET_SIZE];
    Trie()
    {
        isLeaf = false;
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
    }

    void insert(string key, int ind)
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
            curr->indexes.insert(ind);
            curr = curr->children[index];

        }

        // mark last node as leaf
        curr->isLeaf = true;
        curr->indexes.insert(ind); // for last

    }


    void insertAll(string key, int index)
    {
        for(int i=0; i<key.length(); i++)
        {
            insert(key.substr(i), index + i);
        }
    }

    void insertAllSuffixes(string key)
    {
        for(int i=0; i<key.length(); i++)
        {
            insertAll(key.substr(i), i);
        }
    }

    bool search(string key)
    {
        cout << "search key: " << key << endl;
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


        for(auto x : curr->indexes)
        {
            cout << x << "\t";
        }
        cout << endl;
        return curr->isLeaf; // check last node as word or not
    }
};


int main()
{
    Trie* head = new Trie(); // head node

    // Let us build a suffix trie for text "geeksforgeeks.org"
    string txt = "geeksforgeeks.org";

    head->insertAllSuffixes(txt);

    head->search("geek"); // 0 8
    head->search("forgeeks");
    head->search("quiz"); // nil
    head->search("ee"); // 1 9

    return 0;
}
