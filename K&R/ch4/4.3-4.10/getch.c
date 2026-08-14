#include <stdio.h>
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
