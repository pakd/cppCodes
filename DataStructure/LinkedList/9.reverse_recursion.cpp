#include <iostream>
#include "linked_list_library.hpp"


Node* head = NULL;
void reverseRecursionLinkedList(Node* p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    reverseRecursionLinkedList(p->next);
    Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

int main()
{
    BasicLinkedList myList;
    //Node* head = NULL;
    head = myList.insert(head,1);
    head = myList.insert(head,2);
    head = myList.insert(head,3);
    head = myList.insert(head,4);
    head = myList.insert(head,5);
    reverseRecursionLinkedList(head);
    myList.display(head);

    return 0;

}
