#include "getop.h"
#include "stack.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main() {
	int type;
	double op1, op2;
	char s[MAXOP];

	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				op2 = pop();
				op1 = pop();
				push(op1 + op2);
				break;
			case '*':
				op2 = pop();
				op1 = pop();
				push(op1 * op2);
				break;
			case '-':
				op2 = pop();
				op1 = pop();
				push(op1 - op2);
				break;
			case '/':
				op2 = pop();
				op1 = pop();
				if (op2 != 0.0) {
					push(op1 / op2);
				}
				else {
					printf("error: Zero devision\n");
				}
				break;
			case '%':
				op2 = pop();
				op1 = pop();
				push(fmod(op1, op2));
				break;
			case '\n':
				printf("Результат: %.8g\n", pop());
				break;
			default:
				printf("error: Unknow command %s\n", s);
				break;
		}
	}
	return 0;
}
