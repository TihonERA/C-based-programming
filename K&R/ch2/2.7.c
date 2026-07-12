#include <stdio.h>

unsigned invert(unsigned x, int p, int n) {
    unsigned x_original_copy = x;
    unsigned x_copy = ~(~(~0 << n) << (p+1-n));
    x = x & x_copy;
    x_copy = ~(x_copy | x_original_copy);
    x = x | x_copy;
    return x;
}

/* Лучшее решение
unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0U << n) << (p + 1 - n));
}
*/
