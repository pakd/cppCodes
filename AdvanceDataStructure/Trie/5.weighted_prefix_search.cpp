#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26
class Trie
{
public:
    bool isLeaf;
    Trie* children[ALPHABET_SIZE];
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

    void insert(string key, int keyWeight)
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
        curr->weight = keyWeight;
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

    void weightedSearchUtil(Trie* node, string prefix, int &maxWeight)
    {
        if(!node) // sanity check
        {
            return;
        }

        if(node->isLeaf)
        {
            cout << prefix << endl;
            if (node->weight > maxWeight)
            {
                maxWeight = node->weight;
            }
        }

        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                weightedSearchUtil(node->children[i], prefix + char(i + 'a'), maxWeight);
            }
        }
    }

    int weightedSearch(string str)
    {
        if(this == NULL) // if trie is empty
        {
            return 0;
        }

        Trie* curr = this;
        string prefix = "";
        for(auto it: str)
        {
            int index = it - 'a';
            if(!curr->children[index])
            {
                return 0;
            }

            curr = curr->children[index];
            prefix += it;
        }

        int maxWeight = 0;
        weightedSearchUtil(curr, prefix, maxWeight);

        return maxWeight;

    }

};


int main()
{
    pair<string, int> words[] = { {"geeks", 15}, {"geeksfor", 30}, {"geeksforgeeks", 45}};

    Trie* head = new Trie();

    for (auto itr : words)
    {
        head->insert(itr.first, itr.second);
    }

    string Query = "geek";
    cout << head->weightedSearch(Query);

    return 0;
}
