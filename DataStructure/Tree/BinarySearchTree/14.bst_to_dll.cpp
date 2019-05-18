#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;

void findPairWithGivenSum(Node* head, int sumToFind);

// lets do inorder way as we want a sorted list
// double pointer with head as it will be one time only
void convertBSTtoDLL(Node* root, Node **head)
{
    if(!root) return;
    static Node* prev = NULL;
    convertBSTtoDLL(root->left, head);

    if(prev == NULL)
    {
        *head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;

    convertBSTtoDLL(root->right, head);
}

void findPairWithGivenSum(Node* head, int sumToFind)
{
    Node* endNode = NULL;
    Node* curr = head;
    while(curr->right)
    {
        curr = curr->right;
    }
    endNode = curr;

    Node* leftP = head;
    Node* rightP = endNode;
    while(leftP->data !=rightP->data)
    {
        if((leftP->data + rightP->data) == sumToFind)
        {
            cout << leftP->data << " + " << rightP->data << endl;
            if(leftP->right == rightP)
            {
                return;
            }
            leftP = leftP->right;
            rightP = rightP->left;
        }
        else if((leftP->data + rightP->data) > sumToFind)
        {
            rightP = rightP->left;
        }
        else
        {
            leftP = leftP->right;
        }

    }
}
int main()
{
    BasicTree myTree;
    Node* root = NULL;

    vector<int>  dpk{20,9,24,8,12,0,11};
    for(int i=0; i< dpk.size();i++)
    {

        root = myTree.insert(root, dpk[i]);
    }

    Node* head = NULL;
    convertBSTtoDLL(root, &head);

    Node* curr = head;

    while(curr)
    {
        cout << curr->data << "\t";
        curr = curr->right;
    }
    cout << endl;

    int sumToFind = 20;
    findPairWithGivenSum(head, sumToFind);

    return 0;
}
