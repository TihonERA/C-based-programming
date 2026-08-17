#include "mymath.h"
#include <stdio.h>

double mysin(double radian) {
	double term = radian;
	double sum = radian;

	for (int i = 2; i < 30; i += 2) {
		term = term * (-(radian * radian) / (i * (i + 1)));
		sum += term;
	}
		
	return sum;
}

double myexp(double n) {
	double term = 1, sum = 1;

	for (int i = 1; i < 30; i++) {
		term = term * n / i;
		sum += term;
	}

	return sum;
}

double myln(double x) {
	double base = (x - 1) / (x + 1);
	double sum = base;
	double term = base;
	double current_slice;

	for (int n = 1; n < 50; n++) {
		double base_sq = base * base;

		term = term * base_sq;

		current_slice = term / (2.0 * n + 1);

		sum += current_slice;
	}
	printf("%g\n", 2*sum);
	return 2 * sum;
}

double mypow(double x, double y) {
	return myexp(y * myln(x));
}
