#include <iostream>

class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class BasicLinkedList
{
public:

    void display(Node* head)
    {
        Node *start = head;
        while(start)
        {
            std::cout << start->data <<" ";
            start = start->next;
        }
    }

    int countNodes(Node* head)
    {
        Node *start = head;
        int count = 0;
        while(start)
        {
            count++;
            start = start->next;
        }
        return count;
    }

    Node* insert(Node* head, int data)
    {
        Node* newNode = new Node(data);
        if(head == NULL)
        {
            head = newNode;
            return head;
        }
        Node *itr = head;
        while(itr->next)
        {
            itr=itr->next;
        }

        itr->next = newNode;
        return head;
    }
};
