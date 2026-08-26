void alt_squeeze(char *a1, char *a2) {
  char *save_symbols_pointer = a1;
  char *searching_pointer;

  for (; *a1 != '\0'; a1++) {
    for (searching_pointer = a2;
         *searching_pointer != '\0' && *searching_pointer != *a1;
         searching_pointer++)
      ;

    if (*searching_pointer == '\0') {
      *save_symbols_pointer++ = *a1;
    }
  }

  *save_symbols_pointer = '\0';
}
