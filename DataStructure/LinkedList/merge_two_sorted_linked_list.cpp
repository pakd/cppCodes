#include <iostream>
#include "linked_list_library.hpp"
using namespace std;

Node* curr = NULL;

Node* insertNodeInList(Node* head, Node* push)
{
    push->next = NULL;
    if(!curr)
    {
        head = push;
        curr = push;
    }
    else
    {
        curr->next = push;
        curr = curr->next;
    }

    return head;
}

Node* mergeLinkedLists(Node* head1, Node* head2)
{
    Node* head3 = NULL;


    while(head1 || head2)
    {
        int data1 = head1? head1->data: INT_MAX;
        int data2 = head2? head2->data: INT_MAX;

        if(data1 < data2)
        {
            Node* temp = head1;
            head1 = head1->next;
            head3 = insertNodeInList(head3, temp);
        }
        else
        {
            Node* temp = head2;
            head2 = head2->next;
            head3 = insertNodeInList(head3, temp);
        }
    }

    return head3;
}
int main()
{
    BasicLinkedList myList;

    Node* head1 = NULL;
    head1 = myList.insert(head1, 3);
    head1 = myList.insert(head1, 5);
    head1 = myList.insert(head1, 9);
    head1 = myList.insert(head1, 12);
    head1 = myList.insert(head1, 16);

    Node* head2 = NULL;
    head2 = myList.insert(head2,8);
    head2 = myList.insert(head2,14);
    head2 = myList.insert(head2, 16);

    Node* head3 = NULL ;
    head3 = mergeLinkedLists(head1, head2);
    myList.display(head3);

    return 0;
}
