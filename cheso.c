#include <stdio.h>
#include <stdlib.h>

#include "loop_stack.h"

char *read_file();
void interpret_program();

int main(int argc, char *argv[]) {
	if (argc > 1)
		printf("Please run Cheso programs with standard input");
	else
		interpret_program();

	return 0;
}

void interpret_program() {
	char *code = read_file();
	printf("Program text: %s \n", code);

	loop_stack stack = loop_stack_new();
	loop_stack_push(stack, 10);

	int value = loop_stack_pop(stack);
	printf("Loop stack value: %d\n", value);

	value = loop_stack_pop(stack);
	printf("Loop stack value: %d\n", value);

	loop_stack_free(stack);

	free(code);
}

char *read_file() {
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