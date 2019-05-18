#include "bst_library.hpp"
#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

void left_view(Node* root, int level, int &maxLevel)
{
    if(!root) return;
    if(level>maxLevel)
    {
        cout << root->data << " ";
        maxLevel = level;
    }
    left_view(root->left, level+1, maxLevel);
    left_view(root->right, level+1, maxLevel);

}

void right_view(Node* root, int level, int &maxLevel)
{
    if(!root) return;
    if(level>maxLevel)
    {
        cout << root->data << " ";
        maxLevel = level;
    }
    right_view(root->right, level+1, maxLevel);
    right_view(root->left, level+1, maxLevel);

}


int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{15,6,24,17,30,26,34};
    for(int i=0; i< dpk.size();i++)
    {
        root = myTree.insert(root, dpk[i]);
    }
    int maxLeftLevel = 0;
    left_view(root, 1, maxLeftLevel);
    cout << endl;
    int maxrightLevel = 0;
    right_view(root, 1, maxrightLevel);


    return 0;
}
