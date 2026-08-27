#include <endian.h>
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define MAXBUF 5000000

char *lineptr[MAXLINES];
char buf[MAXBUF];
char *bufp = buf;

void swap(char **, int, int);
void quicksort(char **, int, int);
int readlines(char **, int);
void writelines(char **, int);
int mygetline(char *, int);

int main() {
  int nlines;

  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    quicksort(lineptr, 0, nlines - 1);
    writelines(lineptr, nlines);
    return 0;
  }
  return 1;
}

int readlines(char **lineptr, int maxlines) {
  int len, nlines;

  nlines = 0;
  while ((len = mygetline(bufp, (buf + MAXBUF) - bufp)) > 0) {
    if (nlines >= maxlines) {
      return -1;
    }

    lineptr[nlines++] = bufp;

    bufp += len + 1;
  }
  return nlines;
}

void writelines(char **lptr, int nlines) {
  while (nlines-- > 0) {
    printf("%s\n", *lptr++);
  }
}

void quicksort(char **s, int left, int right) {
  int i, last;

  if (left >= right) {
    return;
  }
  swap(s, left, ((left + right) / 2));

  last = left;
  for (i = left + 1; i <= right; i++) {
    if (strcmp(s[i], s[left]) < 0) {
      swap(s, ++last, i);
    }
  }
  swap(s, left, last);
  quicksort(s, left, last - 1);
  quicksort(s, last + 1, right);
}

void swap(char **s, int i, int j) {
  char *temp;

  temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

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
