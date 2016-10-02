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
	if (argc < 2)
		printf("Please run Cheso on a .cheso program file");
	else if (argc > 2)
		printf("Cheso runs on one .cheso program file");
	else {
		FILE *program_file = fopen(argv[1], "r");
		char *instructions = read_instructions(program_file);
		start_machine(instructions);
		free(instructions);
	}

	return 0;
}

/*
 * Function: start_machine
 * Description: creates a cheso machine and starts execution on the given instructions
 */
void start_machine(char *instructions) {
	machine m = machine_new();
	machine_run(m, instructions);
	machine_free(m);
}

/*
 * Function: read_instructions
 * Description: reads instructions from a file
 */
char *read_instructions(FILE *program_file) {
	int code_capacity = 10;
	char *code = malloc(code_capacity);
	if (code == NULL) {
		fprintf(stderr, "Out of memory\n");
		exit(1);
	}

	int c;
	int code_size = 0;
	while ((c = (char)fgetc(program_file)) != EOF) {
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