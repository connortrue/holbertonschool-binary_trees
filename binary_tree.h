#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <stdlib.h>

/**
 * struct queue_node_s - Queue node
 *
 * @data: Pointer to the data stored in the node
 * @next: Pointer to the next node in the queue
 */
typedef struct queue_node_s
{
    void *data;
    struct queue_node_s *next;
} queue_node_t;

/**
 * struct queue_s - Queue
 *
 * @front: Pointer to the front of the queue
 * @rear: Pointer to the rear of the queue
 */
typedef struct queue_s
{
    queue_node_t *front;
    queue_node_t *rear;
} queue_t;

void enqueue(queue_t **queue, void *data);
void *dequeue(queue_t **queue);
size_t queue_size(const queue_t *queue);

#endif /* BINARY_TREE_H */
