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
    while(head1 && head2)
    {
        sum = head1->data + head2->data + carry;
        carry = sum/10;
        term = sum%10;
        head3 = myList3.insert(head3,term);
        head1 = head1->next;
        head2 = head2->next;

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
    head1 = myList.insert(head1,8);
    head1 = myList.insert(head1,7);
    head1 = myList.insert(head1,6);

    Node* head2 = NULL;
    head2 = myList.insert(head2,4);
    head2 = myList.insert(head2,5);
    head2 = myList.insert(head2,6);

    Node* head3 = NULL ;
    head3 = addLinkedLists(head1,head2);
    myList.display(head3);

    return 0;
}
