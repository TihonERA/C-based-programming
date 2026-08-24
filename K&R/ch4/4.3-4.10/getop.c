#include "getop.h"
#include "getch.h"
#include <ctype.h>
#include <stdio.h>

char line[MAXLINE];
int li = 0;

int _get_newline_if_end(void) {
  if (line[li] == '\0' || line[li] == '\n') {
    if (line[li] == '\n') {
      return line[li];
    }
    if ((mygetline(line, MAXLINE)) == 0) {
      return EOF;
    }
    li = 0;
  }
  return 0;
}

int strip_returning_first_found_symbol() {
  while (line[li] == ' ' || line[li] == '\t') {
    li++;
  }
  return line[li++];
}

int getop(char s[]) {
  int i, c;

  _get_newline_if_end();

  c = strip_returning_first_found_symbol();

  s[0] = c;
  s[1] = '\0';

  if (!isdigit(c) && c != '.' && c != '-') {
    if (islower(c)) {
      li++;
      return VARIABLE;
    }
    return c;
  }
  if (c == '-' && !isdigit(line[li])) { // проверка, что не негативное число
    return c;
  }

  i = 0;

  while (isdigit((c = line[li]))) { // запись числа в строку
    s[++i] = c;
    li++;
  }

  if (c == '.') {
    s[++i] = c;
    while (isdigit((c = line[++li]))) {
      s[++i] = c;
    }
  }

  s[++i] = '\0';
  return NUMBER;
}
