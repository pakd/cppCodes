#include <iostream>
using namespace std;

#define ALPHABET_SIZE 26
class Trie
{
public:
    bool isLeaf;
    Trie* children[ALPHABET_SIZE];
    int frequency;
    Trie()
    {
        isLeaf = false;
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
        frequency = 0;
    }

    void insert(string key)
    {
        Trie* curr = this; // start from root node

        int index = 0;
        for(auto it : key)
        {
            index = it - 'a';
            if(curr->children[index] == NULL )
            {
                curr->children[index] = new Trie();
            }
            curr = curr->children[index];
            curr->frequency++;

            //cout << char(index + 'a') << " " <<curr->frequency << endl;
        }

        // mark last node as leaf
        curr->isLeaf = true;
        curr->frequency++; // for last node
    }

    void shortest_unique_prefix(Trie* node, string prefix)
    {
        if(node == NULL)
        {
            return;
        }
        if(node->frequency == 1 || node->isLeaf)
        {
            cout << prefix << endl;
            return;
        }

        for(int i=0; i < ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                shortest_unique_prefix(node->children[i], prefix + char(i + 'a'));
            }
        }
    }
};


int main()
{
    Trie* head = new Trie(); // head node

    //string arr[] = {"zebra", "dog", "duck", "dove"}; // dog, dov, du, z
    string arr[] = {"geeksgeeks", "geeksquiz", "geeksforgeeks"}; // geeksf, geeksg, geeksq

    for(auto x : arr)
    {
        head->insert(x);
    }

    head->shortest_unique_prefix(head, "");

    return 0;
}
