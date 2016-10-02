#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#ifndef MEMORY_H_
#define MEMORY_H_

typedef struct memory *memory;

memory memory_new(void);
void memory_free(memory mem);
int memory_get(memory mem);
bool memory_set(memory mem, int value);
bool memory_increment(memory mem);
bool memory_decrement(memory mem);
bool memory_shift_right(memory mem);
bool memory_shift_left(memory mem);
void memory_print(memory mem);

#endif