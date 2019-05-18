#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;
bool isExistInPath(vector<Node*>& path, int x);

void printKNodesFromRoot(Node* root, vector<Node*>& path, int k)
{
    if(!root) return;
    if(k==0)
    {
        cout << root->data << " ";
        return;
    }
    else
    {
        if( root->left && !isExistInPath(path, root->left->data))
        printKNodesFromRoot(root->left,  path, k-1);

        if( root->right && !isExistInPath(path, root->right->data))
        printKNodesFromRoot(root->right,  path, k-1);
    }
}

bool ifPathToNodeX(Node* root, vector<Node*>& path, int x)
{

    if(!root) return false;
    path.push_back(root);
    if(root->data == x) return true;
    if(ifPathToNodeX(root->left, path, x) || ifPathToNodeX(root->right, path, x))
        return true;
    path.pop_back();
    return false;

}

bool isExistInPath(vector<Node*>& path, int x)
{
    for(auto it : path)
    {
        if(it->data == x)
            return true;
    }
    return false;
}


int main()
{
    BasicTree myTree;
    Node* root = NULL;

    int k = 3;
    int nodeX = 30;

    // tree creation
    vector<int>  dpk{40,20,50,15,30,60,10,24,36,38,37};

    for(int i=0; i< dpk.size(); i++)
    {

        root = myTree.insert(root, dpk[i]);
    }

    //display level order
    myTree.displayLevelOrder(root);

    // printing path to node x
    vector<Node*> path;
    ifPathToNodeX(root, path, nodeX);
    cout << "\nPath to node X: ";
    for(auto x : path)
    {

        cout << x->data << " ";
    }

    // printing all nodes k distance from node x
    int xNodeHeight = path.size();
    cout << "\nGetting all nodes with distance K: " << k << " from Node ["  << path[xNodeHeight-1]->data  <<  "]: ";
    for(int i=xNodeHeight-1; i >= 0 && k >= 0 ; i--)
    {

        printKNodesFromRoot(path[i], path, k--);
    }
    cout << endl;
    return 0;
}
