#include <iostream>
#include "linked_list_library.hpp"
using namespace std;


Node* reverseLinkedList(Node* head, int k)
{
    Node* curr = head;
    Node* prev = NULL;
    Node* Next;
    int count = 0;

    while(curr && count < k)
    {
        Next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = Next;
        count++;
    }
    if(Next)
    {
        // cout << "prev:" << prev ->data << endl;
        head->next = reverseLinkedList(Next,k);
    }
    head = prev; // prev is the last element in the kth block, so overall last prev after returning from recursion will be the head, in this case "3"

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
    head = myList.insert(head,5);
    head = myList.insert(head,6);
    head = myList.insert(head,7);
    head = myList.insert(head,8);
    head = myList.insert(head,9);
    head = myList.insert(head,10);
    head = reverseLinkedList(head,3);
    myList.display(head);

}
