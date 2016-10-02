#include "machine.h"
#include "memory.h"
#include "loop_stack.h"

#define INITIAL_CAPACITY 5

struct machine {
	int instruction_pointer;
	loop_stack stack;
	memory mem;
};

void execute_start(machine m);
void execute_end(machine m);
void execute_left(machine m);
void execute_right(machine m);
void execute_up(machine m);
void execute_down(machine m);
void execute_print(machine m);
void execute_input(machine m);

/*
 * Function: memory_new
 * Description: constructor for a register memory
 */
machine machine_new() {
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

void machine_free(machine m) {
	memory_free(m->mem);
	loop_stack_free(m->stack);
	free(m);
}

void machine_run(machine m, char *instructions) {
	printf("Program text: %s \n", instructions);
	
	while (true) {
		char instruction = instructions[m->instruction_pointer];
		switch (instruction) {
			case 's':
			execute_start(m);
			break;
			case 'e':
			execute_end(m);
			break;
			case 'u':
			execute_up(m);
			break;
			case 'd':
			execute_down(m);
			break;
			case 'l':
			execute_left(m);
			break;
			case 'r':
			execute_right(m);
			break;
			case 'p':
			execute_print(m);
			break;
			case 'i':
			execute_input(m);
			break;
			default:
			fprintf(stderr, "Uknown instruction: %c in program", instruction);
			break;
		}

		m->instruction_pointer++;
		if (instructions[m->instruction_pointer] == '\0')
			break;
	}
}

void execute_start(machine m) {

}

void execute_end(machine m) {

}

void execute_left(machine m) {

}

void execute_right(machine m) {

}

void execute_up(machine m) {
	memory_increment(m->mem);
}

void execute_down(machine m) {
	memory_decrement(m->mem);
}

void execute_print(machine m) {
	printf("%d", memory_get(m->mem));
}

void execute_input(machine m) {

}


