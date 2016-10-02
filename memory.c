#include "memory.h"

#define INITIAL_CAPACITY 5

struct memory {
	int size;
	int capacity;
	int* cells;
	int cell_pointer;
};

/*
 * Function: memory_new
 * Description: constructor for a register memory
 */
memory memory_new() {
	memory mem = malloc(sizeof(struct memory));
	if (mem == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}
	mem->size = 0;
	mem->capacity = INITIAL_CAPACITY;
	mem->cells = calloc(mem->capacity, sizeof(int));
	if (mem->cells == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}
	mem->cell_pointer = 0;

	return mem;
}

/*
 * Function: memory_free
 * Description: destructor for a register memory
 */
void memory_free(memory mem) {
	free(mem->cells);
	free(mem);
}

/*
 * Function: memory_get
 * Description: gets the integer value at the current cell
 */
int memory_get(memory mem) {
	return mem->cells[mem->cell_pointer];
}

/*
 * Function: memory_increment
 * Description: increments the value at the current cell
 */
void memory_increment(memory mem) {
	mem->cells[mem->cell_pointer]++;
}

/*
 * Function: memory_decrement
 * Description: decrements the value at the current cell
 */
void memory_decrement(memory mem) {
	mem->cells[mem->cell_pointer]--;
}

/*
 * Function: memory_shift_right
 * Description: shifts the current cell pointer to the right
 */
void memory_shift_right(memory mem) {
	//TODO: Handle shift up
}

/*
 * Function: memory_shift_left
 * Description: shifts the current cell pointer to the left
 */
void memory_shift_left(memory mem) {
	//TODO: Handle shift down
}
