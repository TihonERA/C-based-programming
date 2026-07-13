#include <stdio.h>

#define BIG_REGISTER_MIN 65 
#define BIG_REGISTER_MAX 90

int lower(char c) {
	return ((c >= BIG_REGISTER_MIN) && (c <= BIG_REGISTER_MAX)) ? c + ('a' - 'A') : c;
}
