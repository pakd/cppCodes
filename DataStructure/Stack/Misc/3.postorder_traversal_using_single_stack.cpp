#include <iostream>
#include <stack>

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
    Node* current = root;
    std::stack<Node*> st;

    // while current is not null or stack is not empty
    while(current || !st.empty())
    {
        // traversing left subtree
        if(current)
        {
            st.push(current);
            current = current->left;
        }

        // traversing right subtree, current is null
        else
        {
            Node* temp = st.top()->right;

            // no right child, so we can print the node
            if(temp == NULL)
            {
                temp = st.top();
                st.pop();
                std::cout << temp->data << " ";

                // printing parents of right subtree
                while(!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    std::cout << temp->data << " ";
                }
            }

            // if temp is not null or search for left subtree of right child
            else
            {
                current = temp;
            }
        }
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
