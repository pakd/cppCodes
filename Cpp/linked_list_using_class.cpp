#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        data=d;
        next=NULL;
    }
};
class Solution
{
public:
    Node* insert(Node *head,int data)
    {
        Node* dpk = new Node(data);
        if(head == NULL)
        {
            head = dpk;
            return head;
        }
        Node *itr = head;
        while(itr->next!=NULL)
        {
            itr=itr->next;
        }
        itr->next=dpk;
        return head;
    }
    void display(Node *head)
    {
        Node *start=head;
        while(start)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
    }
};
int main()
{
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0) // -- > 0 two operators
    {
        cin>>data;
        head=mylist.insert(head,data);
    }
    mylist.display(head);
}
