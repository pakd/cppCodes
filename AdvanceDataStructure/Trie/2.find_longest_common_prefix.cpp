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

    bool haveOnlyOneChildren(Trie* node)
    {
        int count = 0;
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                count++;
            }
        }
        return count==1?true:false;
    }

    string getLongestCommonPrefix(string key)
    {

        string ans = "";
        if(this == NULL) // if trie is empty
        {
            return ans;
        }

        Trie* curr = this;

        for(auto it : key)
        {
            int index = it - 'a';
            if(haveOnlyOneChildren(curr))
            {
                curr = curr->children[index];
                ans += it;
            }
        }
        return ans;
    }


};


int main()
{

    string words[] = {"geeksforgeeks", "geeks", "geek", "geezer"}; // ans = "gee"

    Trie* head = new Trie(); // head node

    for (auto wordsIt : words)
    {
        head->insert(wordsIt);
    }

    cout << head->getLongestCommonPrefix(words[0]); // pass any string to function


    return 0;
}
