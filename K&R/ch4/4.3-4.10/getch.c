#include <stdio.h>
#include <string.h>
#include "getch.h"

int otsym = -999999;
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

