#include <stdio.h>

unsigned rightrot(unsigned x, int n) {
	int i;
	unsigned n_bits = ~(~0 << n) & x;
	x = x >> n;
	n_bits = n_bits << (32-n);
	x = x | n_bits;
	return x;
}
