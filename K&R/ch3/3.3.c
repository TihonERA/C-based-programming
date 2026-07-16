#include <stdio.h>

void expand(char s1[], char s2[]) {
	int i, j;
	char start = s1[0];
	char stop;
	for (i = 0; s1[i] != '\0'; i++) {
		;
	}
	stop = s1[i-1];
	for (i = start, j = 0; start <= stop; i++, j++, start++) {
		s2[j] = i;
	}
	s2[j] = '\0';
}

int main() {
	char string1[4] = " -~";
	char string2[128];

	expand(string1, string2);
	printf("%s\n", string2);
}
