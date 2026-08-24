#include "getch.h"
#include <stdio.h>
#include <string.h>

int otsym = -999999;
int bufp = 0;

int mygetline(char s[], int lim) {
  int i, c;

  i = 0;
  while (--lim > 0 && (c = getchar()) != EOF && c != '\n') {
    s[i++] = c;
  }
  if (c == '\n') {
    s[i++] = c;
  }
  s[i] = '\0';
  return i;
}

int getch(void) { return (bufp) ? otsym : getchar(); }

void ungetch(int c) {
  if (bufp) {
    otsym = c;
  }
}

void ungets(char s[]) {
  for (int i = strlen(s) - 1; i >= 0; i++) {
    ungetch(i);
  }
}
