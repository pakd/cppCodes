#include <iostream>
#include <vector>
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

    void findWordsUtil(Trie* node, string prefix, vector<bool> &hash)
    {
        if(node->isLeaf)
        {
            cout << prefix << endl;
        }
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            if(node->children[i] && hash[i])
            {
                prefix += char(i + 'a');
                findWordsUtil(node->children[i], prefix, hash);
            }
        }
    }
    void findWords(char *arr, int n)
    {
        if(this == NULL) // sanity check
            return;
        Trie* curr = this;

        string prefix = "";

        vector<bool> hash(ALPHABET_SIZE, false);

        for(int i=0;i<n;i++)
        {
            hash[arr[i] - 'a'] = true;
        }

        for(int i=0; i<n; i++)
        {
            int index = arr[i] - 'a';
            if(hash[index] && curr->children[index])
            {
                prefix += arr[i];
                curr = curr->children[index];
                findWordsUtil(curr, prefix, hash);
            }
            curr = this;
            prefix = "";
        }
    }

};


int main()
{
    string words[] = { "go", "bat", "me", "eat", "goal", "boy", "run"};

    Trie* head = new Trie();

    for (auto itr : words)
    {
        head->insert(itr);
    }

    char arr[] = {'e', 'o', 'b', 'a', 'm', 'g', 'l'} ;
    int size = sizeof(arr)/sizeof(arr[0]);
    head->findWords(arr, size);

    return 0;
}
