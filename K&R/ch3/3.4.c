#include <stdio.h>

void reverse(char s[]) {
	int i = 0, j = 0;
	if (s[i] == '-') {
		i++;
	}

	while (s[j] != '\0') {
		j++;
	}
	j--;

	for (i, j; i < j; i++, j--) {
		int temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void itoa(int n, char s[]) {
	if (n < 0) {
		s[0] = '-';
	}

	unsigned int n_copy = n;
	int i = 0;
	do {
		s[i++] = n_copy % 10 + '0';
	} while ((n_copy /= 10) > 0);
	s[i] = '\0';
	reverse(s);
}
