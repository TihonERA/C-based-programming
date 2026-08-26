#include <stdio.h>
#include <string.h>
void reverse(char *s) {
  char temp, *j = &s[strlen(s) - 1];

  while (s < j) {
    temp = *s;
    *s++ = *j;
    *j-- = temp;
  }
}

char *itoa(int n, char *s, int l) {
  int i, sign;
  unsigned int num;
  char *start = s;

  if ((sign = n < 0)) {
    num = -n;
  } else {
    num = n;
  }

  do {
    *s++ = num % 10 + '0';
  } while ((num /= 10) > 0);

  if (sign) {
    *s++ = '-';
  }

  reverse(start);

  while ((s - start) < l) {
    *s++ = '0';
  }
  *s = '\0';

  return start;
}
