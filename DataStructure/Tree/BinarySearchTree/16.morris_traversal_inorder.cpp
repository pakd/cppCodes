#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;

void MorrisTraversalInorder(Node* root)
{
    if(!root) return;
    Node* curr = root;

    while(curr)
    {
        if(!curr->left)
        {
            // If left subtree doesnt exist print current's data and move to right of current.
            cout << curr->data << " ";
            curr = curr->right;
        }
        else
        {
            // take pre which will be the inordor predecessor of curr in left subtree
            Node* pre = curr->left;
            while(pre->right && pre->right != curr)
            {
                // go to the rightmost child of left subtree
                pre = pre->right;
            }

            if(!pre->right)  // link formation
            {
                pre->right = curr;
                curr=curr->left;
            }
            else // break link
            {
                pre->right = NULL;
                cout << curr->data << " ";
                curr = curr->right;    // left subtree is already printed
            }
        }
    }

}

int main()
{
    BasicTree myTree;
    Node* root = NULL;


    vector<int>  dpk{100,50,150,30,60,120,180,170,210};

    for(int i=0; i< dpk.size(); i++)
    {

        root = myTree.insert(root, dpk[i]);
    }

    //display level order
    myTree.displayLevelOrder(root);

    cout << endl;

    MorrisTraversalInorder(root);


}
