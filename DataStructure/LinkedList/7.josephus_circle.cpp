#include <iostream>
#include "linked_list_library.hpp"

Node* makeCircular(Node* head)
{
    Node* itr = head;

    while(itr->next)
    {
        itr = itr->next;
    }
    itr->next = head;
    return head;
}

Node* josephusCircle(Node* head, int k)
{
    Node* ptr = head;
    Node* prev = head;

    /* while only one node is left in the linked list*/
    while(ptr->next != ptr)
    {
        int count = 1;

        // find kth node
        while(count != k)
        {
            prev = ptr;
            ptr = ptr->next;
            count++;
        }

        // remove kth node
        prev->next = ptr->next;

        std::cout << "deleted node:" << ptr->data << std::endl;

        // move one node further
        ptr = prev->next; // as one node is already removed

    }
    return ptr;
}
int main()
{
    BasicLinkedList myList;
    Node* head = NULL;

    int n = 14; // lastNode = 13
    // int n = 4; // lastNode = 1;
    // int n = 5; k = 3 // lastNode = 4;
    // int n = 14, k = 3; // LastNode = 2;

    for(int i = 1; i <= n ; i++)
    {
        head = myList.insert(head, i);
    }
    head = makeCircular(head);

    Node* lastNode = josephusCircle(head, 2);
    std::cout << lastNode->data;

    return 0;
}
