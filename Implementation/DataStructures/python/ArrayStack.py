import sys

class Stack:
    def __init__(self, stack_capacity):
        self.stack = [0] * (stack_capacity + 1)
        self.stack_size = stack_capacity
        self.current_top_pos = 0

    def is_empty(self):
        return self.current_top_pos == 0

    def is_full(self):
        return self.current_top_pos == (self.stack_size - 1)

    def push(self, new_data):
        if self.is_full():
            return sys.maxsize # stack overflow

        self.current_top_pos = self.current_top_pos + 1;
        self.stack[self.current_top_pos] = new_data

        return self.stack[self.current_top_pos]

    def pop(self):
        if self.is_empty():
            return (-sys.maxsize) # stack underflow

        popped = self.stack[self.current_top_pos];
        self.stack[self.current_top_pos] = 0
        self.current_top_pos = self.current_top_pos - 1;

        return popped

    def top(self):
        if self.is_empty():
            return (-sys.maxsize) # stack underflow

        return self.stack[self.current_top_pos]

test_stack = Stack(4)

test_stack.push(10)
test_stack.push(52)
test_stack.push(238)
test_stack.push(528)
test_stack.push(962)

print(test_stack.pop())

if test_stack.is_empty():
    print("empty")
else:
    print("not empty")

if test_stack.is_full():
    print("full")
else:
    print("not full")

print(test_stack.top())
