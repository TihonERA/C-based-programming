#include <stdio.h>
#include <stdlib.h>

#define MAXLINES 1000
#define MAXLEN 1000000

int mgetline(char **);

int main(int argc, char *argv[]) {
  char line[MAXLEN], *lp = line;
  char *lines[MAXLINES];
  int len, i = 0, count_of_lines_to_display = 10, start_index;

  while (--argc > 0 && (*++argv)[0] == '-') {
    count_of_lines_to_display = atoi(*argv + 1);
  }

  for (len = 0; mgetline(&lp) > 1; len++) {
    lines[len] = lp;
  }

  if ((len - 1) > count_of_lines_to_display) {
    start_index = len - 1 - count_of_lines_to_display;
  } else {
    start_index = 0;
  }

  while (start_index != len - 1) {
    printf("%s", lines[start_index++]);
  }
}

int mgetline(char **line) {
  char *end, *start = *line, *lp = *line;
  int c;

  while ((c = getchar()) != EOF && c != '\n') {
    *lp++ = c;
  }
  if (c == '\n') {
    *lp++ = c;
  }
  *lp = '\0';
  end = lp;

  *line = lp + 1;

  return end - start;
}
