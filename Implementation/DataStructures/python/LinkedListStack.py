import sys

class stack_node:
    def __init__(self, _data):
        self.data = _data
        self.next_node = None

class stack:
    def __init__(self):
        self.root_node = stack_node(0)
        self.top_stack_node = self.root_node

    def is_empty(self):
        if self.top_stack_node is self.root_node:
            return True
        else:
            return False

    def push_stack_node(self, _data):
        new_stack_node = stack_node(_data)
        new_stack_node.next_node = self.top_stack_node
        self.top_stack_node = new_stack_node

        return self.top_stack_node

    def pop_stack_node(self):
        if not self.is_empty():
            temp_stack_node = self.top_stack_node
            self.top_stack_node = self.top_stack_node.next_node

            popped_stack_node_data = temp_stack_node.data
            temp_stack_node = None

            return popped_stack_node_data
        else:
            return (-sys.maxsize) # stack underflow

    def top_stack_node_data(self):
        if not self.is_empty():
            return self.top_stack_node.data
        else:
            return (-sys.maxsize) # stack underflow

test_stack = stack()

test_stack.push_stack_node(100)
test_stack.push_stack_node(80)
test_stack.push_stack_node(30)
test_stack.push_stack_node(80)

test_stack.pop_stack_node()
print(test_stack.pop_stack_node())

if test_stack.is_empty():
    print("empty")
else:
    print("not empty")

print(test_stack.top_stack_node_data())
