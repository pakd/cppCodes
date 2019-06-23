#include <iostream>
#include <unordered_map>

class Node
{
public:
    int data;
    Node* next;
    Node* random;
    Node(int d)
    {
        data = d;
        next = random = NULL;
    }
};

void print(Node* head)
{

    Node* curr = head;
    while(curr)
    {
        int randomData = (curr->random)?curr->random->data:-1;
        std::cout << curr->data << " " << randomData << std::endl;
        curr = curr->next;
    }

    std::cout << std::endl;
}

Node* cloneList(Node* head)
{

    Node* originalNode = head;
    std::unordered_map<Node*, Node*> nodeMap;
    while(originalNode)
    {
        Node* cloneNode = new Node(originalNode->data);
        nodeMap[originalNode] = cloneNode;
        originalNode = originalNode->next;
    }

    originalNode = head;
    Node* cloneNode = NULL;
    while(originalNode)
    {
        cloneNode = nodeMap[originalNode];
        cloneNode->next = nodeMap[originalNode->next];
        cloneNode->random = nodeMap[originalNode->random];
        originalNode = originalNode->next;
    }

    return nodeMap[head];
}



int main()
{
    Node* originalHead = new Node(1);
    originalHead->next = new Node(2);
    originalHead->next->next = new Node(3);
    originalHead->next->next->next = new Node(4);
    originalHead->next->next->next->next = new Node(5);

    // random links

    originalHead->random = originalHead->next->next;
    originalHead->next->random = originalHead->next->next->next;
    originalHead->next->next->random = originalHead->next->next->next->next;
    originalHead->next->next->next->random = NULL;
    originalHead->next->next->next->next->random = originalHead->next;

    print(originalHead);

    Node* clonedHead = cloneList(originalHead);

    print(clonedHead);

    return 0;
}
