#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ALPHABET_SIZE 26
class Trie
{
public:
    bool isLeaf;
    Trie* children[ALPHABET_SIZE];
    int frequency = 0;
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

        curr->isLeaf = true;
        curr->frequency++;
    }

    priority_queue<pair<int, string>> pq;

    void displayAllNodes(Trie* node, string prefix)
    {
        if(node == NULL)
        {
            return;
        }
        if(node->isLeaf)
        {
            pq.push({node->frequency, prefix});
        }
        for(int i=0; i < ALPHABET_SIZE; i++)
        {
            if(node->children[i])
            {
                displayAllNodes(node->children[i], prefix + char(i + 'a'));
            }
        }
    }


};

vector<string> separateWords(string input)
{
    vector<string> ret;
    string word = "";
    for (auto x : input)
    {
        if(x == ' ')
        {
            ret.push_back(word);
            word = "";
        }
        else
        {
            word += tolower(x);
        }
    }
    ret.push_back(word); // push last word
    return ret;
}
int main()
{
    int k = 5;
    Trie* head = new Trie(); // head node
    string book = "Welcome to the world of Geeks This portal has been created to provide well written well thought and well explained solutions for selected questions If you like Geeks for Geeks and would like to contribute here is your chance You can write article and mail your article to contribute at geeksforgeeks org See your article appearing on the Geeks for Geeks main page and help thousands of other Geeks";

    vector<string> bookParsed = separateWords(book);

    for(int i=0;i < bookParsed.size(); i++)
    {
        head->insert(bookParsed[i]);
    }

    head->displayAllNodes(head, "");

    int i = k;
    while(i--)
    {
        pair<int, string> ans = head->pq.top();
        head->pq.pop();

        cout << ans.second << " " << ans.first << endl;
    }

    return 0;
}
