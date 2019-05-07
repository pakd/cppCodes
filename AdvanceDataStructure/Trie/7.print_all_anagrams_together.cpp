#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ALPHABET_SIZE 26

class Trie
{
public:
    bool isLeaf;
    Trie* children[ALPHABET_SIZE];
    vector<string> anagrams;
    int weight;
    Trie()
    {
        isLeaf = false;
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
        weight = 0;
    }

    void insert(string keySorted, string key)
    {
        Trie* curr = this; // start from root node

        for(auto it : keySorted)
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
        curr->anagrams.push_back(key);
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




    void printAnagrams(Trie* node)
    {
        // not required as you will not call this function for null nodes
        /* if(!node)
        {
            return;
        }*/

        if(node->isLeaf)
        {
            for(int i=0; i< node->anagrams.size(); i++)
            {
                cout << node->anagrams[i] << " ";
            }
            cout << endl;
        }

        for(int i=0; i < ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                printAnagrams(node->children[i]);
            }

        }
    }
};


int main()
{
    string wordArr[] = {"cat", "dog", "tac", "god", "act", "gdo"};

    Trie* head = new Trie();

    string copy;
    for (auto itr : wordArr)
    {
        copy = itr;
        sort(itr.begin(), itr.end());
        // cout << copy << " " << itr << endl;
        head->insert(itr, copy);
    }

    head->printAnagrams(head);

    return 0;
}
