#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

class BasicTree
{
public:

    void displayInorder(Node* root)
    {
        if(!root)
            return;
        displayInorder(root->left);
        cout << root->data << "\t";
        displayInorder(root->right);
    }

   /* int countNodes(Node* root)
    {
        Node *start = root;
        int count = 0;
        while(start)
        {
            count++;
            start = start->next;
        }
        return count;
    }*/

    Node* insert(Node* root, int key)
    {
        Node* newNode = new Node(key);
        if(root == NULL)
        {
            root = newNode;
            return root;
        }
        Node *itr = root;

        Node *xUp = root;
        Node *xDown = root;

        while(xDown)
        {
            xUp = xDown;
            xDown = (key < xDown->data)? xDown->left: xDown->right;
        }
        if (key < xUp->data)
        {
            xUp->left = newNode;
        }
        else
        {

            xUp->right = newNode;
        }

        return root;

    }

    int getHeight(Node* root)
    {
        if(!root) return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        int maxHeight = (leftHeight > rightHeight)?leftHeight:rightHeight;
        return maxHeight + 1;
    }

};
