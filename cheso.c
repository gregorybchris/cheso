#include <stdio.h>
#include <stdlib.h>

#include "machine.h"

/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */
/*                                   cheso                                 */
/*                                                                         */
/*     This is the main file that starts execution of a cheso program.     */
/*   It starts the execution loop and iterprets the code in the file       */
/*   piped in as input to standard in.                                     */
/*                                                                         */
/* ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ */

char *read_instructions();
void start_machine();

/*
 * Function: main
 * Description: main method, checks for input types and starts the cheso machine
 */
int main(int argc, char *argv[]) {
	if (argc > 1)
		printf("Please run Cheso programs with standard input");
	else
		start_machine();

	return 0;
}

/*
 * Function: start_machine
 * Description: creates a cheso machine, gets instructions, and starts execution
 */
void start_machine(void) {
	char *instructions = read_instructions();
	machine m = machine_new();
	machine_run(m, instructions);
	machine_free(m);
	free(instructions);
}

/*
 * Function: read_instructions
 * Description: reads instructions from standard input and saves them in a buffer
 */
char *read_instructions(void) {
	int code_capacity = 10;
	char *code = malloc(code_capacity);
	if (code == NULL) {
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}

	int c;
	int code_size = 0;
	while ((c = getchar()) != EOF) {
		// If the buffer has run out
		if (code_size >= code_capacity - 1) {
			code_capacity *= 2;
			code = realloc(code, code_capacity);
			if (code == NULL) {
				fprintf(stderr, "Out of memory\n");
				exit(1);
			}
		}

		code[code_size] = c;
		code_size++;
	}

	code[code_size] = '\0';

	return code;
}