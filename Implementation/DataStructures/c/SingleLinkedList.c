#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct linked_list_node {
  int data;
  struct linked_list_node *next_linked_list_node;
};

struct linked_list_node *insert_node_at_start(struct linked_list_node **root_linked_list_node, int new_node_data) {
  if (!(*root_linked_list_node))
    return NULL;

  struct linked_list_node *new_linked_list_node = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));
  new_linked_list_node->data = new_node_data;
  new_linked_list_node->next_linked_list_node = (*root_linked_list_node)->next_linked_list_node; /* expected to be NULL */
  (*root_linked_list_node)->next_linked_list_node = new_linked_list_node;

  return new_linked_list_node;
}

struct linked_list_node *insert_node_at_middle(struct linked_list_node **root_linked_list_node, int prev_node_to_insert_key, int new_node_data) {
  if (!(*root_linked_list_node))
    return NULL;

  struct linked_list_node *temp_linked_list_node = (*root_linked_list_node)->next_linked_list_node;
  while (temp_linked_list_node != NULL) {
    if (temp_linked_list_node->data == prev_node_to_insert_key)
      break;

    temp_linked_list_node = temp_linked_list_node->next_linked_list_node; 
  }

  if (!temp_linked_list_node)
    return NULL;

  struct linked_list_node *new_linked_list_node = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));
  new_linked_list_node->data = new_node_data;

  new_linked_list_node->next_linked_list_node = temp_linked_list_node->next_linked_list_node;
  temp_linked_list_node->next_linked_list_node = new_linked_list_node;

  return new_linked_list_node;
}

struct linked_list_node *insert_node_at_end(struct linked_list_node **root_linked_list_node, int new_node_data) {
  if (!(*root_linked_list_node))
    return NULL;

  struct linked_list_node *temp_linked_list_node = *root_linked_list_node;
  while (temp_linked_list_node->next_linked_list_node != NULL)
    temp_linked_list_node = temp_linked_list_node->next_linked_list_node;

  struct linked_list_node *new_linked_list_node = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));
  new_linked_list_node->data = new_node_data;
  new_linked_list_node->next_linked_list_node = temp_linked_list_node->next_linked_list_node; /* expected to be NULL */
  temp_linked_list_node->next_linked_list_node = new_linked_list_node;

  return new_linked_list_node;
}

int remove_node_at_key(struct linked_list_node **root_linked_list_node, int node_to_delete_key) {
  if (!(*root_linked_list_node))
    return INT_MIN;

  struct linked_list_node *temp_linked_list_node = *root_linked_list_node;
  while (temp_linked_list_node->next_linked_list_node != NULL) {
    if (temp_linked_list_node->next_linked_list_node->data == node_to_delete_key)
      break;

    temp_linked_list_node = temp_linked_list_node->next_linked_list_node;
  }

  if (!temp_linked_list_node->next_linked_list_node || temp_linked_list_node->next_linked_list_node == *root_linked_list_node)
    return INT_MIN;

  struct linked_list_node *temp_exchange_linked_list_node = temp_linked_list_node->next_linked_list_node;
  temp_linked_list_node->next_linked_list_node = temp_exchange_linked_list_node->next_linked_list_node;

  int removed_node_data = temp_exchange_linked_list_node->data;
  free(temp_exchange_linked_list_node);

  return removed_node_data;
}

void display_linked_list(struct linked_list_node **root_linked_list_node) {
  struct linked_list_node *temp_linked_list_node = (*root_linked_list_node)->next_linked_list_node;
  for (int i = 0; temp_linked_list_node != NULL; ++i) {
    printf("Position %d: %d\n", i, temp_linked_list_node->data);

    temp_linked_list_node = temp_linked_list_node->next_linked_list_node;
  }  
}

void end_linked_list(struct linked_list_node **root_linked_list_node) {
  struct linked_list_node *temp_linked_list_node;
  temp_linked_list_node = (*root_linked_list_node)->next_linked_list_node;
  
  while ((*root_linked_list_node)->next_linked_list_node != NULL) {
    temp_linked_list_node = temp_linked_list_node->next_linked_list_node; 
    free((*root_linked_list_node)->next_linked_list_node);

    (*root_linked_list_node)->next_linked_list_node = temp_linked_list_node;
  }

  free(*root_linked_list_node);
}

int main(void) {
  struct linked_list_node *root_node = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));
  root_node->data = 0;
  root_node->next_linked_list_node = NULL;

  insert_node_at_start(&root_node, 1);
  insert_node_at_end(&root_node, 3);
  insert_node_at_middle(&root_node, 1, 2);

  display_linked_list(&root_node);

  remove_node_at_key(&root_node, 1);

  display_linked_list(&root_node);

  end_linked_list(&root_node);

  return 0;
}
