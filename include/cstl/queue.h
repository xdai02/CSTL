#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "utils.h"

typedef struct queue_t queue_t;

queue_t *queue_create(destroy_t destroy);
void queue_destroy(queue_t *queue);
bool queue_is_empty(const queue_t *queue);
size_t queue_size(const queue_t *queue);
queue_t *queue_clear(queue_t *queue);
queue_t *queue_enqueue(queue_t *queue, T elem);
T queue_dequeue(queue_t *queue);
T queue_get_front(const queue_t *queue);
T queue_get_back(const queue_t *queue);

#endif
