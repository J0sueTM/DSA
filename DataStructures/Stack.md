# Stack

A stack is a linear data structure - works in O(n) - in which the elements are stored in a formation called FILO (first in last out) or LIFO (last in first out).
In a more counter-intuitive idea, you can think about stacks like a "stack of plates". Operations are done in those two just presented modes. The first element will be handled last, while the last inserted element will be handled first. 

## Operations

- *Push* Adds an item. If the stack is already full, it's a stack overflow.
- *Pop* Removes the last pushed item from the stack. If the stack is empty, it's a stack underflow.
- *Top* Gets the top element from the stack.
- *isEmpty* Verifyies whether the stack is empty or not.

## Implementation

The most used methods for implementing a stack are array and linked list. For efficiency and the ability to resize the stack, I'll be using linked list.

```
class Node:
    integer data
    Node next

    function __init__(_data):
        this.data = _data
        this.next = null
    end
end

function push(integer newData, Node rootNode):
    newNode = Node(newData)
    newNode.next = rootNode

    rootNode = newNode
end

function pop(Node rootNode):
    if not isEmpty(rootNode):
        tempNode = rootNode
        rootNode = rootNode.next
        delete(rootNode)        

        return rootNode.data 
    end

    return -2147483648 # stack underflow
end

function top(Node rootNode):
    if not isEmpty(rootNode):
        return rootNode.data
    end

    return -2147483648 # stack underflow
end

function isEmpty(Node rootNode):
    if rootNode.next is null:
        return true
    else:
        return false
    end
end
```
