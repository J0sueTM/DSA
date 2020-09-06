class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

def insertAtKey(n, value, key):
    if n.next == None:
        return

    temp = n.next
    while temp != n and temp.data != key:
        temp = temp.next

    if temp == n:
        return

    newNode = Node(value)
    newNode.next = temp.next
    temp.next = newNode

def removeAtKey(n, key):
    if n.next == None:
        return

    temp = n.next
    prevTemp = temp
    while temp != n and temp.data != key:
        prevTemp = temp
        temp = temp.next

    if temp == n:
        return

    prevTemp.next = temp.next
    del(temp)

def printLinkedList(n):
    if n.next == None:
        return

    temp = n.next
    while temp != n:
        print(temp.data)
        
        temp = temp.next

    print(" ")

head = Node(0)
first = Node(1)
second = Node(2)
third = Node(3)

head.next = first
first.next = second
second.next = third
third.next = head

printLinkedList(head)

insertAtKey(head, 23, 2)
insertAtKey(head, 22, 1)

printLinkedList(head)

removeAtKey(head, 22)

printLinkedList(head)
