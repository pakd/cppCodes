#include "bst_library.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<int> vect;
void PreorderModified(Node* root)
{
    if(!root) return;
    vect.push_back(root->data);

    if(!root->left && !root->right)
    {
        for(auto x : vect)
        {
            cout << x << "\t";
        }
        cout << endl;
    }

    PreorderModified(root->left);
    PreorderModified(root->right);
    vect.pop_back();

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

    PreorderModified(root);


    return 0;
}
