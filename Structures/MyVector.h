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

#ifndef __MYVECTOR_H__
#define __MYVECTOR_H__

/**
 * @file MyVector.h
 *
 * @brief a LIFO structure 
 *
 * A stack store values in a array in order. New values can only be added 
 * and removed from tail. The size of vector will change automatically.
 *
 */

#ifdef __cplusplus
// Do not recommand
// Please use STL Library instead of this
extern "C"
{
#endif

typedef struct _MVector MVector;
typedef void *MVectorValue;

MVector *Mvector_init(size_t type_size, char *initopt, ...);
void Mvector_free(MVector *vector);
int Mvector_push_back(MVector *vector, MVectorValue data);
MVectorValue Mvector_front(MVector *vector);
MVectorValue Mvector_back(MVector *vector);
MVectorValue Mvector_at(MVector *vector, unsigned int pos);
void Mvector_sort(MVector *vector, unsigned int start, unsigned int end, void(*sort)(void *));
unsigned int Mvector_size(MVector *vector);
int Mvector_is_empty(MVector *vector);

#ifdef __cplusplus
}
#endif

#endif
