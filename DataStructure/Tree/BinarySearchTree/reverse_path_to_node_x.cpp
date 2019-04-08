#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool ifPathToNodeX(Node* root, vector<Node*>& path, int x)
{
    if(!root) return false;
    path.push_back(root);
    if(root->data == x) return true;
    if(ifPathToNodeX(root->left, path, x) || ifPathToNodeX(root->right,path,x))
        return true;
    path.pop_back();
    return false;
}

int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{20,10,30,5,15,12,18,17};
    for(int i=0; i< dpk.size();i++)
    {
        root = myTree.insert(root, dpk[i]);
    }
    vector<Node*> path;
    ifPathToNodeX(root, path, 17);

    int i=0;
    int j = path.size() - 1;
    while(i<j)
    {
        swap(path[i]->data, path[j]->data);
        i++;
        j--;
    }

    myTree.displayInorder(root);

    return 0;
}
