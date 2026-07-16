#include <stdio.h>

void escape(char s[], char t[]) {
	int i, j;

	j = 0;
	for (i = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
			case '\n':
				s[j++] = '\\';
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
		}
	}
	s[j] = '\0';
}

void reverse_escape(char s[], char t[]) {
	int i, j;

	j = 0;
	for (i = 0; t[i] != '\0'; i++) {
		switch (t[i]) {
			case '\\':
				switch (t[i+1]) {
					case 'n':
						s[j++] = '\n';
						i++;
						break;
					case 't':
						s[j++] = '\t';
						i++;
						break;
					default:
						s[j++] = t[i];
						break;
				}
				
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}
	s[j] = '\0';
}
