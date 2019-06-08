#include "linked_list_library.hpp"
#include <iostream>

int main()
{
    BasicLinkedList myList;
    Node* head = NULL;
    head = myList.insert(head, 3);
    head = myList.insert(head, 4);
    head = myList.insert(head, 5);
    myList.display(head);
    return 0;
}
