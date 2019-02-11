#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool ifPathToNodeX(Node* root, vector<int>& path, int x)
{
    if(!root) return false;
    path.push_back(root->data);
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
    vector<int> path;
    ifPathToNodeX(root, path,17);
    for(int i=0;i<path.size();i++)
    {

        cout << path[i] << " ";
    }

    return 0;
}
