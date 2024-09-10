#include "MyVector.h"

#include <stdlib.h>
#include <string.h>

MVector *Mvector_init(size_t type_size, char *initopt, ...);
void Mvector_free(MVector *vector);
int Mvector_push_back(MVector *vector, MVectorValue data);
MVectorValue Mvector_front(MVector *vector);
MVectorValue Mvector_back(MVector *vector);
MVectorValue Mvector_at(MVector *vector, unsigned int pos);
void Mvector_sort(MVector *vector, unsigned int start, unsigned int end, void(*sort)(void *));
unsigned int Mvector_size(MVector *vector);
int Mvector_is_empty(MVector *vector);
