#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct queue_node
{
  int data;
  struct queue_node *next_queue_node;
  struct queue_node *prev_queue_node;
};

struct queue_node
*enqueue(struct queue_node **root_queue_node,
         int               new_queue_node_data)
{
  if (!(*root_queue_node))
    return NULL;

  struct queue_node *new_queue_node = (struct queue_node *)malloc(sizeof(struct queue_node));
  new_queue_node->data = new_queue_node_data;

  struct queue_node *temp_queue_node = *root_queue_node;
  while (!temp_queue_node->prev_queue_node)
    temp_queue_node = temp_queue_node->prev_queue_node;

  

  return new_queue_node;
}

void
end_queue(struct queue_node **root_queue_node)
{
  if (!(*root_queue_node))
    return;

  free(*root_queue_node);
}

int
main(void)
{
  struct queue_node *root_q_node = (struct queue_node *)malloc(sizeof(struct queue_node));
  root_q_node->data = 0;
  root_q_node->prev_queue_node = NULL;
  root_q_node->next_queue_node = NULL;

  enqueue(&root_q_node, 10);

  end_queue(&root_q_node);

  return 0;
}
