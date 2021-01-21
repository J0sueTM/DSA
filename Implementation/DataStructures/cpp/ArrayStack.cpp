#include <bits/stdc++.h>

class ArrayStack {
  public:
    ArrayStack(unsigned int stackCapacity) {
      this->_stack = (int *)malloc((stackCapacity + 1) * sizeof(int));
      this->currentTopPos = 0;
      this->stackSize = stackCapacity;
    }

    ~ArrayStack() {
      free(this->_stack);
    }

    bool isEmpty() {
      return this->currentTopPos == 0;
    }

    bool isFull() {
      return this->currentTopPos >= (this->stackSize - 1);
    }

    int push(int new_data) {
      if (isFull())
        return INT_MAX; // stack overflow

      ++this->currentTopPos;
      this->_stack[this->currentTopPos] = new_data;

      return this->_stack[this->currentTopPos];
    }

    int pop() {
      if (isEmpty())
        return INT_MIN; // stack underflow

      int poppedData = this->_stack[this->currentTopPos];
      this->_stack[this->currentTopPos] = 0;
      --this->currentTopPos;

      return poppedData;
    }

    int top() {
      if (isEmpty())
        return INT_MIN; // stack underflow

      return this->_stack[this->currentTopPos];
    }

    int* _stack;
    int currentTopPos;
    int stackSize;
};

int main() {
  ArrayStack testArrayStack(4);

  testArrayStack.push(235);
  testArrayStack.push(24);
  testArrayStack.push(63);
  testArrayStack.push(62);

  printf("%d\n", testArrayStack.pop());

  printf("%s\n", testArrayStack.isEmpty() ? "empty" : "not empty");
  printf("%s\n", testArrayStack.isFull() ? "full" : "not full");

  return 0;
}
