#include <ctype.h>
#include <stdio.h>

#define BUFP_LEN 255

char buf[BUFP_LEN];
int bufp = 0;

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }

void ungetch(int c) {
  if (bufp >= BUFP_LEN) {
    printf("Error: too many chars in buff\n");
  } else {
    buf[bufp++] = c;
  }
}

int getfloat(double *pn) {
  double fl_part = 0;
  int c, sign;

  while (isspace(c = getch()))
    ;
  if (c == EOF) {
    return c;
  }
  if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if (c == '+' || c == '-') {
    c = getch();
    if (!isdigit(c)) {
      ungetch(c);
      return 0;
    }
  }
  for (*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');

  if (c == '.') {
    c = getch();

    for (fl_part = 0; isdigit(c); c = getch()) {
      fl_part = 10 * fl_part + (c - '0');
    }
    while (fl_part > 1) {
      fl_part /= 10;
    }
  }
  *pn += fl_part;
  *pn *= sign;
  if (c != EOF) {
    ungetch(c);
  }
  return 1;
}

int main() {
  int n, boolean;
  double array[100] = {0};

  for (n = 0; n < 100 && (boolean = getfloat(&array[n])) != EOF; n++) {
    printf("%d\n", boolean);
    for (int i = 0; i < 100; i++) {
      printf("%f ", array[i]);
    }
    putchar(10);
  }
}
