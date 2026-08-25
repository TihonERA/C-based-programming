int len(char *s) {
  char *p = s;

  while (*s != '\0')
    s++;
  return s - p;
}

void mystrcat(char *s, char *t) {
  char *starting_pointer = s + (len(s) - len(t));

  while ((*starting_pointer++ = *t++))
    ;
}
