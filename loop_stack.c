#include "loop_stack.h"

/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/*                                loop_stack                               */
/*                                                                         */
/*      This is an implementation of a stack used to keep track of the     */
/*   execution of loops in a cheso program.                                */
/*                                                                         */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */

#define INITIAL_CAPACITY 5

struct loop_stack {
	int *data;
	int size;
	int capacity;
};

/*
 * Function: loop_stack_new
 * Description: constructor for a stack that holds positions of loops in a Cheso program
 */
loop_stack loop_stack_new(void) {
	loop_stack stack = malloc(sizeof(struct loop_stack));
	if (stack == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}
	stack->size = 0;
	stack->capacity = INITIAL_CAPACITY;
	stack->data = malloc(sizeof(int) * stack->capacity);
	if (stack->data == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}

	return stack;
}

/*
 * Function: loop_stack_free
 * Description: destructor for a stack that holds positions of loops in a Cheso program
 */
void loop_stack_free(loop_stack stack) {
	free(stack->data);
	free(stack);
}

/*
 * Function: loop_stack_pop
 * Description: pops a loop location value off the stack and returns it
 */
int loop_stack_pop(loop_stack stack) {
	if (stack->size == 0) {
		fprintf(stderr, "ERROR: Stack is empty\n");
		return -1;
	}
	else {
		stack->size--;
		return stack->data[stack->size];
	}
}

/*
 * Function: loop_stack_peek
 * Description: returns the top loop location value on the stack
 */
int loop_stack_peek(loop_stack stack) {
	if (stack->size == 0) {
		fprintf(stderr, "ERROR: Stack is empty\n");
		return -1;
	}
	else
		return stack->data[stack->size - 1];
}

/*
 * Function: loop_stack_push
 * Description: pushes a loop location value onto the stack
 */
void loop_stack_push(loop_stack stack, int position) {
	// Need to resize stack array
	if (stack->size == stack->capacity) {
		stack->capacity *= 2;
		stack->data = realloc(stack->data, stack->capacity);
	}
	stack->data[stack->size] = position;
	stack->size++;
}

/*
 * Function: loop_stack_size
 * Description: returns the current size of the stack
 */
int loop_stack_size(loop_stack stack) {
	return stack->size;
}

/*
 * Function: loop_stack_empty
 * Description: returns true if the stack is empty, otherwise false
 */
bool loop_stack_empty(loop_stack stack) {
	return stack->size == 0;
}