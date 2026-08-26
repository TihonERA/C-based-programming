#include <string.h>

int strrindex(char *s, char *t) {
  int start;
  char *sstart = s;
  char *j, *k;

  start = -1;
  for (; *s != '\0'; s++) {
    for (j = s, k = t; *k != '\0' && *j == *k; j++, k++) {
      ;
    }
    if ((k - t) > 0 && *k == '\0') {
      start = (j - sstart) - (strlen(t));
    }
  }
  return start;
}
