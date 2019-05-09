#include <iostream>
#include <vector>
using namespace std;

#define ALPHABET_SIZE 26
class Trie
{
public:
    bool isLeaf;
    Trie* children[ALPHABET_SIZE];
    vector<string> stringArr;
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
            if( isupper(it))
            {
                int index = it - 'A';
                if(curr->children[index] == NULL )
                {
                    curr->children[index] = new Trie();
                }
                curr = curr->children[index];
            }

        }

        // mark last node as leaf
        curr->isLeaf = true;
        curr->stringArr.push_back(key);
    }

    bool searchCC(string key)
    {
        Trie* curr = this;
        for(auto it : key)
        {
            int i = it - 'A';
            if(!curr->children[i])
            {
                return false;
            }
            curr = curr->children[i];
        }
        if(curr->isLeaf)
        {
            for (auto x : curr->stringArr)
            {
                cout << x << endl;
            }
        }
    }

    void recursiveSearchUtil(Trie* node, string prefix)
    {
        if(node == NULL) // if first call is null, return
        {
            return;
        }
        if(node->isLeaf)
        {
            for (auto x : node->stringArr)
            {
                cout << x << endl;
            }
        }

        for(int i=0 ; i < ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                recursiveSearchUtil(node->children[i], prefix + char(i + 'A'));
            }

        }
    }
    void recSearch(string key)
    {
        Trie* curr = this;
        string prefix = "";


        for(auto x : key)
        {
            int index = x - 'A';
            if(!curr->children[index])
            {
                cout << "no word" << endl;
                return;
            }
            prefix += x;
            curr = curr->children[index];
        }
        cout << prefix << endl;
        recursiveSearchUtil(curr, prefix);

    }
};


int main()
{
    Trie* head = new Trie(); // head node

    string dict[] = {"Hi", "Hello", "HelloWorld",  "HiTech", "HiGeek", "HiTechWorld", "HiTechCity", "HiTechLab" };

   for (auto x : dict)
    {
        head->insert(x);
    }

    head->recSearch("HT");

    cout << endl << endl;

    head->recSearch("H");

    return 0;
}
