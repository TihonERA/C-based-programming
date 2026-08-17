#include "mymath.h"
#include <math.h>

double mysin(double degree) {
	degree = degree * (M_PI / 180);
	degree = fmod(degree, 2 * M_PI);

	double term = degree;
	double sum = degree;

	for (int i = 2; i < 14; i += 2) {
		term = term * (-(degree * degree) / (i * (i + 1)));
		sum += term;
	}
		
	return sum;
}

double exp(double n) {
	double term, sum = 1;

	for (int i = 1; i < 10; i++) {
		term = term * n / i;
		sum += term;
	}

	return sum;
}

double ln(double x) {
	double base = (x - 1) / (x + 1);
	double sum = base;
	double term = base;
	double current_slice;

	for (int n = 1; n < 10; n++) {
		double base_sq = base * base;

		term = term * base_sq;

		current_slice = term / (2.0 * n + 1);

		sum += current_slice;
	}
	return 2 * sum;
}

double pow(double x, double y) {
	return exp(y * ln(x));
}
