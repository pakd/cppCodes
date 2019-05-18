#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;


int getHeight(Node* root)
{
    if(!root) return 0;
    return (1 + max(getHeight(root->left),getHeight(root->right)));

}
int getMax(Node* root)
{
    if(!root) return 0;
    return max(getMax(root->left), max(getMax(root->right), root->data));
}

int getDiameter(Node* root)
{
    if(!root) return 0;
    return max(getDiameter(root->left),max(getDiameter(root->right),getHeight(root->left) + getHeight(root->right) + 1));
}

int count = 0;
void getSize(Node* root)
{
    if(!root) return;
    count++;
    getSize(root->left);
    getSize(root->right);
}

int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{10,6,14,3,8,12,16,18,15};
    for(int i=0; i< dpk.size();i++)
    {

        root = myTree.insert(root, dpk[i]);
    }

    int maxElement = getMax(root);
    cout << "Max Element\t" << maxElement << endl;

    getSize(root);
    cout << "size\t" << count << endl;

    int maxHeight = getHeight(root);
    cout << "maxHeight\t" << maxHeight << endl;

    int diameter = getDiameter(root);
    cout << "diameter\t" << diameter << endl;

    return 0;
}
