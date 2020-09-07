class Node:
    def __init__(self, data):
        self.data = data
        self.next = None
        self.prev = None

def printLinkedList(n):
    if n.next == None:
        return

    temp = n.next
    while temp != None and temp != n:
        print(temp.data)

        temp = temp.next

    print("")

def insertAtStart(n, value):
    if n == None:
        return

    temp = n
    newNode = Node(value)
    newNode.next = temp.next
    newNode.prev = temp
    if temp.next != None:
        temp.next.prev = newNode
    temp.next = newNode

def insertAtKey(n, value, key):
    if n.next == None:
        return

    temp = n.next
    while temp != None and temp != n and temp.data != key:
        temp = temp.next

    if temp == None or temp == n:
        return

    newNode = Node(value)
    newNode.next = temp.next
    newNode.prev = temp
    if temp.next != None:
        temp.next.prev = newNode
    temp.next = newNode

def removeAtKey(n, key):
    if n.next == None:
        return

    temp = n.next
    while temp != None and temp != n and temp.data != key:
        temp = temp.next

    if temp == None or temp == n:
        return

    temp.prev.next = temp.next
    if temp.next != None:
        temp.next.prev = temp.prev

    del(temp)

# single linked list
head = Node(0)
first = Node(1)
second = Node(2)
third = Node(3)

head.next = first

first.next = second
first.prev = head

second.next = third
second.prev = first

third.prev = second

# circular linked list
nhead = Node(0)
nfirst = Node(1)
nsecond = Node(2)
nthird = Node(3)

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

insertAtStart(head, 4)
insertAtKey(nhead, 64, 3)

printLinkedList(head)
printLinkedList(nhead)

removeAtKey(head, 3)
removeAtKey(nhead, 64)

printLinkedList(head)
printLinkedList(nhead)
