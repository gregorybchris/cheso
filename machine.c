#include "machine.h"
#include "memory.h"
#include "loop_stack.h"

/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/*                                 machine                                 */
/*                                                                         */
/*      This is the file that handles the instruction loop and handles     */
/*   managing control based on the actual instructions in the input file.  */
/*                                                                         */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */

#define INITIAL_CAPACITY 5

struct machine {
	int instruction_pointer;
	loop_stack stack;
	memory mem;
};

static bool execute_start(machine m);
static bool execute_end(machine m);
static bool execute_left(machine m);
static bool execute_right(machine m);
static bool execute_up(machine m);
static bool execute_down(machine m);
static bool execute_print(machine m);
static bool execute_input(machine m);

/*
 * Function: machine_new
 * Description: constructor for a cheso machine
 */
machine machine_new(void) {
	machine m = malloc(sizeof(struct machine));
	if (m == NULL) {
		fprintf(stderr, "ERROR: Out of memory\n");
		exit(1);
	}
	
	m->instruction_pointer = 0;
	m->stack = loop_stack_new();
	m->mem = memory_new();

	return m;
}

/*
 * Function: machine_free
 * Description: destructor for a cheso machine
 */
void machine_free(machine m) {
	memory_free(m->mem);
	loop_stack_free(m->stack);
	free(m);
}

/*
 * Function: machine_run
 * Description: starts the cheso machine fetch-decode-execute cycle
 */
void machine_run(machine m, char *instructions) {
	while (true) {
		char instruction = instructions[m->instruction_pointer];
		bool result = true;
		switch (instruction) {
			case 's':
			result = execute_start(m);
			break;
			case 'e':
			result = execute_end(m);
			break;
			case 'u':
			result = execute_up(m);
			break;
			case 'd':
			result = execute_down(m);
			break;
			case 'l':
			result = execute_left(m);
			break;
			case 'r':
			result = execute_right(m);
			break;
			case 'p':
			result = execute_print(m);
			break;
			case 'i':
			result = execute_input(m);
			break;
			case ' ':
			break;
			case '\t':
			break;
			case '\n':
			break;
			default:
			fprintf(stderr, "Unknown instruction: %c in program\n", instruction);
			exit(1);
			break;
		}
		if (!result) {
			fprintf(stderr, "\tError executing instruction at index: %d", m->instruction_pointer);
			exit(1);
		}

		m->instruction_pointer++;
		if (instructions[m->instruction_pointer] == '\0')
			break;
	}
}

/*
 * Function: execute_start
 * Description: the instruction for the beginning of a loop
 */
static bool execute_start(machine m) {
	//TODO: Write loop code for start
	return true;
}

/*
 * Function: execute_end
 * Description: the instruction for the end of a loop
 */
static bool execute_end(machine m) {
	//TODO: Write loop code for end
	return true;
}

/*
 * Function: execute_left
 * Description: the instruction for shifting left one register
 */
static bool execute_left(machine m) {
	return memory_shift_left(m->mem);
}

/*
 * Function: execute_right
 * Description: the instruction for shifting right one register
 */
static bool execute_right(machine m) {
	return memory_shift_right(m->mem);
}

/*
 * Function: execute_up
 * Description: the instruction for incrementing the current register
 */
static bool execute_up(machine m) {
	return memory_increment(m->mem);
}

/*
 * Function: execute_up
 * Description: the instruction for decrementing the current register
 */
static bool execute_down(machine m) {
	return memory_decrement(m->mem);
}

/*
 * Function: execute_up
 * Description: the instruction for printing the ascii character
 *    corresponding to the value in the current register
 */
static bool execute_print(machine m) {
	char character = (char)memory_get(m->mem);
	printf("%c", character);
	return true;
}

/*
 * Function: execute_up
 * Description: the instruction for setting the value in the current
 *     register to the next character from the standard input buffer
 */
static bool execute_input(machine m) {
	return memory_set(m->mem, getchar());
	return true;
}






