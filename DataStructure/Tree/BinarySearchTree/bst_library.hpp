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

    void displayInorder(Node* head)
    {
        if(!head)
            return;
        displayInorder(head->left);
        cout << head->data << "\t";
        displayInorder(head->right);
    }

   /* int countNodes(Node* head)
    {
        Node *start = head;
        int count = 0;
        while(start)
        {
            count++;
            start = start->next;
        }
        return count;
    }*/

    Node* insert(Node* head, int key)
    {
        Node* newNode = new Node(key);
        if(head == NULL)
        {
            head = newNode;
            return head;
        }
        Node *itr = head;

        Node *xUp = head;
        Node *xDown = head;

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

        return head;

    }

};
