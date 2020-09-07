class Node
{
    public int data;
    public Node next = null;
    public Node prev = null;
    
    public Node(int data)
    {
        this.data = data;
    }
}

public class DoublyLinkedList
{
    public static void printLinkedList(Node n)
    {
        if (n.next == null)
            return;

        Node temp = n.next;
        while (temp != null && temp != n)
        {
            System.out.println(temp.data);

            temp = temp.next;
        }

        System.out.println("");
    }

    public static void insertAtStart(Node n, int value)
    {
        if (n == null)
            return;

        Node temp = n;
        Node newNode = new Node(value);
        newNode.next = temp.next;
        newNode.prev = n;
        if (n.next != null)
            n.next.prev = newNode;
        n.next = newNode;
    }

    public static void insertAtKey(Node n, int value, int key)
    {
        if (n.next == null)
            return;

        Node temp = n.next;
        while (temp != null && temp != n && temp.data != key)
            temp = temp.next;

        if (temp == null || temp == n)
            return;

        Node newNode = new Node(value);
        newNode.next = temp.next;
        newNode.prev = temp;
        if (temp.next != null)
            temp.next.prev = newNode;
        temp.next = newNode;
    }

    public static void removeAtKey(Node n, int key)
    {
        if (n.next == null)
            return;

        Node temp = n.next;
        while (temp != null && temp != n && temp.data != key)
            temp = temp.next;

        if (temp == null || temp == n)
            return;

        if (temp.next != null)
            temp.next.prev = temp.prev;
        temp.prev.next = temp.next;

        temp = null;
    }

    public static void main(String[] args)
    {
        //single linked list
        Node head = new Node(0);
        Node first = new Node(1);
        Node second = new Node(2);
        Node third = new Node(3);

        head.next = first;
        
        first.next = second;
        first.prev = head;

        second.next = third;
        second.prev = first;

        third.prev = second;

        //circular linked list
        Node nhead = new Node(0);
        Node nfirst = new Node(1);
        Node nsecond = new Node(2);
        Node nthird = new Node(3);

        nhead.next = nfirst;
        nhead.prev = nthird;

        nfirst.next = nsecond;
        nfirst.prev = nhead;

        nsecond.next = nthird;
        nsecond.prev = nfirst;

        nthird.next = nhead;
        nthird.prev = nsecond;

        printLinkedList(head);
        printLinkedList(nhead);

        insertAtStart(head, 4);
        insertAtKey(nhead, 64, 3);

        printLinkedList(head);
        printLinkedList(nhead);

        removeAtKey(head, 3);
        removeAtKey(nhead, 64);

        printLinkedList(head);
        printLinkedList(nhead);
    }
}
