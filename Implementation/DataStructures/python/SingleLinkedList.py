class Node:
    def __init__(self, data = 0):
        self.data = data
        self.next = None

def insertAtStart(node, value):
    if node == None:
        return

    temp = node
    newNode = Node(value)
    newNode.next = temp.next
    temp.next = newNode

def insertAtMiddle(node, value, key):
    if node == None:
        return

    temp = node
    while temp != None and temp.data != key:
        temp = temp.next

    if temp == None:
        return

    newNode = Node(value)
    newNode.next = temp.next
    temp.next = newNode

def insertAtEnd(node, value):
    if node == None:
        return

    temp = node
    while temp.next != None:
        temp = temp.next

    newNode = Node(value)
    newNode.next = temp.next
    temp.next = newNode

def removeAtKey(node, key):
    if node == None:
        return

    temp = node
    prevTemp = node
    while temp != None and temp.data != key:
        prevTemp = temp
        temp = temp.next

    if temp == None:
        return

    prevTemp.next = temp.next
    del temp

def printLinkedList(node):
    if node == None:
        return

    temp = node
    while temp != None:
        print(temp.data)

        temp = temp.next;

    print(" ")

head = Node(0)
first = Node(1)
second = Node(2)
third = Node(3)

head.next = first
first.next = second
second.next = third

printLinkedList(head)

insertAtStart(head, 3)
insertAtMiddle(head, 23, 1)
insertAtEnd(head, 22)

printLinkedList(head)

removeAtKey(head, 23)

printLinkedList(head)
