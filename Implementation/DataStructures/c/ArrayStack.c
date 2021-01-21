#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct array_stack {
  int *stack;
  unsigned int array_stack_size;
  int current_top_pos;
};

struct array_stack *create_array_stack(unsigned int stack_capacity) {
  struct array_stack *new_array_stack = (struct array_stack *)malloc(sizeof(struct array_stack));
  new_array_stack->current_top_pos = 0;
  new_array_stack->array_stack_size = stack_capacity;
  new_array_stack->stack = (int *)malloc((stack_capacity + 1) * sizeof(int));

  return new_array_stack;
}

void end_array_stack(struct array_stack **target_array_stack) {
  free((*target_array_stack)->stack);
  free(*target_array_stack);
}

bool is_empty(struct array_stack **target_array_stack) {
  return (*target_array_stack)->current_top_pos == 0;
}

bool is_full(struct array_stack **target_array_stack) {
  return (*target_array_stack)->current_top_pos == ((*target_array_stack)->array_stack_size - 1);
}

int push(struct array_stack **target_array_stack, int new_data) {
  if (is_full(target_array_stack))
    return INT_MAX; // stack overflow

  ++(*target_array_stack)->current_top_pos;  
  (*target_array_stack)->stack[(*target_array_stack)->current_top_pos] = new_data;

  return (*target_array_stack)->stack[(*target_array_stack)->current_top_pos];
}

int pop(struct array_stack **target_array_stack) {
  if (is_empty(target_array_stack))
    return INT_MIN; // stack underflow

  int popped_data = (*target_array_stack)->stack[(*target_array_stack)->current_top_pos];
  (*target_array_stack)->stack[(*target_array_stack)->current_top_pos] = 0;
  --(*target_array_stack)->current_top_pos;

  return popped_data;
}

int top(struct array_stack **target_array_stack) {
  if (is_empty(target_array_stack))
    return INT_MIN; // stack underflow

  return (*target_array_stack)->stack[(*target_array_stack)->current_top_pos];
}

int main(void) {
  struct array_stack *test_array_stack = create_array_stack(4);

  printf("%s\n", is_empty(&test_array_stack) ? "is empty" : "not empty");

  push(&test_array_stack, 82);
  push(&test_array_stack, 15);
  push(&test_array_stack, 234);
  push(&test_array_stack, 523);

  printf("%s\n", is_full(&test_array_stack) ? "is full" : "not full");

  printf("%d\n", pop(&test_array_stack));

  printf("%d\n", top(&test_array_stack));

  end_array_stack(&test_array_stack);

  return 0;
}
