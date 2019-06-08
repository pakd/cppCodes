#include <iostream>
#include "linked_list_library.hpp"

Node* square_root_nth_node(Node* head)
{
    int i = 1;
    int j = 1;

    Node* square_root_nth = NULL;

    while(head)
    {
        // check if j = sqrt(i)
        if( i == j*j)
        {
            if(!square_root_nth)
            {
                square_root_nth = head;
            }
            else
            {
                square_root_nth = square_root_nth->next;
            }
            // increment j if j = sqrt(i)
            j++;
        }

        head = head->next;
        i++;
    }

    return square_root_nth;

}
int main()
{
    BasicLinkedList myList;
    Node* head = NULL;
    head = myList.insert(head,1);
    head = myList.insert(head,2);
    head = myList.insert(head,3);
    head = myList.insert(head,4);
    head = myList.insert(head,5);
    head = myList.insert(head,6);
    head = myList.insert(head,7);
    head = myList.insert(head,8);
    head = myList.insert(head,9);
    head = myList.insert(head,10);
    Node* ans = square_root_nth_node(head);
    std::cout << ans->data;
    return 0;

}
