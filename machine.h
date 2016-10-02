#include <stdio.h>
#include <stdlib.h>

#ifndef MACHINE_H_
#define MACHINE_H_

typedef struct machine *machine;

machine machine_new(void);
void machine_free(machine m);
void machine_run(machine m, char *instructions);

#endif