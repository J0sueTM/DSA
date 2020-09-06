class Node
{
    public int data;
    public Node next = null;

    public Node(int data)
    {
        this.data = data;
    }
}

public class SingleLinkedList
{
    public static void insertAtStart(Node n, int value)
    {
        if (n == null) return;

        Node newNode = new Node(value);
        newNode.next = n;
        n = newNode;
    }

    public static void insertAtMiddle(Node n, int value, int key)
    {
        if (n == null) return;

        Node temp = n;
        while (temp != null && temp.data != key)
            temp = temp.next;

        if (temp == null) return;

        Node newNode = new Node(value);
        newNode.next = temp.next;
        temp.next = newNode;
    }

    public static void insertAtEnd(Node n, int value)
    {
        if (n == null) return;

        Node temp = n;
        while (temp.next != null)
            temp = temp.next;

        Node newNode = new Node(value);
        newNode.next = temp.next;
        temp.next = newNode;
    }

    public static void removeAtKey(Node n, int key)
    {
        if (n == null) return;

        Node temp = n;
        Node prevTemp = temp;
        if (temp.data == key)
        {
            n = temp.next;
            temp = null;

            return;
        }

        while (temp != null && temp.data != key)
        {
            prevTemp = temp;
            temp = temp.next;
        }

        if (temp == null) return;

        prevTemp.next = temp.next;
        temp = null;

        return;
    }

    public static void printLinkedList(Node n)
    {
        if (n == null) return;

        Node temp = n;
        while (temp != null)
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

        printLinkedList(head);

        insertAtStart(head, 3);
        insertAtMiddle(head, 23, 1);
        insertAtEnd(head, 22);

        printLinkedList(head);

        removeAtKey(head, 23);

        printLinkedList(head);
    }
}
