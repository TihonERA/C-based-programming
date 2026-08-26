#include <string.h>

void expand(char s1[], char s2[]) {
  char end_char = s1[strlen(s1) - 1];
  for (char c = *s1; c <= end_char; c++) {
    *s2++ = c;
  }
  *s2 = '\0';
}
