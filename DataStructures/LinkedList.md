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

Circular Linked Lists are just like Single Linked Lists, the difference is that the last node is not pointing to null, but to another node within the linked list, which can be the head, the first node, or any other node

### Creating a Circular Linked List

```
class Node
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
second.node = third
third.next = head
```

At the end, we've created this:

```
head{0 | first} -> first{1 | second}

       ↑                   ↓  

third{3 | head} <- second{2 | third}
```

### Insert in a Circular Linked List

```
class Node
    integer data
    Node next = null

    Node(integer data):
        this.data = data
end

function insertAtKey(Node n, integer value, integer key):
    if n.next is null:
        return

    Node temp = n.next
    while temp is not n and temp.data is not key:
        temp = temp.next

    if temp is n:
        return

    Node newNode = newNode(value)
    newNode.next = temp.next
    temp.next = newNode
end

function printLinkedList(Node n):
    if n is null:
        return

    write(n.data)
    Node temp = n.next
    while temp is not n:
        write(temp.data)

        temp = temp.next
end

Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new Node(3)

head.next = first
first.next = second
second.next = third
third.next = first

insertAtKey(head, value, key)
```

Each step can be explained as follow:

- Check if the given head node isn't null
- Create node tehat stores the given head node
- Iterate throughout the linked list, until the current temp node is the give head node, or the current temp node's data is the given key
- Check if the current temp node is the given head node:
    * cancel operation, a node that stores the given key wasn't found 
- Create new node that stores the given value
- turn the new node's pointer to the temp node
- turn the temp node's pointer to the new node

### delete node from circular linked list

```
class Node
    integer data
    Node next = null

    Node(integer data)
        this.data = data
end

function printLinkedList(Node n, integer key):
    if n.next is null:
        return

    Node temp = n.next
    Node prevTemp = temp
    while temp is not n && temp.data is not key:
        prevTemp = temp
        temp = temp.next

    if temp is n:
        return

    prevTemp.next = temp.next
    temp.next = null

    delete temp
end

Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new node(3)

head.next = first
first.next = second
second.next = third
third.next = head

printLinkedList(head)

removeAtKey(head, key)

printLinkedList(head)
```

The steps can be explained as follow:

- Check if the given head node's next isn't null:
    * return
- Create two nodes that stores the given head node
- Iterate the linked list with the two create nodes untill the current temp node is the given head node, or the current temp node's data is the given key
- Check if the current temp node is the given head node again:
    * return
- Turn prevTemp's pointer to the temp's next
- null the temp's pointer
- delete the temp node

## Doubly Linked List

A doubly linked list can be both a single linked list or a circular linked list, the difference is that a doubly linked list's nodes have pointers for both next node and the previous node

### creating a doubly linked list

```
class Node
    integer data
    Node next = null
    Node prev = null

    Node(integer data):
        this.data = data
end

//single linked list
Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new node(3)

head.next = first

first.next = second
first.prev = head

second.next = third
second.prev = first

third.prev = second

//circular linked list
Node nhead = new Node(0)
Node nfirst = new Node(1)
Node nsecond = new Node(2)
Node nthird = new Node(3)

nhead.next = nfirst
nhead.prev = nthird

nfirst.next = nsecond
nfirst.prev = nhead

nsecond.next = nthird
nsecond.prev = nfirst

nthird.next = nhead
nthird.prev = nsecond

``` 

So far, we've created this:

for the doubly single linked list:

```
head{0 | first} -> first{1 | second} -> second{2 | third} -> third{3 | null} -> null
```

for the doubly circular linked list:
```
head{0 | first} -> first{1 | second}

       ↑                   ↓  

third{3 | head} <- second{2 | third}
```

### insert at a doubly linked list

```
class Node
    integer data
    Node next = null
    Node prev = null

    Node(integer data):
        this.data = data
end

function insertAtStart(Node n, int value):
    if n.next is null:
        return

    Node temp = n
    Node newNode = new Node(value)
    newNode.next = temp.next
    if temp.next is not null:
        temp.next.prev = newNode
    newNode.prev = temp
    temp.next = newNode
end

function insertAtKey(Node n, int value, int key):
    if n.next is null:
        return

    Node temp = n.next
    while temp is not null and temp is not n and temp.data is not key:
        temp = temp.next

    if temp is null or temp is n:
        return

    Node newNode = new Node(value)
    newNode.next = temp.next
    newNode.prev = temp
    temp.next = newNode
end

function printLinkedList(Node n):
    if n.next is null:
        return

    Node temp = n.next
    while temp is not null and temp is not n:
        write(temp.data)
        temp = temp.next
end

//single linked list
Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new node(3)

head.next = first

first.next = second
first.prev = head

second.next = third
second.prev = first

third.prev = second

//circular linked list
Node nhead = new Node(0)
Node nfirst = new Node(1)
Node nsecond = new Node(2)
Node nthird = new Node(3)

nhead.next = nfirst
nhead.prev = nthird

nfirst.next = nsecond
nfirst.prev = nhead

nsecond.next = nthird
nsecond.prev = nfirst

nthird.next = nhead
nthird.prev = nsecond

printLinkedList(head)
printLinkedList(nhead)

insertAtStart(head, value)
insertAtKey(head, value, key)

printLinkedList(head)
printLinkedList(nhead)

removeAtKey(head, key)

printLinkedList(head)
printLinkedList(nhead)
```

All the processes can be explained as follow:

**Insert at start**

- Check if the next node of the given head isn't null:
    * return
- Create temporary node that stores the given head node
- Create new node that stores the given value
- Turn the new node's next pointer to the temporary node's next pointer
- Check if the next node of the temporary node isn't null:
    - Turn the previous node of the next node of the temporary node the newNode
- Turn the next node of the temporary node the newNode

### delete node from doubly linked list

```
class Node
    integer data
    Node next = null
    Node prev = null

    Node(integer data):
        this.data = data
end

function removeAtKey(Node n, int key):
    if n.next is null:
        return

    Node temp = n
    while temp is not null and temp is not n and temp.data is not key:
        temp = temp.next

    if temp is null or temp is n:
        return

    if temp.next is not null:
        temp.next.prev = temp.prev
    temp.prev.next = temp.next
    temp.next.prev = temp.prev
    
    delete temp
end

function printLinkedList(Node n):
    if n.next is null:
        return

    Node temp = n.next
    while temp is not null and temp is not n:
        write(temp.data)
        temp = temp.next
end

//single linked list
Node head = new Node(0)
Node first = new Node(1)
Node second = new Node(2)
Node third = new node(3)

head.next = first

first.next = second
first.prev = head

second.next = third
second.prev = first

third.prev = second

//circular linked list
Node nhead = new Node(0)
Node nfirst = new Node(1)
Node nsecond = new Node(2)
Node nthird = new Node(3)

nhead.next = nfirst
nhead.prev = nthird

nfirst.next = nsecond
nfirst.prev = nhead

nsecond.next = nthird
nsecond.prev = nfirst

nthird.next = nhead
nthird.prev = nsecond

printLinkedList(head)
printLinkedList(nhead)

removeAtKey(head, key)

printLinkedList(head)
printLinkedList(nhead)
```

The explanation:

- Check if the next node of the given head node isn't null
- Create temporary node that stores the next node of the given head node
- Check if the temporary node is not null and the temporar node is not the given head node and the data of the temporary node is not the key:
    - Turn the temporary node the next node of the temporary node
- Check if the next node of the temporary node isn't null:
    - Tuen the previous node of the next node of the temporary node the previous node of the temporary node
- Turn the next node of the previous node of the temporary node the next node of the temporary node
- Delete the temporary node
