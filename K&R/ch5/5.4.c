int len(char *s) {
  char *p = s;

  while (*s != '\0') {
    s++;
  }
  return s - p;
}

int strend(char *s, char *t) {
  int lens = len(s), lent = len(t);

  if (lent > lens) {
    return 0;
  }
  char *startingPointer = s + (lens - lent);

  while (startingPointer < s + lens) {
    if (*startingPointer++ != *t++) {
      return 0;
    }
  }
  return 1;
}
