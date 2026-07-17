#include <stdio.h>

void reverse(char s[]) {
	int i, j;

	j = 0;
	while (s[j] != '\0') {
		j++;
	}
	j--;

	for (i = 0, j; i < j; i++, j--) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void itoa(int n, char s[], int l) {
	int i; 
	unsigned int n_copy = n;

	if (n > 0) {
		s[0] = '-';
	}

	i = 0; 
	do {
		s[i++] = n_copy % 10 + '0';
	} while ((n_copy /= 10) > 0);
	s[i] = '\0';

	reverse(s);

	while (i < l) {
		s[i++] = '0';
	}
	s[i] = '\0';
}
