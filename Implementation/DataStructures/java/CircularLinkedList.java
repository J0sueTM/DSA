class Node
{
    public int data;
    public Node next = null;

    public Node(int data)
    {
        this.data = data;
    }
}

public class CircularLinkedList
{
    public static void insertAtKey(Node n, int value, int key)
    {
        if (n.next == null)
            return;

        Node temp = n.next;
        while (temp != n && temp.data != key)
            temp = temp.next;

        Node newNode = new Node(value);
        newNode.next = temp.next;
        temp.next = newNode;
    }

    public static void removeAtKey(Node n, int key)
    {
        if (n.next == null)
            return;

        Node temp = n.next;
        Node prevTemp = temp;
        while (temp != n && temp.data != key)
        {
            prevTemp = temp;
            temp = temp.next;
        }

        if (temp == n)
            return;

        prevTemp.next = temp.next;
        temp = null;
    }

    public static void printLinkedList(Node n)
    {
        if (n.next == null)
            return;

        Node temp = n.next;
        while (temp != n)
        {
            System.out.println(temp.data);
            temp = temp.next;
        }

        System.out.println(" ");
    }

    public static void main(String[] args)
    {
        Node head = new Node(0);
        Node first = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);

        head.next = first;
        first.next = second;
        second.next = third;
        third.next = head;

        printLinkedList(head);

        insertAtKey(head, 23, 2);
        insertAtKey(head, 22, 1);

        printLinkedList(head);

        removeAtKey(head, 22);

        printLinkedList(head);
    }
}
