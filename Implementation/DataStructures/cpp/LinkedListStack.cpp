#include <bits/stdc++.h>

class StackNode {
  public:
    StackNode(int nodeData) {
      this->data = nodeData;
      this->nextNode = NULL;
    }

    int data;
    StackNode* nextNode;
};

class Stack {
  public:
    Stack() {
      this->rootNode = new StackNode(0);
    }

    ~Stack() {
      delete this->rootNode;
    }

    const bool isEmpty() {
      return this->currentTopNode == this->rootNode;
    }

    StackNode* pushStackNode(const int newNodeData) {
      StackNode* newNode = new StackNode(newNodeData);
      newNode->nextNode = this->currentTopNode;
      this->currentTopNode = newNode;

      return newNode;
    }

    int popStackNode() {
      if (this->isEmpty())
        return INT_MIN;

      StackNode* tempStackNode = currentTopNode;
      currentTopNode = currentTopNode->nextNode;
      int poppedStackData = tempStackNode->data;
      delete tempStackNode;

      return poppedStackData;
    }

    int topStackNode() {
      if (isEmpty())
        return INT_MIN;

      return currentTopNode->data;
    }

    void print() {
      while (!this->isEmpty()) {
        printf("%d\n", this->currentTopNode->data);
        this->popStackNode();
      }    
    }

    StackNode* currentTopNode;
    StackNode* rootNode;
};

int main() {
  Stack* __Stack = new Stack();
  __Stack->pushStackNode(10);
  __Stack->pushStackNode(50);
  __Stack->pushStackNode(80);
  __Stack->pushStackNode(100);

  printf("%d\n", __Stack->topStackNode());

  printf("%d\n", __Stack->popStackNode());

  printf("%s\n", __Stack->isEmpty() ? "is empty" : "is not empty");

  __Stack->print();

  delete __Stack;

  return 0;
}
