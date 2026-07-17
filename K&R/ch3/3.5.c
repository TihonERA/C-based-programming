#include <stdio.h>

void reverse(char s[]) {
	int i, j;

	j = 0;
	while (s[j] != '\0') {
		j++;
	}
	j--;

	for (i = 0, j; i < j; i++, j--) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void itob(int n, char s[], int b) {
	int i;
	char symbols[17] = "0123456789abcdef";

	if (n < 0) {
		s[0] = '-';
	}
	unsigned int n_copy = n;
	i = 0;
	do {
		s[i++] = symbols[n_copy % b];
	} while ((n_copy /= b) > 0);

	s[i] = '\0';
	reverse(s);
}

int main() {
	char string[100];

	itob(1234359534, string, 8);
	printf("%s\n", string);
}
