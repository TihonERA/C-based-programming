int len(char *s) {
  char *p = s;

  while (*s != '\0')
    s++;

  return p - s;
}

void strncopy(char *s, char *t, int n) {
  char *y = t;
  while ((y - t) < n && (*s++ = *y++)) {
    ;
  }
}

void mystrcat(char *s, char *t, int n) {
  int lenS = len(s), lenT = len(t) - n;
  t[lenT] = '\0';

  char *starting_pointer = s + (lenS - lenT);

  while ((*starting_pointer++ = *t++))
    ;
}

int mystrcmp(char *s, char *t, int n) {
  char *y = t;

  for (; (y - t) < n && *s == *t; s++, t++) {
    if (*s == '\0') {
      return 0;
    }
  }
  return *s - *y;
}
