#include <iostream>
#include <cstring>
using namespace std;

#define ALPHABET_SIZE 26
#define M 3
#define N 3


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
            int index = it - 'A';
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
            int index = it - 'A';
            if(curr->children[index] == NULL )
            {
                return false;
            }
            curr = curr->children[index];
        }

        return curr->isLeaf; // check last node as word or not
    }

    void searchWordRecursive(Trie* root, int i, int j, string prefix, bool visited[M][N], char boggle[M][N])
    {
        if(root->isLeaf)
        {
            cout << prefix << endl;
        }

        visited[i][j] = true;

        // check if child node is present in neighborhood of current cell
        for(int k=0; k < ALPHABET_SIZE; k++)
        {
            if(root->children[k])
            {
                char ch = char(k + 'A');

                /*
                      N
                      |
                  W---|---E
                      |
                      S
                */

                // S
                if (isSafe(i+1,j,visited) && boggle[i+1][j] == ch)
                {
                    searchWordRecursive(root->children[k], i+1 , j, prefix + ch, visited, boggle);
                }

                // SE
                if (isSafe(i+1,j+1,visited) && boggle[i+1][j+1] == ch)
                {
                    searchWordRecursive(root->children[k], i+1 , j+1, prefix + ch, visited, boggle);
                }

                // E
                if (isSafe(i,j+1,visited) && boggle[i][j+1] == ch)
                {
                    searchWordRecursive(root->children[k], i, j+1, prefix + ch, visited, boggle);
                }

                // EN
                if (isSafe(i-1,j+1,visited) && boggle[i-1][j+1] == ch)
                {
                    searchWordRecursive(root->children[k], i-1, j+1, prefix + ch, visited, boggle);
                }

                // N
                if (isSafe(i-1,j,visited) && boggle[i-1][j] == ch)
                {
                    searchWordRecursive(root->children[k], i-1, j, prefix + ch, visited, boggle);
                }

                // NW
                if (isSafe(i-1,j-1,visited) && boggle[i-1][j-1] == ch)
                {
                    searchWordRecursive(root->children[k], i-1, j-1, prefix + ch, visited, boggle);
                }

                // W
                if (isSafe(i,j-1,visited) && boggle[i][j-1] == ch)
                {
                    searchWordRecursive(root->children[k], i, j-1, prefix + ch, visited, boggle);
                }

                // WS
                if (isSafe(i+1,j-1,visited) && boggle[i+1][j-1] == ch)
                {
                    searchWordRecursive(root->children[k], i+1, j-1, prefix + ch, visited, boggle);
                }


            }
        }

        visited[i][j] = false; // same character can come in, with the gap of 1 missing.
    }

    void findWords(char boggle[M][N], Trie* root, bool visited[M][N])
    {
        // only child of root node can be the first char of words in dictionary
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++)
            {
                int index = boggle[i][j] - 'A';

                string prefix = "";

                // we start searching for word in dictionary
                // if we found a character which is child
                // of Trie root
                if(root->children[index])
                {
                    prefix += boggle[i][j];
                    searchWordRecursive(root->children[index], i, j, prefix, visited, boggle);
                    prefix = "";
                }

            }
        }
    }

    // sanity check function
    bool isSafe(int i, int j, bool visited[M][N])
    {
        if(i >= 0 && i < M && j >=0 && j < N && !visited[i][j])
        {
            return true;
        }
        return false;
    }
};




int main()
{
    Trie* root = new Trie(); // head node

    // Let the given dictionary be following
    string dictionary[] = {"GEEKS", "FOR", "QUIZ", "GEE"};

    for (auto x : dictionary)
    {
        root->insert(x);
    }

    char boggle[M][N] =
    {
        {'G','I','Z'},
        {'U','E','K'},
        {'Q','S','E'}
    };

    bool visited[M][N];
    memset(visited, false, sizeof(visited));
    /*for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            visited[M][N] = false;
        }
    }*/



    root->findWords(boggle, root, visited);

    return 0;
}
