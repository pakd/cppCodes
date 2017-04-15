#include <iostream>
#include "linked_list_library.hpp"
using namespace std;

Node* addLinkedLists(Node* head1, Node* head2)
{
    Node* head3 = NULL;
    BasicLinkedList myList3;
    int carry = 0;
    int sum = 0;
    int term = 0;

    while(head1 || head2)
    {
        sum = (head1? head1->data: 0) + (head2? head2->data: 0) + carry;
        carry = sum/10;
        term = sum%10;
        head3 = myList3.insert(head3,term);
        if (head1)
        {
            head1 = head1->next;
        }
        if(head2)
        {
            head2 = head2->next;
        }
    }
    if(carry > 0)
    {
        head3 = myList3.insert(head3,carry);
    }
    return head3;
}
int main()
{
    BasicLinkedList myList;
    Node* head1 = NULL;
    head1 = myList.insert(head1,7);
    head1 = myList.insert(head1,5);
    head1 = myList.insert(head1,9);
    head1 = myList.insert(head1,4);
    head1 = myList.insert(head1,6);

    Node* head2 = NULL;
    head2 = myList.insert(head2,8);
    head2 = myList.insert(head2,4);

    Node* head3 = NULL ;
    head3 = addLinkedLists(head1,head2);
    myList.display(head3);

    return 0;
}
