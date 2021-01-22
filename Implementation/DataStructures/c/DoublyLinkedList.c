#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>

enum operation_position
{
  start = 0x0,
  middle = 0x1,
  end = 0x2
};

struct linked_list_node
{
  int data;

  struct linked_list_node *prev_linked_list_node;
  struct linked_list_node *next_linked_list_node;
};

bool
is_empty(struct linked_list_node **root_linked_list_node)
{
  return (*root_linked_list_node)->next_linked_list_node == *root_linked_list_node;
}

struct linked_list_node
*insert_linked_list_node(struct linked_list_node **root_linked_list_node,
                         enum operation_position insertion_position,
                         ...)
{
  if (!(*root_linked_list_node))
    return NULL;

  va_list insertion_args;
  va_start(insertion_args, insertion_position);

  struct linked_list_node *new_linked_list_node = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));
  struct linked_list_node *temp_linked_list_node;
  int prev_linked_list_node_data;

  switch (insertion_position)
  {
  case start:
    new_linked_list_node->data = va_arg(insertion_args, int);
    va_end(insertion_args);

    temp_linked_list_node = *root_linked_list_node;
   
    break;
  case middle:
    prev_linked_list_node_data = va_arg(insertion_args, int);
    new_linked_list_node->data = va_arg(insertion_args, int);
    va_end(insertion_args);

    temp_linked_list_node = (*root_linked_list_node)->next_linked_list_node;
    while (temp_linked_list_node != *root_linked_list_node)
    {
      if (temp_linked_list_node->data == prev_linked_list_node_data)
        break;

      temp_linked_list_node = temp_linked_list_node->next_linked_list_node;
    }

    if (temp_linked_list_node == *root_linked_list_node)
      return NULL;

    break;
  case end:
    new_linked_list_node->data = va_arg(insertion_args, int);
    va_end(insertion_args);

    temp_linked_list_node = (*root_linked_list_node)->prev_linked_list_node;

    break;
  default:
    va_end(insertion_args);

    return NULL;
    break;
  }

  new_linked_list_node->next_linked_list_node = temp_linked_list_node->next_linked_list_node;
  new_linked_list_node->prev_linked_list_node = temp_linked_list_node;
  temp_linked_list_node->next_linked_list_node->prev_linked_list_node = new_linked_list_node;
  temp_linked_list_node->next_linked_list_node = new_linked_list_node;

  return new_linked_list_node;
}

int
remove_linked_list_node(struct linked_list_node **root_linked_list_node,
                        enum operation_position remove_position,
                        ...)
{
  if (!(*root_linked_list_node))
    return INT_MIN;

  va_list remove_args;

  struct linked_list_node *temp_linked_list_node;
  int remove_linked_list_node_key;

  switch (remove_position)
  {
  case start:
    if ((*root_linked_list_node)->next_linked_list_node == *root_linked_list_node)
      return INT_MIN;

    temp_linked_list_node = (*root_linked_list_node)->next_linked_list_node;

    break;
  case middle:
    va_start(remove_args, remove_position);
    va_end(remove_args);

    remove_linked_list_node_key = va_arg(remove_args, int);    
    temp_linked_list_node = (*root_linked_list_node)->next_linked_list_node;
    while (temp_linked_list_node != *root_linked_list_node)
    {
      if (temp_linked_list_node->data == remove_linked_list_node_key)
        break;

      temp_linked_list_node = temp_linked_list_node->next_linked_list_node;
    }

    if (temp_linked_list_node == *root_linked_list_node)
      return INT_MIN;

    break;
  case end:
    if ((*root_linked_list_node)->prev_linked_list_node == *root_linked_list_node)
      return INT_MIN;

    temp_linked_list_node = (*root_linked_list_node)->prev_linked_list_node;

    break;
  default:
    va_end(remove_args);

    return INT_MIN;
    break;
  }

  int removed_linked_list_node_data = temp_linked_list_node->data;
  temp_linked_list_node->prev_linked_list_node->next_linked_list_node = temp_linked_list_node->next_linked_list_node;
  temp_linked_list_node->next_linked_list_node->prev_linked_list_node = temp_linked_list_node->prev_linked_list_node;
  temp_linked_list_node->prev_linked_list_node = NULL;
  temp_linked_list_node->next_linked_list_node = NULL;

  free(temp_linked_list_node);
  return removed_linked_list_node_data;
}

void
end_linked_list(struct linked_list_node **root_linked_list_node)
{
  if (!(*root_linked_list_node))
    return;
  
  struct linked_list_node *temp_linked_list_node = (*root_linked_list_node)->prev_linked_list_node;
  while ((*root_linked_list_node)->prev_linked_list_node)
  {
    if (temp_linked_list_node == *root_linked_list_node)
      break;

    struct linked_list_node *temp_exchange_linked_list_node = temp_linked_list_node->prev_linked_list_node;

    temp_exchange_linked_list_node->next_linked_list_node = temp_linked_list_node->prev_linked_list_node;
    temp_linked_list_node->next_linked_list_node = NULL;
    temp_linked_list_node->next_linked_list_node->prev_linked_list_node = temp_exchange_linked_list_node;
    temp_linked_list_node->next_linked_list_node = NULL;

    free(temp_linked_list_node);
    temp_linked_list_node = temp_exchange_linked_list_node;
  }

  free(*root_linked_list_node);
}

void
display_linked_list(struct linked_list_node **root_linked_list_node,
                    bool reverse_display)
{
  if (!(*root_linked_list_node))
  {
    return;
  }
  else if (is_empty(root_linked_list_node))
  {
    printf("Empty\n");

    return;
  }

  struct linked_list_node *temp_linked_list_node; 

  if (reverse_display)
    temp_linked_list_node = (*root_linked_list_node)->prev_linked_list_node;
  else
    temp_linked_list_node = (*root_linked_list_node)->next_linked_list_node;

  for (int i = 0; temp_linked_list_node != *root_linked_list_node; ++i)
  {
    printf("Position %d: %d\n", i, temp_linked_list_node->data);

    temp_linked_list_node = (reverse_display) ? temp_linked_list_node->prev_linked_list_node : temp_linked_list_node->next_linked_list_node;
  }   

  printf("\n");
}

int
main(void)
{
  struct linked_list_node *root_ll_node = (struct linked_list_node *)malloc(sizeof(struct linked_list_node));
  root_ll_node->data = 0;
  root_ll_node->next_linked_list_node = root_ll_node;
  root_ll_node->prev_linked_list_node = root_ll_node;

  insert_linked_list_node(&root_ll_node, start, 3);
  insert_linked_list_node(&root_ll_node, start, 1);
  insert_linked_list_node(&root_ll_node, end, 4);
  insert_linked_list_node(&root_ll_node, end, 5);
  insert_linked_list_node(&root_ll_node, middle, 1, 2);
  
  display_linked_list(&root_ll_node, false);

  remove_linked_list_node(&root_ll_node, start);
  remove_linked_list_node(&root_ll_node, end);
  remove_linked_list_node(&root_ll_node, middle, 3);

  display_linked_list(&root_ll_node, false);

  end_linked_list(&root_ll_node);

  return (0);
}
