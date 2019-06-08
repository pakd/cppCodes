#include <iostream>
#include "linked_list_library.hpp"

Node* n_by_k(Node* head, int k)
{
    Node* fractionalNode  = NULL;

    int count = 0;
    while(head)
    {
        if( count%k == 0)
        {
            if(!fractionalNode )
            {
                fractionalNode  = head;
            }
            else
            {
                fractionalNode  = fractionalNode ->next;
            }
        }
        head = head->next;
        count++;
    }

    return fractionalNode;
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

    Node* ans = n_by_k(head, 2); // 6/2 == 3
    std::cout << ans->data;
    return 0;

}
