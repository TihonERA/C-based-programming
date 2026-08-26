#include "getch.h"
#include <stdio.h>
#include <string.h>

int otsym = -999999;
int bufp = 0;

int mygetline(char *s, int lim) {
  char *start = s;
  int c;

  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    *s++ = c;
  }
  if (c == '\n') {
    *s++ = c;
  }
  *s = '\0';
  return s - start;
}

int getch(void) { return (bufp) ? otsym : getchar(); }

void ungetch(int c) {
  if (bufp) {
    otsym = c;
  }
}

void ungets(char *s) {
  for (int i = strlen(s) - 1; i >= 0; i--) {
    ungetch(i);
  }
}
