#include <ctype.h>
#include <stdio.h>

double atof(char *s) {
  double val, power, exp, result;
  int sign;

  while (isspace(*s))
    s++;

  sign = (*s == '-') ? -1 : 1;

  if (*s == '+' || *s == '-') {
    s++;
  }
  for (val = 0.0; isdigit(*s); s++) {
    val = 10.0 * val + (*s - '0');
  }
  if (*s == '.') {
    s++;
  }
  for (power = 1.0; isdigit(*s); s++) {
    val = 10.0 * val + (*s - '0');
    power *= 10;
  }
  result = sign * val / power;
  if (!(*s == 'e' || *s == 'E'))
    return result;
  s++;

  int exp_direction = (!isdigit(*s) && *s == '-') ? -1 : 1;
  if (!exp_direction)
    s++;

  for (exp = 0.0; isdigit(*s); s++) {
    exp = exp * 10.0 + (*s - '0');
  }
  if (exp_direction) {
    for (; exp > 0.0; exp--) {
      result *= 10.0;
    }
  } else {
    for (; exp > 0.0; exp--) {
      result /= 10.0;
    }
  }
  return result;
}

int main() { printf("%g\n", atof("50.104234")); }
