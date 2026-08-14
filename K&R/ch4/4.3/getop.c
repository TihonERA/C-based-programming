#include "getop.h"
#include "getch.h"
#include <ctype.h>

int getop(char s[]) {
	int i, c, has_dot;

	while ((s[0] = c = getch()) == ' ' || c == '\t') 
		;

	s[1] = '\0';

	if (!isdigit(c) && c != '.' && c != '-') {
		return c;
	}
	i = 0;

	has_dot = 0;	
	if (c == '-') {
		char next_char = getch();
		if (isdigit(next_char) || next_char == '.') {
			has_dot = next_char == '.';
			s[++i] = next_char;
			c = next_char;
		}
		else {
			ungetch(next_char);
		 	return '-';
		}
	}
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch()))
			;
	}
	if (c == '.' && !has_dot)
		while(isdigit(s[++i] = c = getch()))
			;
	return NUMBER;
}
