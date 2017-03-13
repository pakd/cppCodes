#include <iostream>
#include "linked_list_library.hpp"
using namespace std;


Node* reverseLinkedList(Node* head)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* Next;

    while(curr)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
    }

    head = prev;

    return head;
}
int main()
{
    BasicLinkedList myList;
    Node* head = NULL;
    head = myList.insert(head,1);
    head = myList.insert(head,2);
    head = myList.insert(head,3);
    head = myList.insert(head,4);
    head = reverseLinkedList(head);
    myList.display(head);

}
