#include <string.h>
#include <stdlib.h>

#include "LinkedQueue.h"


typedef struct _LQueueEntry LQueueEntry;

const void *QUEUE_NULL = 0;

struct _LQueueEntry {
    LQueueValue data;
    LQueueEntry *pre;
    LQueueEntry *nxt;
};

struct _LQueue {
    LQueueEntry *front;
    LQueueEntry *rear;
    size_t type_size;
};

LQueue *Lqueue_init(size_t type_size)
{
    LQueue *queue;

    queue = (LQueue *)malloc(sizeof(LQueue));

    if (queue == NULL) {
        return NULL;
    }

    queue->rear = NULL;
    queue->front = NULL;
    queue->type_size = type_size;
    return queue;
}

void Lqueue_free(LQueue *queue)
{
    while (!Lqueue_is_empty(queue)) {
        Lqueue_pop_front(queue);
    }

    free(queue);
}

int Lqueue_push_front(LQueue *queue, LQueueValue data)
{
    LQueueEntry *new_entry;

    new_entry = (LQueueEntry *)malloc(sizeof(LQueueEntry));

    if (new_entry == NULL) {
        return 0;
    }

    void *temp = malloc(queue->type_size);

    if (temp == NULL) {
        return 0;
    }

    memcpy(temp, data, queue->type_size);

    new_entry->data = temp;
    new_entry->pre = NULL;
    new_entry->nxt = queue->front;

    if (queue->front == NULL) {
        queue->front = new_entry;
        queue->rear = new_entry;
    }
    else {
        queue->front->pre = new_entry;
        queue->front = new_entry;
    }
    return 1;
}

LQueueValue Lqueue_pop_front(LQueue * queue)
{
    LQueueEntry *entry;
    LQueueValue result;
    if (Lqueue_is_empty(queue)) {
        return (LQueueValue)QUEUE_NULL;
    }
    entry = queue->front;
    queue->front = entry->nxt;
    result = entry->data;

    if (queue->front == NULL) {
        queue->rear = NULL;
    }
    else {
        queue->front->pre = NULL;
    }
    free(entry);

    return result;
}

LQueueValue Lqueue_front(LQueue *queue)
{
    if (Lqueue_is_empty(queue)) {
        return (LQueueValue)QUEUE_NULL;
    }
    else {
        return queue->front->data;
    }
}

int Lqueue_push_back(LQueue *queue, LQueueValue data) {
    LQueueEntry *new_entry;
    void *temp;
    new_entry = (LQueueEntry *)malloc(sizeof(LQueueEntry));
    temp = malloc(queue->type_size);
    if (new_entry == NULL || temp == NULL) {
        return 0;
    }

    memcpy(temp, data, queue->type_size);
    
    new_entry->data = temp;
    new_entry->pre = queue->rear;
    new_entry->nxt = NULL;

    if (queue->rear == NULL) {
        queue->front = new_entry;
        queue->rear = new_entry;
    }
    else {
        queue->rear->nxt = new_entry;
        queue->rear = new_entry;
    }
    return 1;
}

LQueueValue Lqueue_pop_back(LQueue *queue)
{
    LQueueEntry *entry;
    LQueueValue result;

    if (Lqueue_is_empty(queue)) {
        return (LQueueValue)QUEUE_NULL;
    }

    entry = queue->rear;
    queue->rear = entry->pre;
    result = entry->data;

    if (queue->rear == NULL) {
        queue->front = NULL;
    }
    else {
        queue->rear->nxt = NULL;
    }
    
    free(entry);
    return result;
}

LQueueValue Lqueue_back(LQueue *queue)
{
    if (Lqueue_is_empty(queue)) {
        return (LQueueValue)QUEUE_NULL;
    }
    else {
        return queue->rear->data;
    }
}

int Lqueue_is_empty(LQueue *queue)
{
    return queue->front == NULL;
}