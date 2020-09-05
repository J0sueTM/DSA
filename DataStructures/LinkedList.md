# Linked List

A linked list is a linear data structure (that works in linear time (On)), in which the elements are not stored at contiguous memory locations, like arrays. Linked Lists work like elements with data and pointer to another element.

```
Head -> A{data | pointer to B} -> B{data | pointer to C} -> C{data | pointer to null} -> null
```

The linked list begins with a header, which is just a pointer to the first element and end with a null pointer

In comparison with array, linked lists are good at insertion, deletion and modification. You can modify the size of a linked list, insert and delete new elements wherever you want, etc. Things you cannot do with arrays.

There are 3 main types of Linked lists:

- Single Linked List
- Circular Linked List
- Doubly Linked List

## Single Linked List

### creating a single linked list:

```
class Node:
    integer data
    Node next = null

    Node(integer data):
        this.data = data
end

Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new Node(3)

head.next = first
first.next = second
second.next = third
```

at the end, we've created this:

```
head{0 | first} -> first{1 | second} -> second{2 | third} -> third{3 | null} -> null
```

### insert node at single linked list

```
class Node
    integer data
    Node next = NULL

    Node(integer data):
        this.data = data
end

function insertAtStart(Node n, integer value)
    if n is null:
        return

    Node newNode = new Node(value)
    newNode.next = n
    n = newNode
end

function insertAtMiddle(Node n, integer value, integer key):
    if n is null:
        return

    Node temp = n
    while temp is not null and temp.data is not key:
        temp = temp.next

    Node newNode = new Node(value)
    newNode.next = temp.next
    temp.next = newNode
end

function insertAtEnd(Node n, integer value):
    if n is null:
        return

    Node temp = n
    while temp.next is not null:
        temp = temp.next

    Node newNode = newNode(value)
    temp.next = newNode
end

Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new Node(3)

head.next = first
first.next = second
second.next = third

insertAtStart(head, value)
insertAtMiddle(head, value, key)
insertAtEnd(head, value)
```

We started with something like this:

```
head{0 | first} -> first{1 | second} -> second{2 | third} -> third{3 | null} -> null
```

Each process can be explained as following:

**InsertAtStart**

- check if the given head node isn't null
- create a new node
- create a next pointer to this node, that points to the head
- turn the just inserted node the head

**InsertAtMiddle**

- check if the given head node isn't null
- create a temporary node that archives the given head node
- iterate with this temporary node throughout the linked list untill the given position where the node will be inserted
- create a new node
- create a pointer to this node, taht points to the next pointer of the temporary node
- point the temporary node's pointer to the created node

**InsertAtEnd**

- check if the given head node isn't null:
    * add the node after this null node
- create a temporary node that archives the given head node
- iterate with this temporary node throughout the linked list untill the last node points to null
- create a new node
- point the temporary node's pointer to the created node 

### Delete node from single linked list

```
class Node
    integer data
    Node next = null

    Node(integer data):
        this.data = data
end

function deleteAtKey(Node n, integer key):
    if n is null:
        return

    Node temp = n
    Node prevTemp

    if temp.data == key:
        n = temp.next
        delete(temp)

        return

    while temp is not null and temp.data is not key:
        prevTemp = temp
        temp = temp.next

    if temp is null:
        return

    prevTemp = temp.next
    delete(temp)
end

Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new Node(3)

head.next = first
next.next = second
second.next = third

deleteAtKey(head, key)
```

We started with something like this:

```
head{0 | first} -> first{1 | second} -> second{2 | third} -> third{3 | null} -> null
```

Each step can be explained as following:

- check if the given head node is null
- create node to store the head node, an a node to store the previous node of the current node
- check if the head node has the given key:
    * turn the next node of the head the new head
    * delete the head node stored at temp
- iterate throughout the linked list while: 
    * **the current node isn't null**
    * **the current node's data isn't the given key**
- check if we finished the iteration and now the current node is the last one (null):
    * return
- Soon we are at the last node
- turn prevTemp to the node current node is pointing to
- delete the current node (temp)

## Circular Linked List
