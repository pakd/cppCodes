#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;

bool ifPathToNodeX(Node* root, vector<int>& path, int *sum, int k)
{
    if(!root) return false;
    path.push_back(root->data);
    *sum+=root->data;
    if(*sum==k) return true;
    if(ifPathToNodeX(root->left, path, sum, k) || ifPathToNodeX(root->right, path, sum, k))
        return true;
    path.pop_back();
    *sum-=root->data;
    return false;

}


int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{10,8,12,4,9,11,15,14,18};
    for(int i=0; i< dpk.size();i++)
    {

        root = myTree.insert(root, dpk[i]);
    }
    vector<int> path;
    int sum = 0;
    ifPathToNodeX(root, path, &sum, 51);
    for(int i=0;i<path.size();i++)
    {

        cout << path[i] << " ";
    }

    return 0;
}
