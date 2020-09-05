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

void insertAtStart(Node* n, int value)
{
    if (n == NULL) return;

    Node* newNode = new Node(value);
    newNode->next = n;
    n = newNode;
}

void insertAtMiddle(Node* n, int value, int key)
{
    if (n == NULL) return;

    Node* temp = n;
    while (temp != NULL && temp->data != key)
        temp = temp->next;

    if (temp == NULL) return;

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    temp->next = newNode;
}

void insertAtEnd(Node* n, int value)
{
    if (n == NULL) return;

    Node* temp = n;
    while (temp->next != NULL)
        temp = temp->next;

    Node* newNode = new Node(value);
    temp->next = newNode;
}

void removeAtKey(Node** n, int key)
{
    if (n == NULL) return;

    Node* temp = *n;
    Node* prevTemp;
    if (temp->data == key)
    {
        *n = temp->next;
        delete temp;
    }

    while (temp != NULL && temp->data != key)
    {
        prevTemp = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prevTemp->next = temp->next;
    delete temp;
}

void printLinkedList(Node* n)
{
    if (n == NULL) return;

    Node* temp = n;
    while (temp != NULL)
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

    printLinkedList(head);

    insertAtStart(head, 3);
    insertAtMiddle(head, 23, 1);
    insertAtEnd(head, 22);

    printLinkedList(head);

    removeAtKey(&head, 23);

    printLinkedList(head);

    return 0;
}
