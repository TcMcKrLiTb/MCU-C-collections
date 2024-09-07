/*

BSD 2-Clause License

Copyright (c) 2024, TcMcKrLiTb

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

*/

#include <string.h>
#include <stdlib.h>

#include "LinkedQueue.h"

typedef struct _LQueueEntry LQueueEntry;

const void *LQUEUE_NULL = 0;

struct _LQueueEntry
{
    LQueueValue data;
    LQueueEntry *pre;
    LQueueEntry *nxt;
};

struct _LQueue
{
    LQueueEntry *front;
    LQueueEntry *rear;
    size_t type_size;
};

/// @brief Initialize a new linked queue
/// @param type_size size of the type
/// @return new queue
LQueue *Lqueue_init(size_t type_size)
{
    LQueue *queue;

    queue = (LQueue *)malloc(sizeof(LQueue));

    if (queue == NULL)
    {
        return NULL;
    }

    queue->rear = NULL;
    queue->front = NULL;
    queue->type_size = type_size;
    return queue;
}

/// @brief Release the space cost by a linked queue
/// @param queue queue
void Lqueue_free(LQueue *queue)
{
    while (!Lqueue_is_empty(queue))
    {
        Lqueue_pop_front(queue);
    }

    free(queue);
}

/// @brief Add a new data from head of queue
/// @param queue 
/// @param data 
/// @return 
int Lqueue_push_front(LQueue *queue, LQueueValue data)
{
    LQueueEntry *new_entry;

    new_entry = (LQueueEntry *)malloc(sizeof(LQueueEntry));

    if (new_entry == NULL)
    {
        return 0;
    }

    void *temp = malloc(queue->type_size);

    if (temp == NULL)
    {
        return 0;
    }

    memcpy(temp, data, queue->type_size);

    new_entry->data = temp;
    new_entry->pre = NULL;
    new_entry->nxt = queue->front;

    if (queue->front == NULL)
    {
        queue->front = new_entry;
        queue->rear = new_entry;
    }
    else
    {
        queue->front->pre = new_entry;
        queue->front = new_entry;
    }
    return 1;
}

LQueueValue Lqueue_pop_front(LQueue *queue)
{
    LQueueEntry *entry;
    LQueueValue result;
    if (Lqueue_is_empty(queue))
    {
        return (LQueueValue)LQUEUE_NULL;
    }
    entry = queue->front;
    queue->front = entry->nxt;
    result = entry->data;

    if (queue->front == NULL)
    {
        queue->rear = NULL;
    }
    else
    {
        queue->front->pre = NULL;
    }
    free(entry);

    return result;
}

LQueueValue Lqueue_front(LQueue *queue)
{
    if (Lqueue_is_empty(queue))
    {
        return (LQueueValue)LQUEUE_NULL;
    }
    else
    {
        return queue->front->data;
    }
}

int Lqueue_push_back(LQueue *queue, LQueueValue data)
{
    LQueueEntry *new_entry;
    void *temp;
    new_entry = (LQueueEntry *)malloc(sizeof(LQueueEntry));
    temp = malloc(queue->type_size);
    if (new_entry == NULL || temp == NULL)
    {
        return 0;
    }

    memcpy(temp, data, queue->type_size);

    new_entry->data = temp;
    new_entry->pre = queue->rear;
    new_entry->nxt = NULL;

    if (queue->rear == NULL)
    {
        queue->front = new_entry;
        queue->rear = new_entry;
    }
    else
    {
        queue->rear->nxt = new_entry;
        queue->rear = new_entry;
    }
    return 1;
}

LQueueValue Lqueue_pop_back(LQueue *queue)
{
    LQueueEntry *entry;
    LQueueValue result;

    if (Lqueue_is_empty(queue))
    {
        return (LQueueValue)LQUEUE_NULL;
    }

    entry = queue->rear;
    queue->rear = entry->pre;
    result = entry->data;

    if (queue->rear == NULL)
    {
        queue->front = NULL;
    }
    else
    {
        queue->rear->nxt = NULL;
    }

    free(entry);
    return result;
}

LQueueValue Lqueue_back(LQueue *queue)
{
    if (Lqueue_is_empty(queue))
    {
        return (LQueueValue)LQUEUE_NULL;
    }
    else
    {
        return queue->rear->data;
    }
}

int Lqueue_is_empty(LQueue *queue)
{
    return queue->front == NULL;
}