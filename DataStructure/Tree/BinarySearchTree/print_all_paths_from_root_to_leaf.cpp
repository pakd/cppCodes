#include "bst_library.hpp"
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

deque<int> s;
void InorderModified(Node* root)
{
    if(!root) return;
    s.push_back(root->data);

    InorderModified(root->left);

    if(!root->left && !root->right)
    {
        for(int i=0;i < s.size();i++)
        {
            cout << s[i] << "\t";
        }
        cout << endl;
    }

    InorderModified(root->right);
    s.pop_back();

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

    InorderModified(root);


    return 0;
}
