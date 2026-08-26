#include "getop.h"
#include "getch.h"
#include <ctype.h>
#include <stdio.h>

char line[MAXLINE];
char *li = line;

int _get_newline_if_end(void) {
  if (*li == '\0' || *li == '\n') {
    if (*li == '\n') {
      return *li;
    }
    if ((mygetline(line, MAXLINE)) == 0) {
      return EOF;
    }
    li = line;
  }
  return 0;
}

int strip_returning_first_found_symbol() {
  while (*li == ' ' || *li == '\t') {
    li++;
  }
  return *li++;
}

int getop(char *s) {
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
  if (c == '-' && !isdigit(*li)) { // проверка, что не негативное число
    return c;
  }

  i = 0;

  while (isdigit((c = *li))) { // запись числа в строку
    *(++s) = c;
    li++;
  }

  if (c == '.') {
    *(++s) = c;
    while (isdigit((c = *(++li)))) {
      *(++s) = c;
    }
  }

  *(++s) = '\0';
  return NUMBER;
}
