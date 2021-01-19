class StackNode {
    public static int data;
    public static StackNode nextNode;

    StackNode(int nodeData) {
        this.data = nodeData;        
        this.nextNode = null;
    }
}

class _Stack {
    protected static StackNode rootNode;
    public static StackNode currentTopNode;

    _Stack() {
        rootNode = new StackNode(0);
        currentTopNode = rootNode;
    }

    public static boolean isEmpty() {
        return currentTopNode == rootNode;
    }    

    public static StackNode pushStackNode(int nodeData) {
        StackNode newStackNode = new StackNode(nodeData);
        newStackNode.nextNode = currentTopNode;
        currentTopNode = newStackNode;

        return newStackNode;
    }

    public static int popStackNode() {
        if (isEmpty())
            return Integer.MIN_VALUE; // stack underflow

        StackNode tempStackNode = currentTopNode.nextNode;
        int poppedStackNodeData = tempStackNode.data;
        currentTopNode = null;
        currentTopNode = tempStackNode;

        return poppedStackNodeData;
    }

    public static int topStackNode() {
        if (isEmpty())
            return Integer.MIN_VALUE; // stack underflow

        return currentTopNode.data;
    }
}

public class Stack {
    public static void main(String[] args) {
        _Stack testStack = new _Stack();

        testStack.pushStackNode(23);
        testStack.pushStackNode(52);
        testStack.pushStackNode(20);

        System.out.println(testStack.popStackNode());

        System.out.println(testStack.isEmpty() ? "empty" : "not empty");

        System.out.println(testStack.topStackNode());
    }
}
