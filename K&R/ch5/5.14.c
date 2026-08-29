#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLINES 5000
char *lineptr[MAXLINES];

#define MAXBUF 500000
char buf[MAXBUF];
char *bufp = buf;

int mygetline(char *, int);
int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

typedef int (*cmp_name)(void *, void *);
void mqsort(void *lineptr[], int left, int right, cmp_name comp, int reverse);
void swap(void *[], int, int);

int numcmp(const char *, const char *);

int main(int argc, char *argv[]) {
  int nlines, numeric = 0, reverse = 0;
  char *c;

  while (--argc > 0 && (*++argv)[0] == '-') {
    for (c = ++argv[0]; *c != '\0'; c++) {
      switch (*c) {
      case 'n':
        numeric = 1;
        break;
      case 'r':
        reverse = 1;
        break;
      }
    }
  }
  if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
    mqsort((void **)lineptr, 0, nlines - 1,
           (cmp_name)(numeric ? numcmp : strcmp), reverse);
    writelines(lineptr, nlines);
    return 0;
  }
  printf("Input is too long\n");
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
    printf("%s", *lptr++);
  }
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

void mqsort(void *v[], int left, int right, cmp_name comp, int reverse) {
  int i, last, swap_condition;

  if (left >= right) {
    return;
  }
  swap(v, left, ((left + right) / 2));

  last = left;
  for (i = left + 1; i <= right; i++) {
    swap_condition = (*comp)(v[i], v[left]) < 0;
    if ((reverse) ? !swap_condition : swap_condition) {
      swap(v, ++last, i);
    }
  }
  swap(v, left, last);
  mqsort(v, left, last - 1, comp, reverse);
  mqsort(v, last + 1, right, comp, reverse);
}

void swap(void *s[], int i, int j) {
  char *temp;

  temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

int numcmp(const char *s1, const char *s2) {
  double v1, v2;

  v1 = atof(s1);
  v2 = atof(s2);
  if (v1 < v2)
    return -1;
  if (v1 > v2)
    return 1;
  return 0;
}
