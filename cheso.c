#include <stdio.h>
#include <stdlib.h>

#include "machine.h"

char *read_instructions();
void start_machine();

int main(int argc, char *argv[]) {
	if (argc > 1)
		printf("Please run Cheso programs with standard input");
	else
		start_machine();

	return 0;
}

void start_machine() {
	char *instructions = read_instructions();
	machine m = machine_new();
	machine_run(m, instructions);
	machine_free(m);
	free(instructions);
}

char *read_instructions() {
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