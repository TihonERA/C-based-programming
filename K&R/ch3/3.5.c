#include <string.h>

void reverse(char s[]) {
  char *j = &s[strlen(s) - 1];

  while (s < j) {
    int temp = *s;
    *s++ = *j;
    *j-- = temp;
  }
}

char *itob(int n, char *s, int b) {
  char *start = s;
  unsigned int num;

  if (n < 0) {
    num = -n;
  } else {
    num = n;
  }
  do {
    int digit = num % b;
    *s++ = (digit < 10) ? (digit + '0') : (digit - 10 + 'a');
  } while ((num /= b) > 0);
  if (n < 0) {
    *s++ = '-';
  }

  *s = '\0';
  reverse(start);

  return start;
}
