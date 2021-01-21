class Stack {
    public static int arrStack[], currentTopPos, stackSize;

    Stack(int stackCapacity) {
        arrStack = new int[stackCapacity + 1];
        currentTopPos = 0;
        stackSize = stackCapacity;
    }

    public static boolean isEmpty() {
        return currentTopPos == 0;
    }

    public static boolean isFull() {
        return currentTopPos == stackSize - 1;
    }

    public static int push(int newData) {
        if (isFull())
            return Integer.MAX_VALUE; // stack overflow

        ++currentTopPos;
        arrStack[currentTopPos] = newData;
        return arrStack[currentTopPos];
    }

    public static int pop() {
        if (isEmpty())
            return Integer.MIN_VALUE; // stack underflow

        int poppedData = arrStack[currentTopPos];
        arrStack[currentTopPos] = 0;
        --currentTopPos;

        return poppedData;
    }

    public static int top() {
        if (isEmpty())
            return Integer.MIN_VALUE; // stack underflow

        return arrStack[currentTopPos];
    }
}

public class ArrayStack {
    public static void main(String[] args) {
        Stack testStack = new Stack(4);

        testStack.push(10);
        testStack.push(824);
        testStack.push(923);
        testStack.push(9614);

        System.out.println(testStack.pop());

        testStack.push(3659);

        System.out.println(testStack.isEmpty() ? "empty" : "not empty");
        System.out.println(testStack.isFull() ? "full" : "not full");

        testStack.pop();

        System.out.println(testStack.top());
    }
}
