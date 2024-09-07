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

#ifndef __LINKEDQUEUE_H__
#define __LINKEDQUEUE_H__

/**
 * @file LinkedQueue.h
 *
 * @brief a Double-ended linked queue.
 *
 * A double ended queue which store values in a list in order. New values
 * can be added and removed from both head and the rare of the queue.
 *
 * Base on https://github.com/fragglet/c-algorithms.git by Simon Howard
 * It's a very helpful Repository
 *
 */
// #undef __cplusplus
#ifdef __cplusplus
// Do not recommend
// use STL Library instead of this
extern "C"
{
#endif

typedef struct _LQueue LQueue;
typedef void *LQueueValue;

LQueue *Lqueue_init(size_t type_size);
void Lqueue_free(LQueue *queue);
int Lqueue_push_front(LQueue *queue, LQueueValue data);
LQueueValue Lqueue_pop_front(LQueue *queue);
LQueueValue Lqueue_front(LQueue *queue);
int Lqueue_push_back(LQueue *queue, LQueueValue data);
LQueueValue Lqueue_pop_back(LQueue *queue);
LQueueValue Lqueue_back(LQueue *queue);
int Lqueue_is_empty(LQueue *queue);

#ifdef __cplusplus
}
#endif

#endif