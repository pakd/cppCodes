#include "bst_library.hpp"
#include <iostream>
#include <vector>
using namespace std;


int search(int *arr, int start, int end, int key)
{
    for(int i=start;i<=end;i++)
    {
        if(arr[i] == key)
            return i;
    }
}

Node* constructTree(int *in, int inS, int inE, int *pre, int preS, int preE)
{
    if(inS > inE) return NULL;
    int rootData = pre[preS];
    Node* root = new Node(rootData);


    int index = search(in, inS, inE, rootData);

    int linS = inS;
    int linE = index - 1;
    int rinS = index + 1;
    int rinE = inE;
    int lpreS = preS+1;
    int lpreE = linE - linS + lpreS;
    int rpreS = lpreE + 1;
    int rpreE = preE;

    root->left = constructTree(in, linS, linE, pre, lpreS, lpreE);
    root->right = constructTree(in, rinS, rinE, pre, rpreS, rpreE);
    return root;

}


int main()
{
    BasicTree myTree;
    Node* root = NULL;
    int size = 8;
    int inorder[] = {7,4,5,8,4,10,9,6};
    int preorder[] = {10,4,7,8,5,4,6,9};
    root = constructTree(inorder, 0, size-1, preorder, 0, size -1 );

    myTree.displayLevelOrder(root);

    return 0;
}
