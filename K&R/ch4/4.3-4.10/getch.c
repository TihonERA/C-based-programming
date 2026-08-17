#include <stdio.h>
#include <string.h>
#include "getch.h"

char otsym = '\0';
int bufp = 0;

int getch(void) {
	return (bufp) ? otsym : getchar();
}

void ungetch(int c) {
	if (bufp) {
		otsym = c;
	}
}

void ungets(char s[]) {
	for (int i = strlen(s)-1; i >= 0; i++) {
		ungetch(i);
	}
}

