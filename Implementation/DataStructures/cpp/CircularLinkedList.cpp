#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node* next = NULL;

        Node(int data)
        {
            this->data = data;
        }
};

void insertAtKey(Node* n, int value, int key)
{
    if (n->next == NULL) return;

    Node* temp = n->next;
    while(temp != n && temp->data != key)
        temp = temp->next;

    if (temp == n) return;

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void removeAtKey(Node** n, int key)
{
    if ((*n)->next == NULL) return;

    Node* temp = (*n)->next;
    Node* prevTemp = temp;
    while (temp != *n && temp->data != key)
    {
        prevTemp = temp;
        temp = temp->next;
    }

    if (temp == *n) return;

    prevTemp->next = temp->next;
    temp->next = NULL;

    delete temp;
}

void printLinkedList(Node* n)
{
    if (n->next == NULL) return;

    Node* temp = n->next;
    while (temp != n)
    {
        cout << temp->data << "\n";

        temp = temp->next;
    }

    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    Node* head = new Node(0);
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = first;
    first->next = second;
    second->next = third;
    third->next = head;

    printLinkedList(head);

    insertAtKey(head, 23, 2);
    insertAtKey(head, 22, 1);

    printLinkedList(head);

    removeAtKey(&head, 22);

    printLinkedList(head);

    return 0;
}
