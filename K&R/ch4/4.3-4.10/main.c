#include "getop.h"
#include "stack.h"
#include "mymath.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

double variables[26] = {NAN};
char last_var;

int main() {
	int type, index;
	double op1, op2, num;
	char s[MAXOP];

	int print_result = 1;
	while ((type = getop(s)) != EOF) {
		switch (type) {
			case NUMBER:
				num = atof(s);
				push(num);
				break;
			case VARIABLE:
				last_var = s[0] - 'a';
				push(variables[last_var]);
				break;
			case '=':
				pop();
				variables[last_var] = pop();
				print_result = 0;
				printf("Сохранил в переменную %c значение %.8g\n", last_var + 'a', variables[last_var]);
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
			case 'S':
				push(mysin(pop()));
				break;
			case 'E':
				push(myexp(pop()));
				break;
			case 'P':
				op2 = pop();
				op1 = pop();
				push(mypow(op1, op2));
				break;
			case '\n':
				if (!print_result) {
					print_result = 1;
					break;
				}
				printf("Результат: %.8g\n", pop());
				break;
			default:
				printf("error: Unknow command %s\n", s);
				break;
		}
	}
	return 0;
}
