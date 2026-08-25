#include <stdio.h>
#include <stdlib.h>

void printarray(int *a, int size) {
  for (int i = 0; i < size; i++) {
    printf("%d", *(a + i));
  }
  putchar(10);
}

int main() {
  int *array = malloc(10 * sizeof(int));

  for (int i = 0; i < 10; i++) {
    *(array + i) = i;
  }
  printarray(array, 10);
  int *pointer = array + 3;

  *(pointer + 1) = 0;
  printarray(array, 10);

  free(array);
}
