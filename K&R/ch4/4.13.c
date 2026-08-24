#include <stdio.h>
#include <string.h>
void reverse(char s[], int start, int end) {
  char temp;
  if (start > end) {
    return;
  }
  temp = s[start];
  s[start] = s[end];
  s[end] = temp;
  reverse(s, start + 1, end - 1);
}

int main() {
  char s[] = "pidorok gufich nihuya ne uchitsa";
  reverse(s, 0, strlen(s) - 1);
  printf("%s\n", s);
}
