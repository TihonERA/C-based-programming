#include <float.h>
#include <limits.h>
#include <stdio.h>

int htoi(char *hex) {
  int result, hex_current_multiplayer, hex_number;
  int i = 0;

  if (*hex != '0' && (*(hex + 1) != 'x' || *(hex + 1) != 'X'))
    return 0;
  char *start_of_hex = hex + 1;
  hex = hex + 2;

  while (*hex != '\0')
    hex++;

  hex--;

  result = 0;
  hex_current_multiplayer = 1;
  for (; (*hex != *start_of_hex); hex--) {
    if (*hex >= '0' && *hex <= '9') {
      hex_number = *hex - '0';
      result = result + (hex_number * hex_current_multiplayer);
    } else if (*hex >= 'A' && *hex <= 'F') {
      hex_number = *hex - 'A' + 10;
      result = result + (hex_number * hex_current_multiplayer);
    } else if (*hex >= 'a' && *hex <= 'f') {
      hex_number = *hex - 'a' + 10;
      result = result + (hex_number * hex_current_multiplayer);
    } else {
      return 0;
    }
    hex_current_multiplayer = hex_current_multiplayer * 16;
  }

  return result;
}

int main() { printf("%d\n", htoi("0xA10")); }
