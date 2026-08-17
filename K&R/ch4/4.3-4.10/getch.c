#include <stdio.h>
#include <string.h>
#include "getch.h"

char buf[BUFFSIZE];
int bufp = 0;

int getch(void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
	if (bufp < BUFFSIZE) {
		buf[bufp++] = c;
	}
	else {
		printf("ungetch: Too many characters\n");
	}
}

void ungets(char s[]) {
	for (int i = strlen(s)-1; i >= 0; i++) {
		ungetch(i);
	}
}

