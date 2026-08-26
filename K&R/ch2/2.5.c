int any(char s1[], char s2[]) {
  for (char *i = s1; *i != '\0'; i++) {
    for (char *k = s2; *k != '\0'; k++) {
      if (*i == *k) {
        return i - s1;
      }
    }
  }
  return -1;
}
