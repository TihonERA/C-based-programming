#include <stdio.h>
#include "stack.h"

int sp = 0;
double val[MAXVAL];

void push(double f) {
	if (sp < MAXVAL) {
		val[sp++] = f;
	}
	else {
		printf("error: Stack is full\n");
	}
}

double pop(void) {
	if (sp > 0) {
		return val[--sp];
	}
	else {
		printf("error: Stack is empty\n");
		return 0.0;
	}
}
