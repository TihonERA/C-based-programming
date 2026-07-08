#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
	unsigned x_mask = ~(~((~0 << n) << (p+1-n)));
	x = x & x_mask;

	unsigned y_mask = (~(~0 << n));
	y_mask = (y & y_mask) << (p+1-n);

	x = x | y_mask;
	return x;
}

