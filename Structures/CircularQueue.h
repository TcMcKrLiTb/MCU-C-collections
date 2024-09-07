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

#ifndef __CIRCULARQUEUE_H__
#define __CIRCULARQUEUE_H__

/**
 * @file CircularQueue.h
 * 
 * @brief a FIFO structure that store values in a array.
 * New values can only added from back.
 * 
 */

#ifdef __cplusplus
// Do not recommend
// please use STL Library in C++ instead of this
extern "C"
{
#endif

typedef struct _CQueue CQueue;
typedef void *CQueueValue;

CQueue *Cqueue_init(size_t type_size, int size);
void Cqueue_free(CQueue *queue);
int Cqueue_push(CQueue *queue, CQueueValue data);
CQueueValue Cqueue_pop(CQueue *queue);
CQueueValue Cqueue_front(CQueue *queue);
int Cqueue_is_empty(CQueue *queue);

#ifdef __cplusplus
}
#endif

#endif
