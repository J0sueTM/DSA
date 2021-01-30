#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct ll_queue_node
{
  int data;

  struct ll_queue_node *next_ll_queue_node;
  struct ll_queue_node *prev_ll_queue_node;
};

struct ll_queue
{
  struct ll_queue_node *front_ll_queue_node;
  struct ll_queue_node *rear_ll_queue_node;
};

struct ll_queue
*init_ll_queue();

void
end_ll_queue(struct ll_queue **target_ll_queue);

bool
is_empty(struct ll_queue **target_ll_queue);

/* if true, will get the front, otherwise will get rear
 *
 * I could've made two functions, each one for the two sides:
 *  get_front() and get_rear()
 * which would work either. This is a method I thought would save a couple
 * lines therefore a bit more efficient.
*/
int
*get_data(struct ll_queue **target_ll_queue,
         bool               get_front);

struct ll_queue_node
*enqueue(struct ll_queue **target_ll_queue,
         int              new_ll_queue_node_data);

int
dequeue(struct ll_queue **target_ll_queue);

/* MAIN */
int
main(void)
{
  struct ll_queue *test_ll_queue = init_ll_queue();

  enqueue(&test_ll_queue, 10);
  enqueue(&test_ll_queue, 29);
  enqueue(&test_ll_queue, 352);

  printf("%d\n", *get_data(&test_ll_queue, false)); /* rear: 352 */

  dequeue(&test_ll_queue);

  printf("%d\n", *get_data(&test_ll_queue, true)); /* front: 29 */

  enqueue(&test_ll_queue, 333);
  dequeue(&test_ll_queue);
  dequeue(&test_ll_queue);

  printf("%d\n", *get_data(&test_ll_queue, true)); /* front: 333 */

  printf("%s\n", is_empty(&test_ll_queue) ? "empty" : "not empty");

  end_ll_queue(&test_ll_queue);

  return 0;
}
/* MAIN */

struct ll_queue
*init_ll_queue()
{
  struct ll_queue *new_ll_queue = (struct ll_queue *)malloc(sizeof(struct ll_queue));
  if (!new_ll_queue)
    return NULL;

  new_ll_queue->rear_ll_queue_node = (struct ll_queue_node *)malloc(sizeof(struct ll_queue_node));
  if (!new_ll_queue->rear_ll_queue_node)
    return NULL;
  new_ll_queue->front_ll_queue_node = (struct ll_queue_node *)malloc(sizeof(struct ll_queue_node));
  if (!new_ll_queue->front_ll_queue_node)
    return NULL;

  new_ll_queue->front_ll_queue_node->prev_ll_queue_node = new_ll_queue->rear_ll_queue_node;
  new_ll_queue->rear_ll_queue_node->next_ll_queue_node = new_ll_queue->front_ll_queue_node;

  return new_ll_queue;
}

void
end_ll_queue(struct ll_queue **target_ll_queue)
{
  if (!(*target_ll_queue))
    return;

  free(*target_ll_queue);
}

int
*get_data(struct ll_queue **target_ll_queue,
          bool              get_front)
{
  if (!(*target_ll_queue) ||
      is_empty(target_ll_queue))
    return NULL;

  if (get_front)
    return &(*target_ll_queue)->front_ll_queue_node->prev_ll_queue_node->data;

  return &(*target_ll_queue)->rear_ll_queue_node->next_ll_queue_node->data;
}

bool
is_empty(struct ll_queue **target_ll_queue)
{
  return (*target_ll_queue)->rear_ll_queue_node->next_ll_queue_node == (*target_ll_queue)->front_ll_queue_node;
}

struct ll_queue_node
*enqueue(struct ll_queue **target_ll_queue,
         int               new_ll_queue_node_data)
{
  if (!(*target_ll_queue))
    return NULL;

  struct ll_queue_node *new_ll_queue_node = (struct ll_queue_node *)malloc(sizeof(struct ll_queue_node));
  if (!new_ll_queue_node)
    return NULL;
  new_ll_queue_node->data = new_ll_queue_node_data;

  (*target_ll_queue)->rear_ll_queue_node->next_ll_queue_node->prev_ll_queue_node = new_ll_queue_node;
  new_ll_queue_node->next_ll_queue_node = (*target_ll_queue)->rear_ll_queue_node->next_ll_queue_node;
  (*target_ll_queue)->rear_ll_queue_node->next_ll_queue_node = new_ll_queue_node;

  return new_ll_queue_node;
}

int
dequeue(struct ll_queue **target_ll_queue)
{
  if (!(*target_ll_queue) ||
      is_empty(target_ll_queue))
    return INT_MIN;

  struct ll_queue_node *temp_prev_ll_node = (*target_ll_queue)->front_ll_queue_node->prev_ll_queue_node->prev_ll_queue_node;
  int dequeued_ll_queue_node_data = temp_prev_ll_node->next_ll_queue_node->data;

  free((*target_ll_queue)->front_ll_queue_node->prev_ll_queue_node);

  (*target_ll_queue)->front_ll_queue_node->prev_ll_queue_node = temp_prev_ll_node;
  temp_prev_ll_node->next_ll_queue_node = (*target_ll_queue)->front_ll_queue_node;

  return dequeued_ll_queue_node_data;
}
