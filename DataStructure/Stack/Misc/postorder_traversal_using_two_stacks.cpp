#include <iostream>
#include <stack>
using namespace std;

// A tree node
class Node
{
public:
    int data;
    Node *left, *right;
};

Node* newNode(int data)
{
    Node* node = new Node();
    node->data = data;
    node->left = node->right = NULL;
    return node;
}


void postOrderIterative(Node* root)
{
    if (root == NULL)
        return;

    stack<Node*> st1;
    stack<Node*> st2;

    st1.push(root);

    while(!st1.empty())
    {

        // pop from stack 1
        Node* temp = st1.top();
        st1.pop();

        // push to stack 2
        st2.push(temp);


        // push left child to stack 1
        if(temp->left)
        {
            st1.push(temp->left);
        }

        // push right child to stack 1
        if(temp->right)
        {
            st1.push(temp->right);
        }

    }

    while(!st2.empty())
    {
        cout << st2.top()->data << " ";
        st2.pop();
    }

}

int main()
{
    Node* root = NULL;
    root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    postOrderIterative(root);

    return 0;
}
