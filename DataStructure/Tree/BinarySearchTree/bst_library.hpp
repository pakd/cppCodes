#include <iostream>
#include <queue>
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

    void displayLevelOrder(Node* root)
    {
        if(!root)
            return;
        queue<Node*> Q;
        Q.push(root);
        while(!Q.empty())
        {
            Node* curr = Q.front();
            if(curr->left)
                Q.push(curr->left);
            if(curr->right)
                Q.push(curr->right);
            cout << curr->data << " ";
            Q.pop();

        }
    }

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

    Node* insertRecursive(Node* root, int key)
    {
        if(!root)
        {
            Node* newNode = new Node(key);
            return newNode;
        }

        else if(root->data > key)
        {
            root->left = insertRecursive(root->left, key);
        }
        else
        {
            root->right = insertRecursive(root->right, key);
        }

        return root;
    }

    Node* search(Node* root, int key)
    {
        if(!root || root->data == key)
            return root;

        else if(root->data > key)
            return search(root->left, key);

        else
            return search(root->right, key);
    }

};
