#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define NUMBER 1
#define MAX_OP 100

int getop(int, char *);
void push(double);
double pop(void);

int main(int argc, char *argv[]) {
  double op1, op2;
  int c;
  while ((c = getop(--argc, *++argv)) != EOF) {
    switch (c) {
    case NUMBER:
      push(atof(*argv));
      break;
    case '+':
      op2 = pop();
      op1 = pop();
      push(op1 + op2);
      printf("%g\n", op1 + op2);
      break;
    case '-':
      op2 = pop();
      op1 = pop();
      push(op1 - op2);
      break;
    case '*':
      op2 = pop();
      op1 = pop();
      push(op1 * op2);
      break;
    case '/':
      op2 = pop();
      op1 = pop();
      push(op1 / op2);
      break;
    default:
      printf("%s\n", *argv);
      printf("error: Unknow command\n");
      break;
    }
  }
  printf("%g\n", pop());
}

int getop(int len, char *lines) {
  if (len <= 0) {
    return EOF;
  }
  if (!isdigit(*lines)) {
    return *lines;
  }

  return NUMBER;
}

#define MAX_STACK 200

double stack[MAX_STACK];
double *sp = stack;

void push(double n) {
  (((stack + MAX_STACK) - sp) > 0) ? *sp++ = n
                                   : printf("error: Stack if full\n");
}

double pop(void) {
  if (sp != stack) {
    return *--sp;
  }
  printf("error: Stack is empty\n");
  return 0.0;
}
