#include "bst_library.hpp"
#include <iostream>

using namespace std;

Node* lowestCommonAncestor(Node* root, int p, int q)
{
    if(!root)
    {
        return NULL;
    }
    if(root->data == p || root->data == q)
    {
        return root;
    }

    Node* left = lowestCommonAncestor(root->left, p, q);
    Node* right = lowestCommonAncestor(root->right, p, q);

    if(left && right) {
        return root;
    }

    return (left)?left:right;
}

int main()
{
    BasicTree myTree;
    Node* head = NULL;

    vector<int>  dpk{22, 10, 30, 5, 15, 24, 36, 23};
    for(int i=0; i< dpk.size(); i++)
    {
        head = myTree.insert(head, dpk[i]);
    }

    Node* lca = lowestCommonAncestor(head, 10, 23); // 22
    std::cout << lca->data;

    return 0;
}
