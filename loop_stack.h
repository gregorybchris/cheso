#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>

#ifndef LOOP_STACK_H_
#define LOOP_STACK_H_

typedef struct loop_stack *loop_stack;

loop_stack loop_stack_new();
void loop_stack_free(loop_stack stack);
int loop_stack_pop(loop_stack stack);
void loop_stack_push(loop_stack stack, int position);
int loop_stack_size(loop_stack stack);
bool loop_stack_empty(loop_stack stack);

#endif