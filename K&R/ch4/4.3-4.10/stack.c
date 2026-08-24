#include "stack.h"
#include <math.h>
#include <stdio.h>

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL) {
    val[sp++] = f;
  } else {
    // printf("error: Stack is full\n");
  }
}

double pop(void) {
  if (sp > 0) {
    return val[--sp];
  } else {
    printf("error: Stack is empty\n");
    return 0.0;
  }
}

double gettop(void) {
  if (sp > 0) {
    return val[sp - 1];
  } else {
    printf("error: Stack is empty\n");
    return NAN;
  }
}

void duplicatetop(void) {
  double top;
  if (!isnan(top = gettop())) {
    val[sp++] = top;
  }
}

void clearstack(void) { sp = 0; }

void swaptoptwoelemenets(void) {
  int first, second;
  double temp;

  if (sp >= 2) {
    first = sp - 1;
    second = sp - 2;

    temp = val[first];
    val[first] = val[second];
    val[second] = temp;
    return;
  } else {
    printf("error: Stacks length is less than 2\n");
  }
}
