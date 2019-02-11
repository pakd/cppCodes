#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;

void printKNodesFromRoot(Node* root, int k)
{
    if(!root) return;
    if(k==0)
    {
        cout << root->data << " ";
        return;
    }
    else
    {
        printKNodesFromRoot(root->left, k-1);
        printKNodesFromRoot(root->right, k-1);
    }
}


int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{20,10,30,5,15,40};

    for(int i=0; i< dpk.size();i++)
    {

        root = myTree.insert(root, dpk[i]);
    }
    printKNodesFromRoot(root, 3);

    return 0;
}
