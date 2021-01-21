#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct stack_node {
  int data;
  struct stack_node *next_stack_node;
};

bool is_empty(struct stack_node **top_stack_node) {
  return !(*top_stack_node);
}

struct stack_node *push_stack_node(struct stack_node **top_stack_node, int new_stack_node_data) {
  struct stack_node *new_stack_node = (struct stack_node *)malloc(sizeof(struct stack_node));
  new_stack_node->data = new_stack_node_data;
  new_stack_node->next_stack_node = *top_stack_node;
  *top_stack_node = new_stack_node;

  return new_stack_node;
}

int pop_stack_node(struct stack_node **top_stack_node) {
  if (is_empty(top_stack_node))
    return INT_MIN;

  struct stack_node *temp_stack_node = *top_stack_node;
  *top_stack_node = (*top_stack_node)->next_stack_node;

  int popped_stack_node_data = temp_stack_node->data;
  free(temp_stack_node);

  return popped_stack_node_data;
}

int top_stack_node_data(struct stack_node **top_stack_node) {
  if (is_empty(top_stack_node))
    return INT_MIN;

  return (*top_stack_node)->data;
}

int main(void) {
  struct stack_node *root_stack_node = (struct stack_node*)malloc(sizeof(struct stack_node));

  push_stack_node(&root_stack_node, 10);
  push_stack_node(&root_stack_node, 20);
  push_stack_node(&root_stack_node, 35);

  printf("%d\n", pop_stack_node(&root_stack_node));
  printf("%d\n", pop_stack_node(&root_stack_node));

  printf("%d\n", top_stack_node_data(&root_stack_node));

  free(root_stack_node);

  return 0;
}
