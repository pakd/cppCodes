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

    string getLongestPrefix(string key)
    {
        string ans = "";
        string prevMatch = "";

        // if trie is empty
        if(this == NULL)
        {
            return "";
        }

        Trie* curr = this;


        for(auto it : key)
        {
            int index = it - 'a';
            if(curr->children[index] == NULL )
            {
                return prevMatch;
            }

            ans += it;


            curr = curr->children[index];
            if(curr->isLeaf)
            {
                prevMatch = ans;
            }
        }
        return prevMatch;
    }


};


int main()
{

    string words[] = {"are", "area", "base", "cat", "cater", "children", "basement"};

    Trie* head = new Trie(); // head node

    for (auto wordsIt : words)
    {
        head->insert(wordsIt);
    }

    string wordsCheck[] = {"caterer", "basement", "are", "arex", "basemexz", "xyx", "catex"};


    for (auto wordsIt : wordsCheck)
    {
        cout << wordsIt << " : " << head->getLongestPrefix(wordsIt) << endl;
    }


    return 0;
}
