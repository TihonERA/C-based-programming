void escape(char *s, char *t) {
  for (; *t != '\0'; t++) {
    switch (*t) {
    case '\n':
      *s++ = '\\';
      *s++ = 'n';
      break;
    case '\t':
      *s++ = '\\';
      *s++ = 't';
      break;
    default:
      *s++ = *t;
    }
  }
  *s = '\0';
}

void reverse_escape(char *s, char *t) {
  for (; *t != '\0'; t++) {
    switch (*t) {
    case '\\':
      switch (t[1]) {
      case 'n':
        *s++ = '\n';
        t++;
        break;
      case 't':
        *s++ = '\t';
        t++;
        break;
      default:
        *s++ = *t;
        break;
      }

      break;
    default:
      *s++ = *t;
      break;
    }
  }
  *s = '\0';
}
