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

    void DisplayContactsUtil(Trie* node, string prefix)
    {
        if(!node) // sanity check
        {
            return;
        }

        if(node->isLeaf)
        {
            cout << prefix << endl;
        }

        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                DisplayContactsUtil(node->children[i], prefix + char(i + 'a'));
            }
        }
    }

    void DisplayContacts(string str)
    {
        string prefix = "";
        if(this == NULL)
        {
            return;
        }
        Trie* curr = this;

        for(auto it : str)
        {
            int index = it - 'a';
            if(curr->children[index] == NULL )
            {
                cout << "-----" << endl;
                return;
            }
            curr = curr->children[index];
            prefix += it;
            //cout << prefix << endl;
        }

        DisplayContactsUtil(curr, prefix);
    }


};


int main()
{

    string contacts [] = {"mohan", "mohanlal", "mohani", "sohan", "sara", "alan", "alanwest" };

    Trie* head = new Trie(); // head node

    for (auto wordsIt : contacts)
    {
        head->insert(wordsIt);
    }

    string Query = "moh";
    //string Query = "z" // ans  = "-----"
    head->DisplayContacts(Query);

    return 0;
}
