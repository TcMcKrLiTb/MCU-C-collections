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

#include "CircularQueue.h"

typedef struct _CQueueEntry CQueueEntry;

const void *CQUEUE_NULL = 0;

struct _CQueue
{
    CQueueValue *databuf;
    unsigned int front;
    unsigned int rear;
    size_t type_size;
};

/// @brief Initialize a new circular queue
/// @param type_size size of the type
/// @param size size of queue buf
/// @return new queue
CQueue *Cqueue_init(size_t type_size, int size)
{
    CQueue *queue;
    queue = (CQueue *)malloc(sizeof(CQueue));

    if (queue == NULL)
    {
        return NULL;
    }
    queue->front = 0;
    queue->rear = 0;
    queue->databuf = (CQueueValue *)malloc(type_size * size);
    queue->type_size = type_size;
    return queue;
}

/// @brief Release the space cost by a linked queue
/// @param queue
void Cqueue_free(CQueue *queue)
{
    free(queue->databuf);
}

/// @brief Add a new data from the tail of the queue
/// @param queue
/// @param data
/// @return
int Cqueue_push_back(CQueue *queue, CQueueValue data)
{
    memcpy((char *)queue->databuf + queue->rear * queue->type_size,
           data, queue->type_size);
    
}
