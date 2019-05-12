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
    int wordIndex = 0;
    Trie()
    {
        isLeaf = false;
        for(int i=0; i<ALPHABET_SIZE; i++)
        {
            children[i] = NULL;
        }
    }

    // only insert reverse strings
    // i for not matching same strings
    void insert(string key, int i)
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
        curr->wordIndex = i;
    }

    bool search(string key, Trie* lastNode, int i, int& matchedLength)
    {
        lastNode = NULL;
        matchedLength = 0;
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
            matchedLength++;
            curr = curr->children[index];
        }

        lastNode = curr;

        if(i != curr->wordIndex) // to check if we are not matching same word.
        {
            return curr->isLeaf; // check last node as word or not
        }
        return false;


    }

    //get all string in case of no complete match by recursive search
    bool getAllStringsBelow(Trie* lastNode)
    {
        vector<string> ret;
        traverseAllNodesBelow(lastNode, ret, "");

        for(auto x : ret)
        {
            if(isPalindromeString(x))
            {
                return true;
            }
        }
        return false;
    }


    void traverseAllNodesBelow(Trie* node,vector<string>& vect, string prefix)
    {
        if(node == NULL)
        {
            return;
        }
        if(node->isLeaf)
        {
            vect.push_back(prefix);
        }
        for(int i=0; i < ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                traverseAllNodesBelow(node->children[i], vect, prefix + char(i + 'a'));
            }
        }
    }

    bool isPalindrome(vector<string>& words)
    {
        int i = 0;
        for(auto x : words)
        {
            Trie* lastNode;
            string check = "";
            int matchedLength = 0;
            bool isThere = search(x, lastNode, i++, matchedLength);

            if(isThere)
            {
                return true;
            }
            else // recrusive search
            {
                int xLen = x.length();
                int xLenRequired = xLen - matchedLength;
                string sub = x.substr(matchedLength, xLenRequired);
                if(isPalindromeString(sub))
                {
                    return true;
                }
                if( lastNode && getAllStringsBelow(lastNode))
                {
                    return true;
                }
            }
        }
        return false;
    }

    bool isPalindromeString(string str)
    {
        int len = str.length();

        int i = 0;
        int j  = len - 1;

        while(i < j)
        {
            if(str[i] != str[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};
/*

 algorithm steps
 1. insert reverse of all words in trie;
 2. iterate all words again and check if it is present in trie
    2.a complete match, return true;
    2.b string searched length is bigger than in trie, check rest of string is palindrome or not.
    2.c string in trie is bigger , then recursively check all substring for palindrome and return true if present.
 */
int main()
{
    Trie* head = new Trie(); // head node

    vector<string> vect = {"geekf", "geeks", "or", "keeg", "abc", "bc"}; // yes
    // vector<string> vect = {"deepak", "kumar", "or", "keeg", "abc", "bc"}; // no
    // vector<string> vect = {"abc", "xyxcba", "geekst", "or", "keeg", "bc"}; // yes

    // inserting reverse of strings
    int i = 0;
    for( auto x : vect)
    {
        string temp = x;

        reverse(temp.begin(), temp.end());
        head->insert(temp, i++);
    }

    head->isPalindrome(vect)? cout << "Yes" : cout << "No";

    return 0;
}
