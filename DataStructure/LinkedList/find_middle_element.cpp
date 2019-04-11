#include <iostream>
#include "linked_list_library.hpp"
using namespace std;

Node* findMiddleNode(Node* head)
{
    Node* slow = head;
    Node* fast = head;

    while(fast  && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;

}
int main()
{
    BasicLinkedList myList;
    Node* head = NULL;

    int n = 10;

    for(int i = 1; i <= n ; i++)
    {
        head = myList.insert(head, i);
        Node* middle = findMiddleNode(head);
        cout << i << " : "<<middle->data << endl;
    }

    return 0;
}
