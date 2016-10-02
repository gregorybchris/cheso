#include "memory.h"

/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/*                                  memory                                 */
/*                                                                         */
/*      This file handles the program memory and specifically keeps track  */
/*   of the registers that the program can use, the values in those        */
/*   registers, and the current register being worked on in the program.   */
/*                                                                         */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */

#define INITIAL_CAPACITY 15

struct memory {
	int capacity;
	int *cells;
	int cells_start;
	int cells_end;
	int cell_pointer;
};

static void resize(memory mem);

/*
 * Function: memory_new
 * Description: constructor for a register memory
 */
memory memory_new(void) {
	memory mem = malloc(sizeof(struct memory));
	if (mem == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}
	mem->capacity = INITIAL_CAPACITY;
	mem->cells = calloc(mem->capacity, sizeof(int));
	if (mem->cells == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}
	mem->cells_start = 0;
	mem->cells_end = 0;
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
 * Function: memory_set
 * Description: sets the integer value at the current cell
 */
bool memory_set(memory mem, int value) {
	mem->cells[mem->cell_pointer] = value;
	return true;
}

/*
 * Function: memory_increment
 * Description: increments the value at the current cell
 */
bool memory_increment(memory mem) {
	mem->cells[mem->cell_pointer]++;

	if (mem->cells[mem->cell_pointer] < 0) {
		fprintf(stderr, "ERROR: Register out of range\n");
		return false;
	}
	else
		return true;
}

/*
 * Function: memory_decrement
 * Description: decrements the value at the current cell
 */
bool memory_decrement(memory mem) {
	mem->cells[mem->cell_pointer]--;

	if (mem->cells[mem->cell_pointer] < 0) {
		fprintf(stderr, "ERROR: Register out of range\n");
		return false;
	}
	else
		return true;
}

/*
 * Function: memory_shift_right
 * Description: shifts the current cell pointer to the right
 */
bool memory_shift_right(memory mem) {
	// Current pointer is out of the defined range for the registers
	if (mem->cell_pointer == mem->cells_end) {
		// Defined range of registers is completely full
		if ((mem->cells_end + 1) % mem->capacity == mem->cells_start)
			resize(mem);
		else
			mem->cells_end = (mem->cells_end + 1) % mem->capacity;
	}

	mem->cell_pointer = (mem->cell_pointer + 1) % mem->capacity;
	return true;
}

/*
 * Function: memory_shift_left
 * Description: shifts the current cell pointer to the left
 */
bool memory_shift_left(memory mem) {
	// Current pointer is out of the defined range for the registers
	if (mem->cell_pointer == mem->cells_start) {
		// Defined range of registers is completely full
		if ((mem->cells_end + 1) % mem->capacity == mem->cells_start)
			resize(mem);
		else
			mem->cells_start = (mem->cells_start + mem->capacity - 1) % mem->capacity;
	}

	mem->cell_pointer = (mem->cell_pointer + mem->capacity - 1) % mem->capacity;
	return true;
}

/*
 * Function: resize
 * Description: resizes the cells array to hold more values
 */
static void resize(memory mem) {
	int *new_cells = calloc(mem->capacity * 2, sizeof(int));
	if (new_cells == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}
	for (int i = 0; i < mem->capacity; i++)
		new_cells[i] = mem->cells[(mem->cells_start + i) % mem->capacity];
	free(mem->cells);
	mem->cell_pointer = mem->cell_pointer == mem->cells_start ? 0 : mem->capacity - 1;
	mem->cells_start = 0;
	mem->cells_end = mem->capacity - 1;
	mem->cells = new_cells;
	mem->capacity *= 2;
}

/*
 * Function: memory_print
 * Description: prints a string representation of a register memory
 */
void memory_print(memory mem) {
	printf("(Memory <capacity=%d> <cells_start=%d> <cells_end=%d> <cell_pointer=%d> ", 
		mem->capacity, mem->cells_start, mem->cells_end, mem->cell_pointer);
	printf("<cells=[");
	for (int i = 0; i < mem->capacity; i++) {
		printf("%d", mem->cells[i]);
		if (i < mem->capacity - 1)
			printf(", ");
	}
	printf("]>)\n");
}