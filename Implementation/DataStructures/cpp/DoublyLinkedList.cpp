#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        int data;
        Node* next = NULL;
        Node* prev = NULL;

        Node(int data)
        {
            this->data = data;
        }
};

void printLinkedList(Node* n)
{
    Node* temp = n->next;
    while (temp != NULL && temp != n)
    {
        cout << temp->data << "\n";

        temp = temp->next;
    }

    cout << "\n";
}

void insertAtStart(Node* n, int value)
{
    if (n == NULL) return;

    Node* temp = n;
    Node* newNode = new Node(value);
    newNode->next = temp->next;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

void insertAtKey(Node* n, int value, int key)
{
    if (n->next == NULL) return;

    Node* temp = n->next;
    while (temp != n && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp == n) return;

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) temp->next->prev = newNode;
    temp->next = newNode;
}

void removeAtKey(Node** n, int key)
{
    if ((*n)->next == NULL) return;

    Node* temp = (*n)->next;
    while (temp != NULL && temp != *n && temp->data != key)
        temp = temp->next;

    if (temp == NULL || temp == *n) return;

    if (temp->next != NULL) temp->next->prev = temp->prev;

    temp->prev->next = temp->next;
    temp->next = NULL;
    delete temp;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    //single doubly linked list
    Node* head = new Node(0);
    Node* first = new Node(1);
    Node* second = new Node(2);
    Node* third = new Node(3);

    head->next = first;

    first->next = second;
    first->prev = head;

    second->next = third;
    second->prev = first;

    third->prev = second;

    //circular doubly linked list
    Node* nhead = new Node(0);
    Node* nfirst = new Node(1);
    Node* nsecond = new Node(3);
    Node* nthird = new Node(2);

    nhead->next = nfirst;
    nhead->prev = nthird;

    nfirst->next = nsecond;
    nfirst->prev = nhead;

    nsecond->next = nthird;
    nsecond->prev = nfirst;

    nthird->next = nhead;
    nthird->prev = nsecond;

    printLinkedList(head);
    printLinkedList(nhead);

    insertAtStart(head, 4);
    insertAtKey(nhead, 64, 3);

    printLinkedList(head);
    printLinkedList(nhead);

    removeAtKey(&head, 3);
    removeAtKey(&nhead, 64);

    printLinkedList(head);
    printLinkedList(nhead);

    return 0;
}
