void itoa(char s[], int n) {
  static int len = 0;

  if (n < 0) {
    s[len++] = '-';
    n = -n;
  }
  if (n / 10) {
    itoa(s, n / 10);
  }
  s[len++] = n % 10 + '0';
}
