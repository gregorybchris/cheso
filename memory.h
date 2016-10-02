#include <stdio.h>
#include <stdlib.h>

#ifndef MEMORY_H_
#define MEMORY_H_

typedef struct memory *memory;

memory memory_new();
void memory_free(memory mem);
int memory_get(memory mem);
void memory_increment(memory mem);
void memory_decrement(memory mem);
void memory_shift_right(memory mem);
void memory_shift_left(memory mem);

#endif