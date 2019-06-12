#include <iostream>
#include <stack>
#include "bst_library.hpp"

void inorder_iterative(Node* root)
{
    // pair of Node and int (state)
    std::stack<pair<Node*, int>> st;

    st.push({root, 0});

    while(!st.empty())
    {
        std::pair<Node*, int> temp = st.top();
        Node* node = temp.first;
        int state = temp.second;
        st.pop();

        if(!node || state == 3) continue;
        st.push({node, state+1});

        if(state == 0) st.push({node->left, 0});
        else if(state == 1) std::cout << node->data << " ";
        else if(state == 2) st.push({node->right, 0});
    }
}

void preorder_iterative(Node* root)
{
    // pair of Node and int (state)
    std::stack<pair<Node*, int>> st;

    st.push({root, 0});

    while(!st.empty())
    {
        std::pair<Node*, int> temp = st.top();
        Node* node = temp.first;
        int state = temp.second;
        st.pop();


        if(!node || state == 3) continue;
        st.push({node, state+1});

        if(state == 0) std::cout << node->data << " ";
        else if(state == 1) st.push({node->left, 0});
        else if(state == 2) st.push({node->right, 0});
    }
}

void postorder_iterative(Node* root)
{
    // pair of Node and int (state)
    std::stack<pair<Node*, int>> st;

    st.push({root, 0});

    while(!st.empty())
    {
        std::pair<Node*, int> temp = st.top();
        Node* node = temp.first;
        int state = temp.second;
        st.pop();


        if(!node || state == 3) continue;
        st.push({node, state+1});

        if(state == 0) st.push({node->left, 0});
        else if(state == 1) st.push({node->right, 0});
        else if(state == 2) std::cout << node->data << " ";
    }
}

int main()
{
    BasicTree myTree;
    Node* root = NULL;

    std::vector<int>  dpk{10, 6, 14, 4, 8, 12, 16};
    for(auto x : dpk)
    {
        root = myTree.insert(root, x);
    }

    inorder_iterative(root);
    std::cout << std::endl;

    preorder_iterative(root);
    std::cout << std::endl;

    postorder_iterative(root);
}
