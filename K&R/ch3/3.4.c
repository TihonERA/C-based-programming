#include <string.h>

void reverse(char *s) {
  if (*s == '-') {
    s++;
  }

  char *j = &s[strlen(s) - 1];

  while (s < j) {
    int temp = *s;
    *s++ = *j;
    *j-- = temp;
  }
}

char *itoa(int n, char *s) {
  char *start = s;

  if (n < 0) {
    *s++ = '-';
    n = -n;
  }
  do {
    *s++ = n % 10 + '0';
  } while ((n /= 10) > 0);
  *s = '\0';
  reverse(start);

  return start;
}
